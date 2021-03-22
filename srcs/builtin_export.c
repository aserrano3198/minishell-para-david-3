/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:50:05 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/11 16:21:31 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			parse_var(char *var)
{
	int		i;

	i = -1;
	if (var[0] == '=' && var[1] == '\0')
		return (-1);
	else if (!ft_strchr(var, '='))
		return (0);
	else
	{
		while (var[++i])
		{
			if (var[i] == '=' && var[i + 1] == '\0')
				return (1);
			else if (var[i] == '=' && var[i + 1] != '\0')
				return (2);
		}
	}
	return (0);
}

int			parse_status2(t_shell *shell, char *var, int status)
{
	char	*new_var;
	char	*var_value;

	if (status == 0)
	{
		new_var = ft_strdup(var);
		var_value = ft_strdup("''");
		if (find_env_var(shell, new_var) == 0)
			add_env_var(shell, new_var, var_value);
	}
	else
	{
		new_var = ft_strbgchr(var, '=');
		if (status == 2)
			var_value = ft_strtrim(ft_strrchr(var, '='), "=");
		else
			var_value = ft_strdup("''");
		if (find_env_var(shell, new_var) == 1)
			set_env_var(shell, new_var, var_value);
		else
			add_env_var(shell, new_var, var_value);
	}
	free(new_var);
	free(var_value);
	return (1);
}

int			parse_status(t_shell *shell, char *var, int status, int ok)
{
	if (ok == 1)
	{
		if (status == -1)
			return (ft_error("minishell: bad assignment"));
		else
			return (parse_status2(shell, var, status));
	}
	else
		return (0);
}

int			builtin_export(t_shell *shell)
{
	int		i;
	int		status;
	int		ok;

	ok = 1;
	i = 0;
	if (shell->cmd_exec_parsed[1] == NULL)
		builtin_env(shell);
	else
		while (shell->cmd_exec_parsed[++i])
		{
			status = parse_var(shell->cmd_exec_parsed[i]);
			ok = parse_status(shell, shell->cmd_exec_parsed[i], status, ok);
		}
	return (1);
}
