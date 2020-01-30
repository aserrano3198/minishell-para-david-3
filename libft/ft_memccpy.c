/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:03:53 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/14 18:40:13 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	char				*dstcpy;
	char				*srccpy;
	char				*ret;

	dstcpy = (char *)dst;
	srccpy = (char *)src;
	i = -1;
	while (++i < n)
	{
		dstcpy[i] = srccpy[i];
		if (srccpy[i] == (char)c)
		{
			ret = &dstcpy[++i];
			return ((void *)ret);
		}
	}
	return (0);
}
