/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:39:37 by rzukale           #+#    #+#             */
/*   Updated: 2020/01/16 13:54:21 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrices	*ft_create_elem(void **data, char c)
{
	t_tetrices	*list;

	list = NULL;
	list = (t_tetrices*)malloc(sizeof(t_tetrices));
	if (list)
	{
		list->data = data;
		list->next = NULL;
		list->c = c;
		list->length = find_tetri_length(data);
		list->height = find_tetri_height((char**)data);
		list->start = find_hash_line((char**)data);
		list->sk = skip_amount((char**)data);
	}
	return (list);
}

void		ft_tetrices_push_back(t_tetrices **begin_list, void **data, char c)
{
	t_tetrices *push;
	t_tetrices *list;

	push = *begin_list;
	if (push != NULL)
	{
		while (push->next != NULL)
		{
			push = push->next;
		}
		if ((list = ft_create_elem(data, c)))
		{
			push->next = list;
		}
	}
	else
	{
		*begin_list = ft_create_elem(data, c);
	}
}

int			number_of_tetrices(t_tetrices **tetrices)
{
	t_tetrices	*tmp;
	int			i;

	i = 0;
	tmp = *tetrices;
	if (tmp)
	{
		while (tmp)
		{
			i++;
			tmp = tmp->next;
		}
		return (i);
	}
	return (-1);
}
