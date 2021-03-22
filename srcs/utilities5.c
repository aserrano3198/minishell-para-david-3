/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:03:31 by aserrano          #+#    #+#             */
/*   Updated: 2020/02/14 14:06:15 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				ft_jump_quotes(char *s, int i)
{
	if (s[i] == '\'' && ++i)
	{
		while (s[i] && s[i] != '\'')
			i++;
		i++;
	}
	else if (s[i] == '\"' && ++i)
	{
		while (s[i] && s[i] != '\"')
			i++;
		i++;
	}
	return (i);
}

int				ft_countwords2(char *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		words++;
		if (s[i] == '\'' || s[i] == '\"')
			i = ft_jump_quotes(s, i);
		else
			while (s[i] && s[i] != c && s[i] != '\"' && s[i] != '\'')
				i++;
	}
	return (words);
}
