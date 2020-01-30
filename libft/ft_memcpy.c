/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:19:29 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/12 20:02:46 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*dstcpy;
	char			*srccpy;

	if (!n || dst == src)
		return (dst);
	dstcpy = (char *)dst;
	srccpy = (char *)src;
	i = -1;
	while (++i < n)
		dstcpy[i] = srccpy[i];
	return (dst);
}
