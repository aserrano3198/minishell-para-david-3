/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:45:37 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 16:46:07 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup_gnl(const char *src)
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
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int				ft_strchr_gnl(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (s[i] == c)
		return (1);
	return (0);
}

char			*ft_strjoin_and_free(char *str, char *buf)
{
	int		i;
	int		j;
	char	*joined;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (buf[j])
		j++;
	joined = malloc(sizeof(char) * (i + j + 1));
	i = -1;
	j = 0;
	while (str[++i])
		joined[i] = str[i];
	while (buf[j])
		joined[i++] = buf[j++];
	joined[i] = '\0';
	free(str);
	return (joined);
}
