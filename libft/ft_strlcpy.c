/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:43:46 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/10 18:31:49 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_strlen2(const char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		i++;
	}
	return (i);
}

static void				*ft_memcpy1(void *dst, const void *src, size_t n)
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

size_t					ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclength;

	if (src == NULL)
		return (0);
	srclength = ft_strlen2(src);
	if (srclength < size)
		ft_memcpy1(dst, src, srclength + 1);
	else if (size)
	{
		ft_memcpy1(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srclength);
}
