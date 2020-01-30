/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:15:42 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 17:15:08 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	manage_flags(t_toprint *toprint)
{
	while (toprint->format[toprint->i] == '0' ||
		toprint->format[toprint->i] == '-' ||
		toprint->format[toprint->i] == '.' ||
		toprint->format[toprint->i] == '*')
	{
		if (toprint->format[toprint->i] == '0')
			toprint->flags[ZERO] = 1;
		else if (toprint->format[toprint->i] == '-')
			toprint->flags[MINUS] = 1;
		else if (toprint->format[toprint->i] == '.')
		{
			toprint->precission_setted = 1;
			toprint->flags[DOT] = 1;
		}
		else if (toprint->format[toprint->i] == '*')
			return ;
		toprint->i++;
	}
}
