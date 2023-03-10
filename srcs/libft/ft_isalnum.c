/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:10:16 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/06 14:04:44 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	int answer;

	answer = 1;
	if ((c < '0') || ((c > '9') && (c < 'A')))
	{
		answer = 0;
	}
	if (((c > 'Z') && (c < 'a')) || (c > 'z'))
	{
		answer = 0;
	}
	return (answer);
}
