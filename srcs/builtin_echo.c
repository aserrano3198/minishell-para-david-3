/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:37:13 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/14 12:43:08 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	builtin_echo2(t_shell *shell, int i)
{
	int		o;

	while ((shell->cmd_exec_parsed[++i]) && (o = -1))
	{
		while (shell->cmd_exec_parsed[i][++o])
			write(STDOUT_FILENO, shell->cmd_exec_parsed[i] + o, 1);
		if (shell->cmd_exec_parsed[i + 1])
			write(STDOUT_FILENO, " ", 1);
	}
}

int			builtin_echo(t_shell *shell)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (shell->cmd_exec_parsed[1] &&
		!ft_strncmp(shell->cmd_exec_parsed[1], "-n", 2))
	{
		i++;
		flag = 1;
	}
	builtin_echo2(shell, i);
	if (!flag)
		write(STDOUT_FILENO, "\n", 1);
	return (1);
}
