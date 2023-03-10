/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:45:16 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/13 19:43:07 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strlen3(char const *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		i++;
	}
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*conc;
	int		conclen;
	int		i;
	int		o;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	conclen = ft_strlen3(s1) + ft_strlen3(s2) + 1;
	if (!(conc = malloc(sizeof(char) * conclen)))
		return (NULL);
	i = -1;
	while (s1[++i])
		conc[i] = s1[i];
	o = -1;
	while (s2[++o])
		conc[i++] = s2[o];
	conc[i] = '\0';
	return (conc);
}
