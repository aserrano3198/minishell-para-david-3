#include "../includes/minishell.h"

int     lsh_cd(char **args)
{
    //Este if se cambiará para que si se hace "cd" sin nada, vaya al home del usuario
    if (args[1] == NULL)
        write (2, "cd: expected argument to \"cd\"\n", 31);
    else if (chdir(args[1]) != 0)
        perror("cd");
    return (1);
}

int     launch(char **args)
{
    pid_t   pid;
    pid_t   wpid;
    int     status;

    pid = fork();
    if (pid == 0)
    {
        // Child process
        //if (execve(args[0], args, ) == -1)
        if (execvp(args[0], args) == -1)
        {
            ft_putstr_fd("zsh: command not found: ", 2);
            ft_putendl_fd(args[0],2 );
        }
        exit(1);
    }
    else if (pid < 0)
    {
        ft_putstr_fd("zsh: command not found: ", 2);
        ft_putendl_fd(args[0],2 );
    }
    else
    {
        // Parent process
        wpid = waitpid(pid, &status, WUNTRACED);
        while (!WIFEXITED(status) && !WIFSIGNALED(status))
            wpid = waitpid(pid, &status, WUNTRACED);
    }
    return (1);
}

int     lsh_exit()
{
    return (0);
}

int     exec_command(char **command_splited)
{
    int   i;

    if (command_splited[0] == NULL)
        return (1);
    i = -1;
    while (++i < 2)
        if (ft_strncmp(command_splited[0], builtin_str[i], ft_strlen(builtin_str[i])) == 0)
            return (*builtin_func[i])(command_splited);
    return (launch(command_splited));
}

void    free_command(char **command)
{
    while (*command)
        free(*command++);
    //free(command);
}

int     parse_commands(char **command)
{
    int     i;
    char    *command_execute;
    char    **command_execute_parsed;

    i = -1;
    while (command[++i])
    {
        command_execute = ft_strtrim(command[i], " ");
        free(command[i]);
        command_execute_parsed = ft_split(command_execute, ' ');
        free(command_execute);
        if (!(exec_command(command_execute_parsed)))
            return (0);
        free_command(command_execute_parsed);
    }
    return (1);
}

int     main(void)
{
    char    *line;
    char    **commands;
    int     status;

    status = 1;
    while (status)
    {
        ft_printf("minishell> ");
        get_next_line(0, &line);
        commands = ft_split(line, ';');
        free(line);
        status = parse_commands(commands);
        free(commands);
    }
    return (0);
}