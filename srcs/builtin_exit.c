/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:49:25 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/11 16:21:30 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			builtin_exit(t_shell *shell)
{
	free_command(shell->cmd_exec_parsed);
	free(shell->commands);
	free_command(shell->env);
	free(shell);
	exit(0);
}
