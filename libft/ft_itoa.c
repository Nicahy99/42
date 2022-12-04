/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazblah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:24:44 by yazblah           #+#    #+#             */
/*   Updated: 2022/11/18 14:41:40 by yazblah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*static long int	ft_itoapostif(int n)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
		nbr = nbr * (-1);
	return (nbr);
}

static int	ft_itoalen(int n)
{
	long int	i;

	i = 1;
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*ft_itoaalloc(int n, int len)
{
	char		*str;

	if (n < 0)
	{
		str = malloc((len + 1 + 1) * sizeof(char));
		str[0] = '-';
		str[len + 1] = '\0';
	}
	else
	{
		str = malloc((len + 1) * sizeof(char));
		str[len] = '\0';
		if (n == 0)
			str[0] = '0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nbrp;
	long int	nbr;
	int			len;

	nbr = n;
	nbrp = ft_itoapostif(nbr);
	len = ft_itoalen(nbrp);
	str = ft_itoaalloc(nbr, len);
	if (!str)
		return (NULL);
	if (nbr >= 0)
		len--;
	while (nbrp > 0)
	{
		str[len] = nbrp % 10 + '0';
		nbrp = nbrp / 10;
		len--;
	}
	return (str);
}*/

static long int	ft_abs(int nbr)
{
	long int	n;

	n = nbr;
	if (n < 0)
		return (-n);
	return (n);
}

static void	ft_strrev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
}

static int	ft_itoalength(long int n)
{
	int			length;
	long int	tmp;

	tmp = 0;
	length = 0;
	while (tmp < n)
	{
		tmp = tmp * 10 + 9;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			is_neg;
	int			length;

	is_neg = (n < 0);
	length = ft_itoalength(ft_abs(n));
	if (n == 0)
		return (ft_strdup("0"));
	str = ft_calloc(length + is_neg + 1, sizeof(*str));
	if (!str)
		return (NULL);
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (is_neg)
		str[length] = '-';
	ft_strrev(str);
	return (str);
}
