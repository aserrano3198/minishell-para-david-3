/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:31:46 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 17:33:29 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sw(t_toprint *toprint, char *num)
{
	char	*numf;

	if (toprint->precission >= toprint->width && num[0] == '-')
		numf = neg_prec_bt_width(toprint, num);
	else if (toprint->precission < toprint->width &&
			toprint->width > ft_strlen(num))
		numf = width_bt_prec(toprint, num);
	else if (toprint->precission >= toprint->width && num[0] != '-')
		numf = pos_prec_bt_width(toprint, num);
	else
		numf = num;
	free(num);
	return (numf);
}

void	print_int(t_toprint *toprint)
{
	int				n;
	unsigned int	uns;
	char			*num;
	char			*final;

	n = va_arg(toprint->args, int);
	if (toprint->unsig == 1)
	{
		uns = (unsigned int)n;
		num = ft_unsigned_itoa(uns);
	}
	else
		num = ft_signed_itoa(n);
	if (toprint->precission == 0 &&
			toprint->precission_setted == 1 && num[0] == '0')
		num[0] = '\0';
	if (toprint->precission || toprint->width)
	{
		final = sw(toprint, num);
		ft_putstr_fpf(final, toprint);
	}
	else
		ft_putstr_fpf(num, toprint);
}
