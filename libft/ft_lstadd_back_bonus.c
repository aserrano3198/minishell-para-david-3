/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:24:47 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/05 19:05:24 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *newitem)
{
	t_list *item;

	if (!*alst && newitem)
		*alst = newitem;
	else if (*alst && newitem)
	{
		item = *alst;
		while (item->next)
			item = item->next;
		item->next = newitem;
	}
}
