/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:08:30 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/13 11:19:19 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*get_env_var(t_shell *shell, char *env, char *delim)
{
	int		i;
	char	*path;
	char	*tmp;
	size_t	len_path;
	int		find;

	len_path = ft_strlen(env);
	i = -1;
	find = 0;
	while (shell->env[++i] && find == 0)
		if ((ft_strncmp(shell->env[i], env, len_path)) == 0)
		{
			tmp = ft_strchr(shell->env[i], delim[0]);
			find = 1;
		}
	if (!find)
		return (NULL);
	path = ft_strtrim(tmp, delim);
	return (path);
}

void		set_env_var(t_shell *shell, char *env, char *new_path)
{
	int		i;
	char	*tmp;
	size_t	len_path;

	tmp = ft_strjoin(env, "=");
	len_path = ft_strlen(tmp);
	i = -1;
	while (shell->env[++i])
		if ((ft_strncmp(shell->env[i], tmp, len_path)) == 0)
		{
			free(shell->env[i]);
			shell->env[i] = ft_strjoin(tmp, new_path);
			break ;
		}
	free(tmp);
}

void		add_env_var(t_shell *shell, char *new_env, char *new_value)
{
	int		i;
	char	**env;
	char	*tmp;

	i = 0;
	while (shell->env[i])
		i++;
	if (!(env = (char **)malloc(sizeof(char*) * (i + 2))))
		return ;
	i = -1;
	while (shell->env[++i])
		env[i] = shell->env[i];
	tmp = ft_strjoin(new_env, "=");
	env[i] = ft_strjoin(tmp, new_value);
	free(tmp);
	env[i + 1] = NULL;
	free(shell->env);
	shell->env = env;
}

int			find_env_var(t_shell *shell, char *env_to_find)
{
	int		i;
	size_t	len_path;
	char	*tmp;
	int		found;

	tmp = ft_strjoin(env_to_find, "=");
	len_path = ft_strlen(tmp);
	found = 0;
	i = -1;
	while (shell->env[++i] && found == 0)
		if ((ft_strncmp(shell->env[i], tmp, len_path)) == 0)
			found = 1;
	free(tmp);
	if (found)
		return (1);
	return (0);
}

int			del_env_var(t_shell *shell, char *env_to_del)
{
	int		i;
	size_t	len_path;
	char	*tmp;

	tmp = ft_strjoin(env_to_del, "=");
	len_path = ft_strlen(tmp);
	i = -1;
	while (shell->env[++i])
		if ((ft_strncmp(shell->env[i], tmp, len_path)) == 0)
		{
			shell->env = ft_arraydelone(shell->env, tmp);
			break ;
		}
	return (0);
}
