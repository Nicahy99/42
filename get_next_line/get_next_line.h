/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazblah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:47:41 by yazblah           #+#    #+#             */
/*   Updated: 2022/12/03 13:15:05 by yazblah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_char
{
	char			lettre;
	struct s_char	*next;
}	t_char;

typedef struct s_file
{
	int				fd;
	int				fin;
	int				cpt;
	int				cpt_total;
	struct s_char	*line;
	char			*line_char;
	char			buf[BUFFER_SIZE + 1];
	struct s_file	*next;
}	t_file;

void	*ft_calloc(size_t nmemb, size_t size);
t_char	*ft_char_new(char c);
t_file	*ft_file_new(int fd);
t_file	*ft_file_search(t_file *files, int fd);
char	*get_next_line(int fd);
#endif
