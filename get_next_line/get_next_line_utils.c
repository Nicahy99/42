/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazblah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:47:56 by yazblah           #+#    #+#             */
/*   Updated: 2022/12/03 14:46:59 by yazblah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;

	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}

t_char	*ft_char_new(char c)
{
	t_char	*ch;

	ch = ft_calloc(1, sizeof(t_char));
	if (!ch)
		return (NULL);
	ch->lettre = c;
	return (ch);
}

t_file	*ft_file_new(int fd)
{
	t_file	*file;

	file = ft_calloc(1, sizeof(t_file));
	if (!file)
		return (NULL);
	file->fd = fd;
	file->cpt = 0;
	file->cpt_total = 0;
	file->fin = 0;
	return (file);
}

t_file	*ft_file_search(t_file *files, int fd)
{
	while (files->next)
	{
		if (files->fd == fd)
			return (files);
		files = files->next;
	}
	if (files->fd == fd)
		return (files);
	files->next = ft_file_new(fd);
	return (files->next);
}
