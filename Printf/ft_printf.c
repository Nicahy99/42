/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazblah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:16:30 by yazblah           #+#    #+#             */
/*   Updated: 2022/11/30 14:29:11 by yazblah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(unsigned char c, int *cpt)
{
	write(1, &c, 1);
	*cpt = *cpt + 1;
}

void	ft_putstr(char *str, int *cpt)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++], cpt);
}

void	ft_put_sp_int(char c, long int nbr, int *i, int *cpt)
{
	if (c == 'p')
	{
		if (nbr == 0)
			ft_putstr("(nil)", cpt);
		else
		{
			ft_putstr("0x", cpt);
			ft_putnbr_base_u(nbr, "0123456789abcdef", 16, cpt);
		}
	}
	else if (c == 'i' || c == 'd')
		ft_putnbr_base((int)nbr, "0123456789", 10, cpt);
	else if (c == 'u')
		ft_putnbr_base((unsigned int)nbr, "0123456789", 10, cpt);
	else if (c == 'x')
		ft_putnbr_base((unsigned int)nbr, "0123456789abcdef", 16, cpt);
	else if (c == 'X')
		ft_putnbr_base((unsigned int)nbr, "0123456789ABCDEF", 16, cpt);
	(*i) = (*i) + 1;
}

void	ft_put_special_string(char *str, int *i, int *cpt)
{
	int			j;
	const char	*s = "(null)";

	j = -1;
	if (!str)
		str = (char *)s;
	while (str[++j])
		ft_putchar((unsigned char)str[j], cpt);
	*i = *i + 1;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		cpt;
	va_list	args;

	va_start(args, str);
	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'c' && ++i)
			ft_putchar((unsigned char) va_arg(args, int), &cpt);
		else if (str[i] == '%' && str[i + 1] == 's')
			ft_put_special_string(va_arg(args, char *), &i, &cpt);
		else if (str[i] == '%' && (str[i + 1] == 'p' || str[i + 1] == 'i' || \
		str[i + 1] == 'd' || str[i + 1] == 'u' || str[i + 1] == 'x' || \
		str[i + 1] == 'X'))
			ft_put_sp_int(str[i + 1], va_arg(args, long long int), &i, &cpt);
		else if (str[i] == '%' && str[i + 1] == '%')
			ft_putchar(str[i++], &cpt);
		else
			ft_putchar(str[i], &cpt);
		i++;
	}
	va_end(args);
	return (cpt);
}

/*int main() 
{
  int a = 255;
  int *b;
  float c = 10.5;
	 unsigned long long int i3 = -1;
  
  b = &a;
  //ft_printf("%s%c%s\n", "Hello", ' ', "world");
  //printf("adrese = %p\n", b);
  //ft_printf("adrese = %p\n", b);
  //ft_printf("d = %d\ni = %i\nu = %u\nx = %x\nX =%X\n", c, a, a, a, a);
	//ft_printf(" NULL %p NULL ", NULL);
	ft_printf(" %i", -1);
  return 0;
}*/
