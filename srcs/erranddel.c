/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erranddel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:09:36 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/14 15:22:09 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	return (0);
}

void		free_command(char **command)
{
	int		i;

	i = 0;
	while (command[i])
		free(command[i++]);
	(command) ? free(command) : 0;
}

int			ft_free(char **ret, char *trimmed, char **command, int selector)
{
	free(trimmed);
	free(ret[1]);
	free(ret);
	if (selector)
	{
		trimmed = *command;
		*command = ret[0];
		free(trimmed);
	}
	else
		*command = ret[0];
	return (1);
}

void		ft_cmdfail(char *str)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(str, 2);
}
