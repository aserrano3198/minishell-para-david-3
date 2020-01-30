/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 09:17:34 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 17:15:02 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	first_num_mem(t_toprint *toprint, char *s, char *numf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (toprint->width > ft_strlen(s))
	{
		numf[i++] = '0';
		numf[i++] = 'x';
	}
	while (s[j])
		numf[i++] = s[j++];
	while (i < toprint->width)
		numf[i++] = ' ';
	numf[i] = '\0';
}

void	last_num_mem(t_toprint *toprint, char *s, char *numf)
{
	int i;
	int j;

	i = 0;
	while (i < (toprint->width - ft_strlen(s)))
	{
		if (toprint->flags[ZERO] == 1)
			numf[i] = '0';
		if (toprint->flags[ZERO] == 0)
			numf[i] = ' ';
		i++;
	}
	j = 0;
	while (i < toprint->width)
		numf[i++] = s[j++];
	numf[i] = '\0';
}

char	*width_bt_prec_mem(t_toprint *toprint, char *num)
{
	char *s;
	char *numf;

	numf = malloc(sizeof(char) * toprint->width + 1);
	if (num[0] == '-')
		s = neg_prec_bt_width(toprint, num);
	else
		s = pos_prec_bt_width(toprint, num);
	if (toprint->flags[MINUS] == 1)
		first_num_mem(toprint, s, numf);
	if (toprint->flags[MINUS] == 0)
		last_num_mem(toprint, s, numf);
	return (numf);
}

char	*memsw(t_toprint *toprint, char *num)
{
	char	*numf;

	if (toprint->precission >= toprint->width && num[0] == '-')
		numf = neg_prec_bt_width(toprint, num);
	else if (toprint->precission < toprint->width &&
			toprint->width > ft_strlen(num))
		numf = width_bt_prec_mem(toprint, num);
	else if (toprint->precission >= toprint->width && num[0] != '-')
		numf = pos_prec_bt_width(toprint, num);
	else
		numf = num;
	free(num);
	return (numf);
}
