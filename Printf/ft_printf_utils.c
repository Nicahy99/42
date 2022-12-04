/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazblah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:29:38 by yazblah           #+#    #+#             */
/*   Updated: 2022/11/30 14:29:43 by yazblah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long long int nbr, char *base, int lenBase, int *cpt)
{
	long long int	nb;

	nb = nbr;
	if (lenBase > 1)
	{
		if (nb < 0)
		{
			ft_putchar('-', cpt);
			nb = nb * (-1);
		}
		if (nb < (long long int)lenBase)
		{
			ft_putchar(base[nb], cpt);
		}
		else
		{
			ft_putnbr_base(nb / lenBase, base, lenBase, cpt);
			ft_putnbr_base(nb % lenBase, base, lenBase, cpt);
		}
	}
}

void	ft_putnbr_base_u(unsigned long int nbr, char *base, \
	int lenBase, int *cpt)
{
	unsigned long int	nb;

	nb = nbr;
	if (lenBase > 1)
	{
		if (nb < (unsigned long long int)lenBase)
		{
			ft_putchar(base[nb], cpt);
		}
		else
		{
			ft_putnbr_base(nb / lenBase, base, lenBase, cpt);
			ft_putnbr_base(nb % lenBase, base, lenBase, cpt);
		}
	}
}
