/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:39:28 by aserrano          #+#    #+#             */
/*   Updated: 2019/11/06 13:59:25 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	av;
	char			toprint;

	if (n < 0)
	{
		write(fd, "-", 1);
		av = n * (-1);
	}
	else
		av = n;
	if (av / 10 != 0)
		ft_putnbr_fd(av / 10, fd);
	toprint = (av % 10) + 48;
	write(fd, &toprint, 1);
}
