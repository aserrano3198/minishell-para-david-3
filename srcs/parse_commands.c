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
    if (var[0] == '$' && var[1] != '\0')
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

int             parse_commands(shell_t *shell)
{
    int     i;
    char    *command_execute;

    i = -1;
    while (shell->commands[++i])
    {
        command_execute = ft_strtrim(shell->commands[i], " ");
        free(shell->commands[i]);
        shell->cmd_exec_parsed = ft_split(command_execute, ' ');
        free(command_execute);
        parse_env_vars(shell);
        if (!(exec_command(shell)))
            return (0);
        free_command(shell->cmd_exec_parsed);
    }
    return (1);
}
