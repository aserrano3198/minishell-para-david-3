#include "../includes/minishell.h"

int     launch(shell_t *shell)
{
    pid_t   pid;
    int     status;

    pid = fork();
    if (pid == 0)
    {
        // Child process
        //if (execve(args[0], args, ) == -1)
        if (execvp(shell->cmd_exec_parsed[0], shell->cmd_exec_parsed) == -1)
        {
            ft_putstr_fd("zsh: command not found: ", 2);
            ft_putendl_fd(shell->cmd_exec_parsed[0], 2);
        }
        exit(1);
    }
    else if (pid < 0)
    {
        ft_putendl_fd("zsh: fork failed.", 2);
    }
    wait(&status);
    return (1);
}