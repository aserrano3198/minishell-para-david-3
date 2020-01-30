/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:11:40 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/08 23:59:05 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*scpy;
	size_t			i;

	i = -1;
	scpy = (char *)s;
	while (++i < n)
		if (scpy[i] == (char)c)
			return ((void *)(s + i));
	return (NULL);
}
