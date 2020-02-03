#include "../includes/minishell.h"

int     ft_error(char *str)
{
    ft_putendl_fd(str, 1);
    return (0);
}