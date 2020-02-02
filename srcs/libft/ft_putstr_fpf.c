/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fpf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:10:17 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 17:15:10 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fpf(char *s, t_toprint *toprint)
{
	int i;

	if (s == NULL)
		return ;
	i = -1;
	while (s[++i])
	{
		write(1, &s[i], 1);
		toprint->counter++;
	}
}
