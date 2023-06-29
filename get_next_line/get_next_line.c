/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazblah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:47:34 by yazblah           #+#    #+#             */
/*   Updated: 2022/12/04 12:18:55 by yazblah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_char	*ft_char_last(t_char *ch)
{
	while (ch && ch->next)
		ch = ch->next;
	return (ch);
}

static	char	*ft_line(t_file *file, int cpt)
{
	char	*str;
	t_char	*ch;
	t_char	*tmp;
	int		i;

	if (!(file->line))
		return (NULL);
	str = ft_calloc(cpt + 1, sizeof(char));
	if (!str)
		return (NULL);
	ch = file->line;
	i = 0;
	while (i < cpt && ch)
	{
		str[i++] = ch->lettre;
		tmp = ch->next;
		free(ch);
		ch = tmp;
		if (str[i - 1] == '\n')
			cpt = -cpt;
	}
	file->line = ch;
	file->cpt_total = file->cpt_total - i;
	file->cpt = file->cpt - i;
	return (str);
}

static int	ft_read2(t_file *file, char *buf, int dif)
{
	int		i;
	int		test;
	t_char	*tmp;

	tmp = ft_char_last(file->line);
	i = -1;
	test = 1;
	while (buf[++i])
	{
		if (!(file->line))
			file->line = ft_char_new(buf[i]);
		if (!tmp)
			tmp = file->line;
		else
			tmp->next = ft_char_new(buf[i]);
		if (tmp->next)
			tmp = tmp->next;
		if (buf[i] != '\n' && dif == file->cpt_total - file->cpt)
			file->cpt++;
		if (buf[i] == '\n')
			test = -2;
		file->cpt_total++;
	}
	return (test);
}

static char	*ft_read(t_file *file, char *buf)
{
	int		nbr_read;
	int		dif;

	dif = file->cpt_total - file->cpt;
	nbr_read = 1;
	while (nbr_read > 0)
	{
		nbr_read = read(file->fd, buf, BUFFER_SIZE);
		buf[nbr_read] = '\0';
		if (nbr_read == -1)
			return (NULL);
		if (nbr_read > 0)
			nbr_read = ft_read2(file, buf, dif);
	}
	if (nbr_read == 0)
		file->fin = 1;
	if (dif != file->cpt_total - file->cpt)
		file->cpt++;
	return (ft_line(file, file->cpt_total));
}

char	*get_next_line(int fd)
{
	static t_file	*files;
	t_file			*tmp;
	char			*str;

	if (!files && fd >= 0)
		files = ft_file_new(fd);
	if (fd < 0 || BUFFER_SIZE <= 0 || !files)
		return (NULL);
	tmp = ft_file_search(files, fd);
	if (!tmp)
		return (NULL);
	str = ft_read(tmp, tmp->buf);
	while (files && !files->line)
	{
		tmp = files->next;
		free(files);
		files = tmp;
	}
	return (str);
}
/*
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(void)
{
	int 	fd;
	char	*str;
	fd = open("gnlTester/files/big_line_no_nl", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
    	printf("%s\n", str); 
    	free(str);
		str = get_next_line(fd);
	}
    close(fd);


    fd = open("gnlTester/files/big_line_with_nl", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
    	printf("%s\n", str); 
    	free(str);
		str = get_next_line(fd);
	}
    close(fd);

    fd = open("gnlTester/files/multiple_nlx5", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
    	printf("%s\n", str); 
    	free(str);
		str = get_next_line(fd);
	}
    close(fd);

    fd = open("gnlTester/files/multiple_line_no_nl", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
    	printf("%s\n", str); 
    	free(str);
		str = get_next_line(fd);
	}
    close(fd);

    fd = open("gnlTester/files/multiple_line_with_nl", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
    	printf("%s\n", str); 
    	free(str);
		str = get_next_line(fd);
	}
    close(fd);

    fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
    	printf("%s\n", str); 
    	free(str);
		str = get_next_line(fd);
	}
    close(fd);

    fd = open("gnlTester/files/alternate_line_nl_with_nl", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
    	printf("%s\n", str); 
    	free(str);
		str = get_next_line(fd);
	}
    close(fd);

    //fd = open("gnlTester/stdin", O_RDONLY);
    //    printf("%s\n", str);    
	//free(str);
    //close(fd);

    return (0);
}*/