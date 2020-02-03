#include "../includes/minishell.h"

int     builtin_exit(shell_t *shell)
{
    //Hay que liberar todo
    free(shell);
    return (0);
}