/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:51:15 by aserrano          #+#    #+#             */
/*   Updated: 2020/02/14 14:17:40 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			banner(t_shell *shell)
{
	shell->cmd_exec_parsed = malloc(sizeof(char *) * 2);
	shell->cmd_exec_parsed[0] = ft_strdup("clear");
	shell->cmd_exec_parsed[1] = NULL;
	launch(shell, "clear");
	free(shell->cmd_exec_parsed[0]);
	free(shell->cmd_exec_parsed);
	write(1, "\e[35m,-.-. o       o       | \e[0m   \n", 40);
	write(1, "\e[35m| | | | ,---. |       |---.       |     |    \e[0m\n", 58);
	write(1, "\e[35m| | | | |   | | ,---. |   | ,---. |     |    \e[0m\n", 58);
	write(1, "\e[35m| | | | |   | | `---. |   | |---' |     |    \e[0m\n", 58);
	write(1, "\e[35m` ' ' ` `   ` ` `---' `   ' `---' `---' `---'\e[0m\n", 58);
	write(1, "\e[90m                                             \e[0m\n", 58);
	write(1, "\e[90m                                             \e[0m\n", 58);
	write(1, "\e[90m \e[0m     \e[36mDeveloped by:      aserrano\e[0m\n", 58);
	write(1, "\e[90m \e[0m                      \e[36m  pcuadrad\e[0m\n", 58);
}

void			handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		if (g_forking)
			write(1, "\n", 1);
		else
		{
			write(1, "\n", 1);
			write(1, "\033[33mminishell\033[0m > ", 21);
		}
	}
	else if (signal == SIGQUIT)
		return ;
}

int				main(int argc, char *argv[], char *env[])
{
	char	*line;
	t_shell	*shell;

	if (!(shell = init_save_env(argc, argv, env)))
		return (ft_error("Failed allocate memory"));
	banner(shell);
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
	while (1)
	{
		write(1, "\033[33mminishell\033[0m > ", 21);
		if (get_next_line(STDIN_FILENO, &line) == 0 && line[0] == '\0')
		{
			write(1, "exit\n", 5);
			free(line);
			break ;
		}
		shell->commands = ft_split_pc(line, ';');
		free(line);
		parse_commands(shell);
		free(shell->commands);
	}
	return (EXIT_SUCCESS);
}
