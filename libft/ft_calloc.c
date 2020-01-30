/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:20:34 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/14 18:06:07 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*s;
	char			*scpy;
	size_t			bytes;
	size_t			i;

	bytes = count * size;
	if (!(s = malloc(bytes)))
		return (NULL);
	scpy = (char *)s;
	i = -1;
	while (++i < bytes)
		scpy[i] = 0;
	return (s);
}
