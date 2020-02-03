#include "../includes/minishell.h"

int        builtin_echo(shell_t *shell);

int     exec_command(shell_t *shell)
{
    if (shell->cmd_exec_parsed[0] == NULL)
        return (1);
    if (!ft_strncmp(shell->cmd_exec_parsed[0], "cd", 2))
            return (builtin_cd(shell));
    else if (!ft_strncmp(shell->cmd_exec_parsed[0], "exit", 4))
            return (builtin_exit(shell));
    else if (!ft_strncmp(shell->cmd_exec_parsed[0], "env", 3))
            return (builtin_env(shell));
	else if (!ft_strncmp(shell->cmd_exec_parsed[0], "echo", 4))
            return (builtin_echo(shell));
    else
        return (launch(shell));
}