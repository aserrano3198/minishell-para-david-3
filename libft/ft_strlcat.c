/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:13:52 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/10 18:31:48 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen1(char *str)
{
	size_t i;

	i = 0;
	while (*(str + i))
	{
		i++;
	}
	return (i);
}

static size_t	set_ret(char *dest, char *src, size_t size)
{
	if (ft_strlen1(dest) >= size)
		return (ft_strlen1(src) + size);
	else
		return (ft_strlen1(dest) + ft_strlen1(src));
}

size_t			ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	ret;

	ret = set_ret(dest, src, size);
	i = 0;
	n = 0;
	i = ft_strlen1(dest);
	while (src[n] && size > 1 + i)
	{
		dest[i] = src[n];
		i++;
		n++;
	}
	dest[i] = '\0';
	return (ret);
}
