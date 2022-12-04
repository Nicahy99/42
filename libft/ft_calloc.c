/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazblah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:03:33 by yazblah           #+#    #+#             */
/*   Updated: 2022/11/18 13:04:36 by yazblah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	tmp;

	tmp = -1;
	if (!nmemb || !size)
		return (ft_calloc(1, 1));
	if (size == 0 || tmp / size < nmemb)
		return (NULL);
	s = (unsigned char *)malloc(nmemb * size);
	if (!(unsigned char *)s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}
