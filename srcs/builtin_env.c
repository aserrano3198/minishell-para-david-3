/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:48:21 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/11 16:21:30 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			builtin_env(t_shell *shell)
{
	int		i;

	i = -1;
	while (shell->env[++i])
	{
		write(1, shell->env[i], ft_strlen(shell->env[i]));
		write(1, "\n", 1);
	}
	return (1);
}
