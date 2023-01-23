/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:22:11 by inskim            #+#    #+#             */
/*   Updated: 2023/01/23 23:58:09 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_min(int nb, int fd)
{
	if (nb >= 0)
		return (0);
	write(fd, "-", 1);
	return (1);
}

static void	print(unsigned int u_nb, int fd)
{
	if (u_nb >= 10)
	{
		print(u_nb / 10, fd);
		u_nb = u_nb % 10;
	}
	u_nb = u_nb + 48;
	write(fd, &u_nb, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	u_nb;

	if (is_min(nb, fd) == 1)
		u_nb = -nb;
	else
		u_nb = nb;
	print(u_nb, fd);
}
