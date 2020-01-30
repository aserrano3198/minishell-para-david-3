/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_toprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:11:07 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 17:15:09 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reset_toprint(t_toprint *toprint)
{
	int j;

	j = 0;
	toprint->mayus = 0;
	toprint->memory = 0;
	toprint->hex_i = 0;
	toprint->percent = 0;
	toprint->width = 0;
	toprint->zerostr = 0;
	toprint->precission = 0;
	toprint->ischar = 0;
	toprint->unsig = 0;
	toprint->precissioncpy = 0;
	toprint->flagi = 0;
	toprint->nullmemo = 0;
	toprint->precission_setted = 0;
	while (j < 4)
		toprint->flags[j++] = 0;
}
