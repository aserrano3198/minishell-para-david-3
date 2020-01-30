/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 09:26:09 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/26 09:26:31 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static long int		tenpow(int i)
{
	long int		pow;

	pow = 1;
	while (i >= 1)
	{
		pow = 10 * pow;
		i--;
	}
	return (pow);
}

static void			fillnbr(char *nbr, int n, int size, int i)
{
	unsigned int av;

	av = n;
	while (size > 0)
	{
		nbr[i] = (av / tenpow(size - 1)) + '0';
		av = av % tenpow(size - 1);
		size--;
		i++;
	}
	nbr[i] = '\0';
}

static int			n_size(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n / tenpow(i) != 0)
		i++;
	return (i);
}

char				*ft_unsigned_itoa(unsigned int n)
{
	char	*nbr;
	int		size;

	size = n_size(n);
	if (!(nbr = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	fillnbr(nbr, n, size, 0);
	return (nbr);
}
