/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:21:49 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 17:15:00 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	read_arg(t_toprint *toprint)
{
	if (toprint->format[toprint->i] == 's')
		print_str(toprint);
	else if (toprint->format[toprint->i] == 'd' ||
			(toprint->format[toprint->i] == 'i' && (toprint->flagi = 1))
			|| (toprint->format[toprint->i] == 'u' && (toprint->unsig = 1)))
		print_int(toprint);
	else if (toprint->format[toprint->i] == 'c' ||
			(toprint->format[toprint->i] == '%' && (toprint->percent = 1)))
		print_char(toprint);
	else if (toprint->format[toprint->i] == 'x' ||
			(toprint->format[toprint->i] == 'X' && (toprint->mayus = 1)))
		print_hex(toprint);
	else if (toprint->format[toprint->i] == 'p')
	{
		toprint->memory = 1;
		print_mem(toprint);
	}
	else if (toprint->format[toprint->i] == '\0')
		toprint->end = 1;
}
