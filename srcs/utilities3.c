/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:08:26 by aserrano          #+#    #+#             */
/*   Updated: 2020/02/14 13:44:32 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		initialize(int *quotes, int *i, char *quote, int *words)
{
	*i = 0;
	*quote = 0;
	*quotes = 0;
	*words = 0;
}

static int		pc_countwords(char *s, char c)
{
	int		i;
	int		words;
	int		quotes;
	char	quote;

	initialize(&quotes, &i, &quote, &words);
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		words++;
		while (s[i] && ((s[i] != c && !quotes) || quotes))
		{
			if ((s[i] == '\"' || s[i] == '\'') && !quotes && (quote = s[i]))
				quotes = 1;
			else if (quotes && s[i] == quote && !(quote = 0))
				quotes = 0;
			i++;
		}
	}
	return (words);
}

static int		pc_size_nextword(char *s, char c, int i)
{
	int		counter;
	int		quotes;
	char	quote;

	quotes = 0;
	quote = 0;
	while (s[i] == c && s[i])
		i++;
	counter = 0;
	while (s[i] && ((s[i] != c && !quotes) || quotes))
	{
		if (quotes && s[i] == quote && !(quote = 0))
			quotes = 0;
		else if ((s[i] == '\"' || s[i] == '\'') && !quotes && (quote = s[i]))
			quotes = 1;
		i++;
		counter++;
	}
	return (counter);
}

static int		pc_save_word(char *str, char *s, char c, int i)
{
	int		j;
	int		quotes;
	char	quote;

	quotes = 0;
	quote = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] && ((s[i] != c && !quotes) || quotes))
	{
		if (quotes && s[i] == quote && !(quote = 0))
			quotes = 0;
		else if ((s[i] == '\"' || s[i] == '\'') && !quotes && (quote = s[i]))
			quotes = 1;
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (i);
}

char			**ft_split_pc(char *s, char c)
{
	int		j;
	char	**tab;
	int		i;
	int		max;

	if (s == NULL)
		return (NULL);
	i = pc_countwords(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	tab[i] = NULL;
	max = i;
	i = 0;
	j = 0;
	while (j < max)
	{
		if (!(tab[j] = malloc(sizeof(char) * (pc_size_nextword(s, c, i) + 1))))
			return (NULL);
		i = pc_save_word(tab[j], s, c, i);
		j++;
	}
	return (tab);
}
