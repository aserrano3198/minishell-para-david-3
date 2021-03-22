/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:51:46 by aserrano          #+#    #+#             */
/*   Updated: 2020/02/12 13:01:25 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			is_replace(char *str, int pos, char *replace)
{
	int		i;

	i = 0;
	while (str[pos])
	{
		if (str[pos] == replace[i])
		{
			i++;
			pos++;
		}
		else
			break ;
		if (replace[i] == '\0')
			return (1);
	}
	return (0);
}

char		*ft_replacestr(char *str_to_replace, char *replace, char *value)
{
	char	*str_replaced;
	int		len;
	int		i;
	int		j;
	int		t;

	len = ft_strlen(str_to_replace) - ft_strlen(replace) + ft_strlen(value);
	str_replaced = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 0;
	while (str_to_replace[i])
	{
		if (is_replace(str_to_replace, i, replace))
		{
			t = 0;
			while (value[t])
				str_replaced[j++] = value[t++];
			i += ft_strlen(replace);
		}
		if (str_to_replace[i])
			str_replaced[j++] = str_to_replace[i++];
	}
	free(str_to_replace);
	str_replaced[j] = '\0';
	return (str_replaced);
}

int			len_env(char *env[])
{
	int		len;

	len = 0;
	while (env[len])
		len++;
	return (len);
}

t_shell		*init_save_env(int argc, char *argv[], char *env[])
{
	t_shell *shell;
	int		size;
	int		i;

	(void)argc;
	(void)argv;
	if (!(shell = (t_shell*)malloc(sizeof(t_shell) * 1)))
		return (NULL);
	size = len_env(env);
	if (!(shell->env = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	shell->env[size] = NULL;
	i = -1;
	while (env[++i])
		if (!(shell->env[i] = ft_strdup(env[i])))
			return (NULL);
	shell->status_last_command = 1;
	shell->redirection_out = 0;
	shell->redirection_in = 0;
	g_read = 0;
	shell->pipe_list = NULL;
	return (shell);
}

int			ft_fail_message(char *str)
{
	write(2, "zsh: no such file or directory:", 32);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (2);
}
