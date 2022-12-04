/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazblah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:40:54 by yazblah           #+#    #+#             */
/*   Updated: 2022/11/18 14:36:16 by yazblah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tempo;

	tempo = malloc(1 * sizeof(t_list));
	if (!tempo)
		return (NULL);
	tempo->content = content;
	tempo->next = NULL;
	return (tempo);
}
