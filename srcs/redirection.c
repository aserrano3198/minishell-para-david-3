/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:06:08 by aserrano          #+#    #+#             */
/*   Updated: 2020/02/14 13:07:56 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				ft_redirection_pipe(t_shell *shell, char **command)
{
	char	**ret;
	char	*trimmed;

	if (ft_strchr(*command, '<'))
	{
		ret = ft_split_pc(*command, '<');
		trimmed = ft_strtrim(ret[1], " \"\'");
		shell->redirection_in = open(trimmed, O_RDONLY, 0777);
		if (shell->redirection_in == -1)
			return (ft_fail_message(ret[1]));
		g_read = 1;
	}
	else if (ft_strnstr(*command, ">>",
			ft_strlen(*command)) && (ret = ft_split_pc(*command, '>'))
			&& (trimmed = ft_strtrim(ret[1], " \"\'")))
		shell->redirection_out = open(trimmed,
		O_WRONLY | O_APPEND | O_CREAT, 0777);
	else if (ft_strchr(*command, '>')
			&& (ret = ft_split_pc(*command, '>'))
			&& (trimmed = ft_strtrim(ret[1], " \"\'")))
		shell->redirection_out = open(trimmed,
			O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		return (0);
	return (ft_free(ret, trimmed, command, 1));
}

int				ft_redirection(t_shell *shell, char **command)
{
	char	**ret;
	char	*trimmed;

	if (ft_strchr(*command, '<'))
	{
		ret = ft_split_pc(*command, '<');
		trimmed = ft_strtrim(ret[1], " \"\'");
		shell->redirection_in = open(trimmed, O_RDONLY, 0777);
		if (shell->redirection_in == -1)
			return (ft_fail_message(ret[1]));
		g_read = 1;
	}
	else if (ft_strnstr(*command, ">>",
			ft_strlen(*command)) && (ret = ft_split_pc(*command, '>'))
			&& (trimmed = ft_strtrim(ret[1], " \"\'")))
		shell->redirection_out = open(trimmed,
		O_WRONLY | O_APPEND | O_CREAT, 0777);
	else if (ft_strchr(*command, '>')
			&& (ret = ft_split_pc(*command, '>'))
			&& (trimmed = ft_strtrim(ret[1], " \"\'")))
		shell->redirection_out = open(trimmed,
			O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		return (0);
	return (ft_free(ret, trimmed, command, 0));
}

void			execute_redirection(t_shell *shell)
{
	if (!g_read)
		dup2(shell->redirection_out, STDOUT_FILENO);
	else if (g_read == 1)
		dup2(shell->redirection_in, STDIN_FILENO);
	shell->status_last_command = exec_command(shell);
	exit(1);
}

void			ft_father_process(t_shell *shell, pid_t pid)
{
	wait(&pid);
	if ((!g_read || g_read == 2) && shell->redirection_out)
	{
		close(shell->redirection_out);
		shell->redirection_out = 0;
		g_read = 0;
	}
	if (g_read == 1 && shell->redirection_in)
	{
		close(shell->redirection_in);
		shell->redirection_in = 0;
		if (!shell->redirection_out)
			g_read = 0;
		else
			g_read = 2;
	}
	g_forking = 0;
}

int				ft_is_redirection(t_shell *shell, char *command)
{
	pid_t	pid;
	int		retu;

	retu = ft_redirection(shell, &command);
	if (retu != 1)
		return (0);
	shell->cmd_exec_parsed = ft_comand_split(command, ' ');
	free(command);
	parse_env_vars(shell);
	g_forking = 1;
	pid = fork();
	if (pid == 0)
		execute_redirection(shell);
	else
		ft_father_process(shell, pid);
	free_command(shell->cmd_exec_parsed);
	return (1);
}
