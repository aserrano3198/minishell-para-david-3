/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:33:34 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 17:33:33 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_mem(long unsigned int av,
		char *base, char *hex_num, t_toprint *toprint)
{
	long unsigned int	nbase;
	char				print;

	nbase = 16;
	if (av >= nbase)
		ft_putnbr_mem((av / nbase), base, hex_num, toprint);
	print = base[av % nbase];
	hex_num[toprint->hex_i] = print;
	toprint->hex_i++;
}

char	*ft_special_case(char *str)
{
	char	*final;
	int		i;
	int		j;

	i = 2;
	j = 1;
	final = malloc(sizeof(char) * ft_strlen(str) + 2);
	final[0] = '0';
	final[1] = 'x';
	while (str[j])
		final[i++] = str[j++];
	final[i] = str[j];
	return (final);
}

char	*ft_check_memo(char *str, t_toprint *toprint)
{
	int		i;
	char	*dup;

	i = 0;
	if (toprint->width > toprint->precissioncpy + 1)
	{
		while (str[i] == ' ')
			i++;
		str[--i] = 'x';
		str[--i] = '0';
	}
	else if (toprint->width == toprint->precissioncpy + 1)
	{
		dup = ft_special_case(str);
		free(str);
		str = dup;
	}
	return (str);
}

void	small_function(t_toprint *toprint, char *hex_num)
{
	char	*final;

	final = memsw(toprint, hex_num);
	if (toprint->width > toprint->precissioncpy &&
		toprint->width > ft_strlen(hex_num) && toprint->flags[ZERO] == 0)
		final = ft_check_memo(final, toprint);
	ft_putstr_fpf(final, toprint);
}

void	print_mem(t_toprint *toprint)
{
	long long int				n;
	long unsigned int			to_hex;
	char						*hex_num;

	toprint->precissioncpy = toprint->precission;
	n = va_arg(toprint->args, long long int);
	if (n == 0 && (toprint->nullmemo = 1) && print_str(toprint))
		return ;
	to_hex = n;
	hex_num = malloc(sizeof(char) * 40);
	ft_putnbr_mem(to_hex, "0123456789abcdef", hex_num, toprint);
	hex_num[toprint->hex_i] = '\0';
	if (!(toprint->width > toprint->precissioncpy &&
		toprint->width > ft_strlen(hex_num) && toprint->flags[ZERO] == 0))
	{
		toprint->width -= 2;
		ft_putstr_fpf("0x", toprint);
	}
	if (toprint->precission || toprint->width > 0)
		small_function(toprint, hex_num);
	else
		ft_putstr_fpf(hex_num, toprint);
}
