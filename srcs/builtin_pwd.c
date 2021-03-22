/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:03:28 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/02/13 11:28:07 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			builtin_pwd(t_shell *shell)
{
	char	*old_path;
	char	tmp1[4097];

	(void)shell;
	old_path = getcwd(tmp1, 4096);
	write(1, old_path, ft_strlen(old_path));
	write(1, "\n", 1);
	return (1);
}
