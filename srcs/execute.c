/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:09:54 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/11 16:21:33 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		exec_command(t_shell *shell)
{
	if (shell->cmd_exec_parsed[0] == NULL)
		return (1);
	if (!ft_strncmp(shell->cmd_exec_parsed[0], "cd", 3))
		return (builtin_cd(shell));
	else if (!ft_strncmp(shell->cmd_exec_parsed[0], "exit", 5))
		return (builtin_exit(shell));
	else if (!ft_strncmp(shell->cmd_exec_parsed[0], "env", 4))
		return (builtin_env(shell));
	else if (!ft_strncmp(shell->cmd_exec_parsed[0], "echo", 5))
		return (builtin_echo(shell));
	else if (!ft_strncmp(shell->cmd_exec_parsed[0], "pwd", 4))
		return (builtin_pwd(shell));
	else if (!ft_strncmp(shell->cmd_exec_parsed[0], "export", 6))
		return (builtin_export(shell));
	else if (!ft_strncmp(shell->cmd_exec_parsed[0], "unset", 5))
		return (builtin_unset(shell));
	else
		return (launch(shell, shell->cmd_exec_parsed[0]));
}
