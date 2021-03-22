/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:52:16 by aserrano          #+#    #+#             */
/*   Updated: 2020/02/14 14:40:36 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				get_status_var(char *var)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlenchr(var, '$');
	if (var[len] == '$' && var[len + 1] == '?')
		return (3);
	else if (var[0] == '$' && var[1] != '\0')
		return (2);
	else if (var[len] == '$' && var[len + 1] == '\0')
		return (0);
	else
		return (1);
}

static void		update_command1(t_shell *shell, char **cmnd_to_upd,
				char *env_var)
{
	int			len_delim;
	char		*tmp;
	char		*prefix;

	len_delim = ft_strlenchr(*cmnd_to_upd, '$');
	prefix = ft_substr(*cmnd_to_upd, 0, len_delim);
	if (find_env_var(shell, env_var) == 1)
	{
		free(*cmnd_to_upd);
		tmp = get_env_var(shell, env_var, "=");
		*cmnd_to_upd = ft_strjoin(prefix, tmp);
		free(tmp);
	}
	else
	{
		free(*cmnd_to_upd);
		*cmnd_to_upd = ft_strdup(prefix);
	}
	free(prefix);
}

static void		update_command2(t_shell *shell, char **cmnd_to_upd,
				char *env_var)
{
	if (find_env_var(shell, env_var) == 1)
	{
		free(*cmnd_to_upd);
		*cmnd_to_upd = get_env_var(shell, env_var, "=");
	}
	else
		shell->cmd_exec_parsed = ft_arraydelone(shell->cmd_exec_parsed,
		ft_strdup(*cmnd_to_upd));
}

void			update_command(t_shell *shell, char **cmnd_to_upd, int status)
{
	char		*env_var;
	char		*tmp;
	char		*tmp2;

	env_var = ft_strtrim(ft_strchr(*cmnd_to_upd, '$'), "$");
	if (status == 1)
		update_command1(shell, cmnd_to_upd, env_var);
	else if (status == 2)
		update_command2(shell, cmnd_to_upd, env_var);
	else if (status == 3)
	{
		if (shell->status_last_command == 1)
			tmp = ft_strdup("0");
		else if (shell->status_last_command == 2)
			tmp = ft_strdup("1");
		else
			tmp = ft_strdup("127");
		tmp2 = ft_strdup(*cmnd_to_upd);
		free(*cmnd_to_upd);
		*cmnd_to_upd = ft_replacestr(tmp2, "$?", tmp);
		free(tmp);
	}
	free(env_var);
}

void			parse_env_vars(t_shell *shell)
{
	int		i;
	int		status;

	i = -1;
	while (shell->cmd_exec_parsed[++i])
	{
		if (ft_strchr(shell->cmd_exec_parsed[i], '$'))
		{
			status = get_status_var(shell->cmd_exec_parsed[i]);
			if (status != 0)
				update_command(shell, &shell->cmd_exec_parsed[i], status);
		}
	}
}
