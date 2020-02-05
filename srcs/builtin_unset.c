#include "../includes/minishell.h"

int        builtin_unset(shell_t *shell)
{
    int     i;

    i = 0;
    if (shell->cmd_exec_parsed[1] != NULL)    
        while (shell->cmd_exec_parsed[++i])
            if (find_env_var(shell, shell->cmd_exec_parsed[i]))
                del_env_var(shell, shell->cmd_exec_parsed[i]);
    return (1);
}