/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_width_and_prec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:50:58 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 17:15:07 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		set_i(t_toprint *toprint)
{
	int i;

	if (toprint->format[toprint->i] == '*' && (toprint->flags[MULT] = 1))
	{
		i = va_arg(toprint->args, int);
		if (i < 0)
		{
			if (toprint->format[toprint->i - 1] == '.'
				&& !(toprint->precission_setted = 0))
				i = 0;
			else
			{
				toprint->flags[MINUS] = 1;
				i = i * -1;
			}
		}
		toprint->i++;
	}
	else
		i = ft_atoi(toprint->format + toprint->i);
	return (i);
}

void	positive_i(t_toprint *toprint, int i)
{
	while (toprint->format[toprint->i] >= '0' &&
			toprint->format[toprint->i] <= '9')
		toprint->i++;
	if (toprint->format[toprint->i] == '.' &&
		(toprint->precission_setted = 1))
	{
		toprint->flags[DOT] = 1;
		toprint->zerostr = toprint->flags[ZERO];
		toprint->flags[ZERO] = 0;
		toprint->width = i;
		toprint->i++;
		manage_width_and_prec(toprint);
	}
	else if (toprint->flags[DOT] == 1 && (toprint->precission = i))
	{
		toprint->precission_setted = 1;
		read_arg(toprint);
	}
	else if (toprint->flags[DOT] == 0 && (toprint->width = i))
		read_arg(toprint);
}

void	manage_width_and_prec(t_toprint *toprint)
{
	int i;

	i = set_i(toprint);
	if (i > 0)
		positive_i(toprint, i);
	else if (i == 0)
	{
		if (toprint->format[toprint->i] == '.' && ++toprint->i)
			manage_width_and_prec(toprint);
		else
		{
			while (toprint->format[toprint->i] == '0')
				toprint->i++;
			read_arg(toprint);
		}
	}
	else
	{
		toprint->i++;
		while (toprint->format[toprint->i] >= '0' &&
				toprint->format[toprint->i] <= '9')
			toprint->i++;
		read_arg(toprint);
	}
}
