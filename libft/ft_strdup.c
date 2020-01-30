/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:06:46 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/12 20:24:47 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char			*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i])
	{
		i++;
	}
	if (!(dup = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	ft_strcpy(dup, (char *)src);
	return (dup);
}
