#include "../includes/minishell.h"

static void    free_command(char **command)
{
    int     i;

    i = 0;
    while (command[i])
        free(command[i++]);
    (command) ? free(command) : 0;
}

int             get_status_var(char *var)
{
    int     i;
    int     len;

    i = 0;
    len = ft_strlenchr(var, '$');
    if (var[len] == '$' && var[len + 1] == '?')
        return (3);
    else if (var[0] == '$' && var[1] != '\0')
        return (2);
    else if (var[len] == '$' && var[len + 1] == '\0')
        return (0);
    else
        return (1);
}

size_t          ft_arraylen(char **array)
{
    int     i;

    i = 0;
    while (array[i])
        i++;
    return (i);
}

char            **ft_arraydelone(char **array, char *to_delete)
{
    size_t      len_array;
    size_t      len_delete;
    char        **new_array;
    int         i;
    int         j;

    len_delete = ft_strlen(to_delete);
    len_array = ft_arraylen(array);
    if (!(new_array = (char**)malloc(sizeof(char*) * (len_array))))
        return (NULL);
    i = -1;
    j = 0;
    while (array[++i])
        if (ft_strncmp(array[i], to_delete, len_delete) != 0)
            new_array[j++] = array[i];
    new_array[j] = NULL;
    free(array);
    free(to_delete);
    return (new_array);
}


void            update_command(shell_t *shell, char **cmnd_to_upd, int status)
{
    char        *prefix;
    int         len_delim;
    char        *env_var;
    char        *tmp;

    env_var = ft_strtrim(ft_strchr(*cmnd_to_upd, '$'), "$");
    if (status == 1)
    {
        len_delim = ft_strlenchr(*cmnd_to_upd, '$');
        prefix = ft_substr(*cmnd_to_upd, 0, len_delim);
        if (find_env_var(shell, env_var) == 1)
        {
            free(*cmnd_to_upd);
            tmp = get_env_var(shell, env_var, "=");
            *cmnd_to_upd = ft_strjoin(prefix, tmp);
            free(tmp);
        }
        else
        {
            free(*cmnd_to_upd);
            *cmnd_to_upd = ft_strdup(prefix);
        }
        free(prefix);
    }
    else if (status == 2)
    {
        if (find_env_var(shell, env_var) == 1)
        {
            free(*cmnd_to_upd);
            *cmnd_to_upd = get_env_var(shell, env_var, "=");
        }
        else
            shell->cmd_exec_parsed = ft_arraydelone(shell->cmd_exec_parsed, ft_strdup(*cmnd_to_upd));
    }
    else if (status == 3)
    {
        if (shell->status_last_command == 1)
            tmp = ft_strdup("0");
        else
            tmp = ft_strdup("127");
        *cmnd_to_upd = ft_replacestr(ft_strdup(*cmnd_to_upd), "$?", tmp);
        free(tmp);
    }
    free(env_var);
}

void            parse_env_vars(shell_t *shell)
{
    int     i;
    int     status;

    i = -1;
    while (shell->cmd_exec_parsed[++i])
    {
        if (ft_strchr(shell->cmd_exec_parsed[i], '$'))
        {
            status = get_status_var(shell->cmd_exec_parsed[i]);
            if (status != 0)
                update_command(shell, &shell->cmd_exec_parsed[i], status);
        }
    }
}

void            ft_pipe(shell_t *shell, char *command_execute)
{
    char **pipetab;
    pid_t   pid1;
    pid_t   pid2;
    int in;
    int out;

    in = dup(STDIN_FILENO);
    out = dup(STDOUT_FILENO);
    pipe(shell->fd);
    pipetab = ft_split(command_execute, '|');
    pid1 = fork();
    if (pid1 == 0)
    {
        close(shell->fd[0]);
        dup2(shell->fd[1], STDOUT_FILENO);
        close(shell->fd[1]);
        shell->cmd_exec_parsed = ft_split(pipetab[0], ' ');
        free(pipetab[0]);
        parse_env_vars(shell);
        shell->status_last_command = exec_command(shell);
        free_command(shell->cmd_exec_parsed);
        close(shell->fd[0]);
        exit(EXIT_SUCCESS);
    }
    else
    {
        pid2 = fork();
        if (pid2 == 0)
        {
            close(shell->fd[1]);
            dup2(shell->fd[0], STDIN_FILENO);
            close(shell->fd[0]);
            shell->cmd_exec_parsed = ft_split(pipetab[1], ' ');
            free(pipetab[1]);
            parse_env_vars(shell);
            shell->status_last_command = exec_command(shell);
            free_command(shell->cmd_exec_parsed);
            exit(EXIT_SUCCESS);
        } 
        else
        {
            close(shell->fd[1]);
            wait(NULL);
            wait(NULL);
            dup2(in, STDIN_FILENO);
            dup2(out, STDOUT_FILENO);
        } 
    }
}

int             parse_commands(shell_t *shell)
{
    int     i;
    char    *command_execute;

    i = -1;
    while (shell->commands[++i])
    {
        
        command_execute = ft_strtrim(shell->commands[i], " ");
        if (ft_strnstr(shell->commands[i], " | ", ft_strlen(shell->commands[i])))
        {
            ft_pipe(shell, command_execute);
            continue ;
        }
        free(shell->commands[i]);
        shell->cmd_exec_parsed = ft_split(command_execute, ' ');
        free(command_execute);
        parse_env_vars(shell);
        shell->status_last_command = exec_command(shell);
        free_command(shell->cmd_exec_parsed);
    }
    return (1);
}
