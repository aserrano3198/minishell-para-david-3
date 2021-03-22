/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:34:32 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/11 16:21:29 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	builtin_cd2(t_shell *shell, char *old_path)
{
	char	tmp[4097];

	set_env_var(shell, "PWD", getcwd(tmp, 4096));
	set_env_var(shell, "OLDPWD", old_path);
	return (1);
}

int			builtin_cd(t_shell *shell)
{
	char	*home_path;
	char	*old_path;
	char	tmp1[4097];

	old_path = getcwd(tmp1, 4096);
	if (shell->cmd_exec_parsed[1] == NULL ||
		!ft_strncmp(shell->cmd_exec_parsed[1], "~", 2))
	{
		home_path = get_env_var(shell, "HOME", "=");
		chdir(home_path);
		free(home_path);
	}
	else if (!ft_strncmp(shell->cmd_exec_parsed[1], "-", 2))
	{
		home_path = get_env_var(shell, "OLDPWD", "=");
		chdir(home_path);
		free(home_path);
	}
	else if (chdir(shell->cmd_exec_parsed[1]) != 0)
	{
		perror("cd");
		return (0);
	}
	return (builtin_cd2(shell, old_path));
}
