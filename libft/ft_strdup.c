/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazblah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:23:21 by yazblah           #+#    #+#             */
/*   Updated: 2022/11/18 13:08:34 by yazblah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		lens;

	lens = ft_strlen(s);
	str = ft_calloc(lens + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, lens + 1);
	return (str);
}
