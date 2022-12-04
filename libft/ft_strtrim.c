/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazblah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:40:58 by yazblah           #+#    #+#             */
/*   Updated: 2022/11/18 13:43:57 by yazblah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_strtrim_debut(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	cpt;

	i = 0;
	cpt = 0;
	while (s1[i] && i == cpt)
	{
		j = 0;
		while (set[j] && set[j] != s1[i])
			j++;
		if (set[j] == s1[i] && set[j] != '\0')
			cpt++;
		i++;
	}
	return (cpt);
}

static int	ft_strtrim_fin(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	cpt;

	i = ft_strlen(s1) - 1;
	cpt = i + 1;
	while (s1[i] && i + 1 == cpt)
	{
		j = 0;
		while (set[j] && set[j] != s1[i])
			j++;
		if (set[j] == s1[i] && set[j] != '\0')
			cpt--;
		i--;
	}
	return (cpt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	start = ft_strtrim_debut(s1, set);
	end = ft_strtrim_fin(s1, set);
	if (end < start)
		return (ft_strdup(""));
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = start;
	while ((i - start) < (end - start))
	{
		str[i - start] = s1[i];
		i++;
	}
	str[i - start] = '\0';
	return (str);
}
