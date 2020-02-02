/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:05:08 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 17:15:11 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	t_toprint *toprint;

	toprint = (t_toprint *)malloc(sizeof(t_toprint));
	ft_init(toprint, format);
	va_start(toprint->args, format);
	if (format[0] && format[0] == '%' && format[1] == '\0')
		return (0);
	if (format)
	{
		while (format[toprint->i])
		{
			if (format[toprint->i] != '%' && ++toprint->counter)
				write(1, &format[toprint->i], 1);
			else if (format[toprint->i++] == '%')
			{
				manage_flags(toprint);
				manage_width_and_prec(toprint);
			}
			ft_reset_toprint(toprint);
			if (!(toprint->end))
				toprint->i++;
		}
	}
	va_end(toprint->args);
	return (toprint->counter);
}
