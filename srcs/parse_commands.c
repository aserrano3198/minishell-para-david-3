#include "../includes/minishell.h"

static void    free_command(char **command)
{
    int     i;

    i = 0;
    while (command[i])
        free(command[i++]);
}

int             parse_commands(shell_t *shell)
{
    int     i;
    char    *command_execute;

    i = -1;
    while (shell->commands[++i])
    {
        command_execute = ft_strtrim(shell->commands[i], " ");
        free(shell->commands[i]);
        shell->cmd_exec_parsed = ft_split(command_execute, ' ');
        free(command_execute);
        if (!(exec_command(shell)))
            return (0);
        free_command(shell->cmd_exec_parsed);
    }
    return (1);
}
