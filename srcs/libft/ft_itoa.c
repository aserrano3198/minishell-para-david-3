/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:45:59 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/12 13:20:29 by aserrano         ###   ########.fr       */
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

	if (n < 0)
		av = n * (-1);
	else
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

static int			n_size(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n / tenpow(i) != 0)
		i++;
	return (i);
}

char				*ft_itoa(int n)
{
	char	*nbr;
	int		size;

	size = n_size(n);
	if (n < 0)
	{
		if (!(nbr = malloc(sizeof(char) * (size + 2))))
			return (NULL);
		nbr[0] = '-';
		fillnbr(nbr, n, size, 1);
	}
	else
	{
		if (!(nbr = malloc(sizeof(char) * (size + 1))))
			return (NULL);
		fillnbr(nbr, n, size, 0);
	}
	return (nbr);
}
