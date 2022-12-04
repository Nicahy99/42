/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazblah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:34:44 by yazblah           #+#    #+#             */
/*   Updated: 2022/11/10 13:38:09 by yazblah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		ft_putchar_fd('-', fd);
	}
	if (nbr < 10)
	{
		nbr = nbr + '0';
		ft_putchar_fd(nbr, fd);
	}
	else
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
}
