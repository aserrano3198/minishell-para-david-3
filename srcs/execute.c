#include "../includes/minishell.h"

int     exec_command(shell_t *shell)
{
    if (shell->cmd_exec_parsed[0] == NULL)
        return (1);
    if (!ft_strncmp(shell->cmd_exec_parsed[0], "cd", 2))
            return (builtin_cd(shell));
    else if (!ft_strncmp(shell->cmd_exec_parsed[0], "exit", 4))
            return (builtin_exit(shell));
    else
        return (launch(shell));
}