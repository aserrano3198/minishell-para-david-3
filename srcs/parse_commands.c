/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:59:18 by aserrano          #+#    #+#             */
/*   Updated: 2020/02/14 12:58:35 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				parse_pipe(t_shell *shell, char *command)
{
	char		**pipetab;
	int			i;
	t_pipe		*new_elem;
	char		*parse_spaces;

	pipetab = ft_split_pc(command, '|');
	i = -1;
	while (pipetab[++i])
	{
		ft_redirection_pipe(shell, &pipetab[i]);
		parse_spaces = ft_strtrim(pipetab[i], " ");
		if (pipetab[i + 1] == NULL)
			new_elem = new_pipe(parse_spaces, 0, shell->pipe_list, g_read);
		else
			new_elem = new_pipe(parse_spaces, 1, shell->pipe_list, g_read);
		ft_lstadd_back_pipe(&shell->pipe_list, new_elem);
		free(parse_spaces);
		free(pipetab[i]);
	}
	free(pipetab);
	return (1);
}

void			parse_commands(t_shell *shell)
{
	int		i;
	char	*command_execute;

	i = -1;
	while (shell->commands[++i])
	{
		command_execute = ft_strtrim(shell->commands[i], " ");
		free(shell->commands[i]);
		if (ft_strchr(command_execute, '|') &&
		parse_pipe(shell, command_execute) && ft_pipe(shell, shell->pipe_list))
			ft_lstclear_pipe(&shell->pipe_list);
		else if (ft_strchr(command_execute, '<') ||
				ft_strchr(command_execute, '>'))
			ft_is_redirection(shell, command_execute);
		else
		{
			shell->cmd_exec_parsed = ft_comand_split(command_execute, ' ');
			parse_env_vars(shell);
			shell->status_last_command = exec_command(shell);
			free_command(shell->cmd_exec_parsed);
		}
		free(command_execute);
	}
}
