/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:11:18 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/14 15:23:13 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		launch_child_procces(t_shell *shell, char *path_exec,
			char *route_path, int i)
{
	int		flag;
	char	*tmp;
	char	*command;

	shell->path = ft_split(route_path, ':');
	if ((flag = 1) && execve(path_exec, shell->cmd_exec_parsed,
	shell->env) == -1 && (command = ft_strjoin("/", path_exec)))
	{
		flag = 0;
		while (shell->path[++i] && flag != 1 &&
			(tmp = ft_strjoin(shell->path[i], command)))
		{
			if (execve(tmp, shell->cmd_exec_parsed, shell->env) != -1)
				flag = 1;
			free(tmp);
		}
		free(command);
	}
	free_command(shell->path);
	if (!flag)
	{
		ft_cmdfail(path_exec);
		exit(2);
	}
	exit(1);
}

int			launch(t_shell *shell, char *path_exec)
{
	pid_t	pid;
	int		status;
	char	*route_path;

	g_forking = 1;
	status = 0;
	route_path = get_env_var(shell, "PATH", "=");
	if ((pid = fork()) < 0)
		return (ft_error("minishell: fork failed."));
	if (pid == 0)
		launch_child_procces(shell, path_exec, route_path, -1);
	else
		waitpid(pid, &status, 0);
	g_forking = 0;
	free(route_path);
	if (status > 0 && status < 512)
		return (2);
	else if (status == 512)
		return (0);
	return (1);
}
