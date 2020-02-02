/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switchint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:23:56 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 17:14:59 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*neg_prec_bt_width(t_toprint *toprint, char *num)
{
	char	*s;
	int		i;
	int		j;

	if (toprint->precission > ft_strlen(num) - 1)
		s = malloc(sizeof(char) * (toprint->precission + 2));
	else
		s = malloc(sizeof(char) * (ft_strlen(num) + 1));
	i = 0;
	s[i++] = '-';
	while (toprint->precission-- >= ft_strlen(num))
		s[i++] = '0';
	j = 1;
	while (num[j])
		s[i++] = num[j++];
	s[i] = num[j];
	return (s);
}

char	*pos_prec_bt_width(t_toprint *toprint, char *num)
{
	char	*s;
	int		i;
	int		j;

	if (toprint->precission >= ft_strlen(num))
		s = malloc(sizeof(char) * (toprint->precission + 1));
	else
		s = malloc(sizeof(char) * (ft_strlen(num) + 1));
	i = 0;
	while (toprint->precission-- > ft_strlen(num))
		s[i++] = '0';
	j = 0;
	while (num[j])
		s[i++] = num[j++];
	s[i] = num[j];
	return (s);
}

void	first_num(t_toprint *toprint, char *s, char *numf)
{
	int i;

	i = 0;
	while (s[i])
	{
		numf[i] = s[i];
		i++;
	}
	while (i < toprint->width)
		numf[i++] = ' ';
	numf[i] = '\0';
}

void	last_num(t_toprint *toprint, char *s, char *numf)
{
	int i;
	int j;
	int max;

	max = toprint->width - ft_strlen(s);
	i = 0;
	j = 0;
	if (s[j] == '-' && toprint->flags[ZERO] == 1 && (j = j + 1))
	{
		max++;
		numf[i++] = '-';
	}
	while (i < max)
	{
		if (toprint->flags[ZERO] == 1)
			numf[i] = '0';
		if (toprint->flags[ZERO] == 0)
			numf[i] = ' ';
		i++;
	}
	while (i < toprint->width)
		numf[i++] = s[j++];
	numf[i] = '\0';
}

char	*width_bt_prec(t_toprint *toprint, char *num)
{
	char *s;
	char *numf;

	numf = malloc(sizeof(char) * toprint->width + 1);
	if (num[0] == '-')
		s = neg_prec_bt_width(toprint, num);
	else
		s = pos_prec_bt_width(toprint, num);
	if (toprint->flags[MINUS] == 1)
		first_num(toprint, s, numf);
	if (toprint->flags[MINUS] == 0)
		last_num(toprint, s, numf);
	return (numf);
}
