#include "../includes/minishell.h"

int        builtin_env(shell_t *shell)
{
    int     i;

    i = -1;
    while (shell->env[++i])
        ft_printf("%s\n", shell->env[i]);
    return (1);
}