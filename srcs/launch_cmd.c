#include "../includes/minishell.h"

int     launch(shell_t *shell, char *path_exec)
{
    pid_t   pid;

    pid = fork();
    if (pid == 0)
    {
        // Child process
        //if (execve(args[0], args, ) == -1)
        if (execve(path_exec, shell->cmd_exec_parsed, shell->env) == -1)
        {
            ft_putstr_fd("zsh: command not found: ", 2);
            ft_putendl_fd(path_exec, 2);
        }
        exit(1);
    }
    else if (pid < 0)
    {
        ft_putendl_fd("zsh: fork failed.", 2);
        return (0);
    }
    wait(&pid);
    return (1);
}