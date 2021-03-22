/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:46:31 by aserrano          #+#    #+#             */
/*   Updated: 2020/02/14 14:04:56 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				size_quoted_word(char *s, int i)
{
	char	quote;
	int		count;

	quote = s[i];
	count = 0;
	i++;
	while (s[i] && s[i] != quote)
	{
		i++;
		count++;
	}
	return (count);
}

static int		size_nextword(char *s, char c, int i)
{
	int counter;

	while (s[i] == c && s[i])
		i++;
	counter = 0;
	while (s[i])
	{
		if ((s[i] == '\"' || s[i] == '\'') && counter == 0)
			return (size_quoted_word(s, i));
		if (s[i] == c || s[i] == '\"' || s[i] == '\'')
			return (counter);
		counter++;
		i++;
	}
	return (counter);
}

int				save_quoted_word(char *str, char *s, int i)
{
	char	quote;
	int		j;

	quote = s[i];
	j = 0;
	i++;
	while (s[i] && s[i] != quote)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	i++;
	str[j] = '\0';
	return (i);
}

static int		save_word(char *str, char *s, char c, int i)
{
	int j;

	j = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if ((s[i] == '\"' || s[i] == '\'') && j == 0)
			return (save_quoted_word(str, s, i));
		if (s[i] == c)
		{
			str[j] = '\0';
			return (i);
		}
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (i);
}

char			**ft_comand_split(char *s, char c)
{
	int		j;
	char	**tab;
	int		i;
	int		max;

	if (s == NULL)
		return (NULL);
	i = ft_countwords2(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	tab[i] = NULL;
	max = i;
	i = 0;
	j = 0;
	while (j < max)
	{
		if (!(tab[j] = malloc(sizeof(char) * (size_nextword(s, c, i) + 1))))
			return (NULL);
		i = save_word(tab[j], s, c, i);
		j++;
	}
	return (tab);
}
