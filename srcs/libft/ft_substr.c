/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:08:43 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/18 17:14:28 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strlen5(const char *str)
{
	size_t i;

	i = 0;
	while (*(str + i))
	{
		i++;
	}
	return (i);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;

	if (s == NULL)
		return (NULL);
	if (!(substr = (char *)malloc(sizeof(char) * ((int)len + 1))))
		return (NULL);
	ft_bzero(substr, len);
	if (start <= ft_strlen5(s))
		ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
