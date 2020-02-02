/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:39:03 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 17:33:27 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	first_str(t_toprint *toprint, char *s, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	while (i < toprint->width)
		s[i++] = ' ';
	s[i] = '\0';
}

void	last_str(t_toprint *toprint, char *s, char *str)
{
	int i;
	int j;

	i = 0;
	while (i < (toprint->width - ft_strlen(str)))
	{
		if (toprint->flags[ZERO] == 1 || toprint->zerostr == 1)
			s[i] = '0';
		else
			s[i] = ' ';
		i++;
	}
	j = 0;
	while (i < toprint->width)
		s[i++] = str[j++];
	s[i] = '\0';
}

char	*finalstr(t_toprint *toprint, char *str)
{
	char *s;
	char *str2;

	if (toprint->precission_setted == 1 &&
			toprint->ischar == 0 && toprint->nullmemo == 0)
		str2 = ft_substr(str, 0, toprint->precission);
	else
		str2 = str;
	if (toprint->width >= ft_strlen(str2))
		s = malloc(sizeof(char) * (toprint->width + 1));
	else
	{
		s = malloc(sizeof(char) * (ft_strlen(str2) + 1));
		if (toprint->precission_setted == 1 &&
				toprint->ischar == 0 && toprint->nullmemo == 0)
			s = ft_substr(str, 0, toprint->precission);
		else
			s = ft_substr(str, 0, ft_strlen(str));
		return (s);
	}
	if (toprint->flags[MINUS] == 1)
		first_str(toprint, s, str2);
	if (toprint->flags[MINUS] == 0)
		last_str(toprint, s, str2);
	return (s);
}

char	*null_memostr(t_toprint *toprint)
{
	char	*str;
	int		i;

	i = 2;
	if (toprint->precission_setted == 1)
	{
		str = malloc(sizeof(char) * (3 + toprint->precission));
		str[0] = '0';
		str[1] = 'x';
		while (i < toprint->precission + 2)
			str[i++] = '0';
		str[i] = '\0';
	}
	else
		str = "0x0";
	return (str);
}

int		print_str(t_toprint *toprint)
{
	char	*str;
	char	*final;
	int		i;

	i = 0;
	if (toprint->nullmemo == 1)
		str = null_memostr(toprint);
	else
		str = va_arg(toprint->args, char *);
	if (str == NULL)
		str = "(null)";
	if (toprint->precission_setted || toprint->width)
	{
		final = finalstr(toprint, str);
		ft_putstr_fpf(final, toprint);
	}
	else
		ft_putstr_fpf(str, toprint);
	return (1);
}
