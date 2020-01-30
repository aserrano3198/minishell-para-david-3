/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:31:03 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 17:33:31 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*hexsw(t_toprint *toprint, char *num)
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

void	ft_putnbr_hex(unsigned av, char *base,
		char *hex_num, t_toprint *toprint)
{
	unsigned			nbase;
	char				print;

	nbase = 16;
	if (av >= nbase)
		ft_putnbr_hex((av / nbase), base, hex_num, toprint);
	print = base[av % nbase];
	hex_num[toprint->hex_i] = print;
	toprint->hex_i++;
}

void	print_hex(t_toprint *toprint)
{
	int							n;
	unsigned					to_hex;
	char						*hex_num;

	n = va_arg(toprint->args, int);
	to_hex = n;
	hex_num = malloc(sizeof(char) * 40);
	if (toprint->mayus)
		ft_putnbr_hex(to_hex, "0123456789ABCDEF", hex_num, toprint);
	else
		ft_putnbr_hex(to_hex, "0123456789abcdef", hex_num, toprint);
	hex_num[toprint->hex_i] = '\0';
	if (toprint->precission == 0 &&
		toprint->precission_setted == 1 && hex_num[0] == '0')
		hex_num[0] = '\0';
	if (toprint->memory == 1)
	{
		toprint->width -= 2;
		ft_putstr_fpf("0x", toprint);
	}
	if (toprint->precission || toprint->width > 0)
		ft_putstr_fpf(hexsw(toprint, hex_num), toprint);
	else
		ft_putstr_fpf(hex_num, toprint);
}
