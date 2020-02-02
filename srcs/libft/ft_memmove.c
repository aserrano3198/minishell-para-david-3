/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:41:56 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/12 17:09:22 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	char			*dstcpy;
	char			*srccpy;

	if (!len || dst == src)
		return (dst);
	dstcpy = (char *)dst;
	srccpy = (char *)src;
	i = -1;
	if (dstcpy > srccpy)
		while (len != 0)
		{
			len--;
			dstcpy[len] = srccpy[len];
		}
	else
		while (++i < len)
			dstcpy[i] = srccpy[i];
	return (dst);
}
