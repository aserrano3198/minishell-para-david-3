#include "../includes/minishell.h"

int     ft_error(char *str)
{
    ft_putendl_fd(str, 2);
    return (0);
}