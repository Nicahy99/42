/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazblah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:50:53 by yazblah           #+#    #+#             */
/*   Updated: 2022/11/30 14:29:23 by yazblah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(unsigned char c, int *cpt);
void	ft_putnbr_base(long long int nbr, char *base, int lenBase, int *cpt);
void	ft_putnbr_base_u(unsigned long int nbr, char *base, \
	int lenBase, int *cpt);
#endif
