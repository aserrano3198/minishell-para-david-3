/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:26:37 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 17:34:14 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_write_and_count(t_toprint *toprint, char c)
{
	write(1, &c, 1);
	toprint->counter++;
}

void	first_strnull(t_toprint *toprint)
{
	int i;

	i = 1;
	ft_write_and_count(toprint, '\0');
	while (i++ < toprint->width)
		ft_write_and_count(toprint, ' ');
}

void	last_strnull(t_toprint *toprint)
{
	int i;

	i = 0;
	while (i < (toprint->width - 1))
	{
		if (toprint->flags[ZERO] == 1 || toprint->zerostr == 1)
			ft_write_and_count(toprint, '0');
		else
			ft_write_and_count(toprint, ' ');
		i++;
	}
	ft_write_and_count(toprint, '\0');
}

void	finalstr_null(t_toprint *toprint)
{
	if (toprint->width == 0)
		ft_write_and_count(toprint, '\0');
	else
	{
		if (toprint->flags[MINUS] == 1)
			first_strnull(toprint);
		if (toprint->flags[MINUS] == 0)
			last_strnull(toprint);
	}
}

void	print_char(t_toprint *toprint)
{
	char	*c;
	char	*final;

	toprint->ischar = 1;
	c = malloc(sizeof(char) * 2);
	if (toprint->percent == 0)
		c[0] = va_arg(toprint->args, int);
	else
		c[0] = '%';
	if (c[0] == 0)
		toprint->nullchar = 1;
	c[1] = '\0';
	if (toprint->nullchar == 1)
		finalstr_null(toprint);
	else if (toprint->precission_setted || toprint->width)
	{
		final = finalstr(toprint, c);
		ft_putstr_fpf(final, toprint);
	}
	else
		ft_putstr_fpf(c, toprint);
}
