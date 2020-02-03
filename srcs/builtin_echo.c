#include "../includes/minishell.h"

int        builtin_echo(shell_t *shell)
{
    int i;
    char *todisplay;

    i = 1;
    while (shell->cmd_exec_parsed[i])
        {
            todisplay = ft_strtrim(shell->cmd_exec_parsed[i], "\"");
            write (1, todisplay, ft_strlen(todisplay));
            write (1, " ", 1);
            free(todisplay);
            i++;
        }
    write(1, "\n", 1);
    return (1);
}