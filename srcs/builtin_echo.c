#include "../includes/minishell.h"

int        builtin_echo(shell_t *shell)
{
    int i;
    char *todisplay;
    int flag;

    i = 1;
    flag = 0;
    if (ft_strncmp(shell->cmd_exec_parsed[1], "-n", 2) == 0)
    {
        i++;
        flag = 1;
    }
    while (shell->cmd_exec_parsed[i])
    {
        todisplay = ft_strtrim(shell->cmd_exec_parsed[i], "\"");
        write (1, todisplay, ft_strlen(todisplay));
        if (shell->cmd_exec_parsed[i + 1])
            write (1, " ", 1);
        free(todisplay);
        i++;
    }
    if (!flag)
        write(1, "\n", 1);
    return (1);
}