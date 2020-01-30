/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:01:37 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/09 00:01:55 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*bcpy;
	size_t			i;

	i = 0;
	bcpy = (char *)b;
	while (i < len)
	{
		*(bcpy + i) = c;
		i++;
	}
	return (b);
}
