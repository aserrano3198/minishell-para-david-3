#include "../includes/minishell.h"

int        builtin_echo(shell_t *shell)
{
    int i;
    int o;
    int flag;

    i = 1;
    o = -1;
    flag = 0;
    if (shell->cmd_exec_parsed[1] && ft_strncmp(shell->cmd_exec_parsed[1], "-n", 2) == 0)
    {
        i++;
        flag = 1;
    }
    while ((shell->cmd_exec_parsed[i]) && (o = -1))
    {
        while (shell->cmd_exec_parsed[i][++o])
            if (shell->cmd_exec_parsed[i][o] != '\"')
                write (STDOUT_FILENO, shell->cmd_exec_parsed[i] + o, 1);
        if (shell->cmd_exec_parsed[i + 1])
            write (STDOUT_FILENO, " ", 1);
        i++;
    }
    if (!flag)
        write(STDOUT_FILENO, "\n", 1);
    return (1);
}