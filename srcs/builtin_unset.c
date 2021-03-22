/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:04:06 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/11 16:21:32 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			builtin_unset(t_shell *shell)
{
	int		i;

	i = 0;
	if (shell->cmd_exec_parsed[1] != NULL)
		while (shell->cmd_exec_parsed[++i])
			if (find_env_var(shell, shell->cmd_exec_parsed[i]))
				del_env_var(shell, shell->cmd_exec_parsed[i]);
	return (1);
}
