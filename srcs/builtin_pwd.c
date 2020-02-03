#include "../includes/minishell.h"

int        builtin_pwd(shell_t *shell)
{
    char *path;

    path = get_env_var(shell, "PWD", "=");
    write(1, path, ft_strlen(path));
    write(1, "\n", 1);
    return (1);
}