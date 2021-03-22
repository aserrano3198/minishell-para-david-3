/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:06:18 by aserrano          #+#    #+#             */
/*   Updated: 2020/02/14 14:23:08 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			ft_close_fds(t_shell *shell, t_pipe *list_cmnd, int pipe_open)
{
	if (pipe_open)
	{
		close(list_cmnd->fd[1]);
		if (!list_cmnd->next || list_cmnd->pipe == 0)
			close(list_cmnd->fd[0]);
	}
	if (list_cmnd->previous && list_cmnd->previous->pipe == 1)
		close(list_cmnd->previous->fd[0]);
	if (shell->redirection_out && !list_cmnd->next)
	{
		close(shell->redirection_out);
		shell->redirection_out = 0;
	}
	if (shell->redirection_in && g_read)
	{
		close(shell->redirection_in);
		shell->redirection_in = 0;
		if (!shell->redirection_out)
			g_read = 0;
		else
			g_read = 2;
	}
}

int				ft_filedescriptors(t_shell *shell, t_pipe *list_cmnd)
{
	if (shell->redirection_out &&
		!list_cmnd->next && dup2(shell->redirection_out, STDOUT_FILENO) < 0)
		return (0);
	if (shell->redirection_in &&
		list_cmnd->read && dup2(shell->redirection_in, STDIN_FILENO) < 0)
		return (0);
	if (list_cmnd->pipe == 1 &&
		dup2(list_cmnd->fd[1], STDOUT_FILENO) < 0)
		return (0);
	if (list_cmnd->previous &&
	list_cmnd->previous->pipe == 1 &&
		dup2(list_cmnd->previous->fd[0], STDIN_FILENO) < 0)
		return (0);
	return (1);
}

int				ft_child_process(t_shell *shell, t_pipe *list_cmnd)
{
	if (!ft_filedescriptors(shell, list_cmnd))
		return (0);
	shell->cmd_exec_parsed = list_cmnd->pipe_parse;
	parse_env_vars(shell);
	shell->status_last_command = exec_command(shell);
	exit(1);
	return (1);
}

int				ft_pipe2(t_shell *shell,
				t_pipe *list_cmnd, int *pipe_open, int *ret)
{
	pid_t	pid;
	int		status;

	if ((list_cmnd->pipe == 1 || (list_cmnd->previous &&
	list_cmnd->previous->pipe == 1)) && (*pipe_open = 1))
		if (pipe(list_cmnd->fd))
			return (0);
	g_forking = 1;
	if ((pid = fork()) < 0)
		return (0);
	else if (pid == 0)
		ft_child_process(shell, list_cmnd);
	else
	{
		waitpid(pid, &status, 0);
		if ((g_read != 1) && shell->redirection_out
		&& !list_cmnd->next && !(g_read = 0) && close(shell->redirection_out))
			shell->redirection_out = 0;
		ft_close_fds(shell, list_cmnd, *pipe_open);
		if (WIFEXITED(status))
			*ret = WEXITSTATUS(status);
		g_forking = 0;
	}
	return (1);
}

int				ft_pipe(t_shell *shell, t_pipe *list_cmnd)
{
	int		ret;
	int		pipe_open;

	while (list_cmnd)
	{
		ret = EXIT_FAILURE;
		pipe_open = 0;
		if (!(ft_pipe2(shell, list_cmnd, &pipe_open, &ret)))
			return (0);
		list_cmnd = list_cmnd->next;
	}
	return (1);
}
