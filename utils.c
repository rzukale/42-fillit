/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:44:03 by eparviai          #+#    #+#             */
/*   Updated: 2020/01/16 14:49:14 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		output_error(int error_nbr, t_tetrices **tetrices)
{
	free_list(tetrices);
	if (error_nbr == -1)
		ft_putstr("usage: fillit input_file\n");
	if (error_nbr == -2)
		ft_putstr("error\n");
	if (error_nbr == -3)
		ft_putstr("Malloc error\n");
	exit(-1);
}

void		check_eof(int fd, t_tetrices **tetrices)
{
	int			char_count;
	int			ret;
	char		buf[4086];

	char_count = 0;
	if ((ret = read(fd, buf, 4085)) > 0)
	{
		buf[ret] = '\0';
		while (buf[char_count] != '\0')
			char_count++;
		if (buf[char_count - 1] == '\n' && buf[char_count - 2] == '\n')
			output_error(-2, tetrices);
	}
}

void		free_list(t_tetrices **begin_list)
{
	t_tetrices *next;
	t_tetrices *list;

	list = *begin_list;
	if (list)
	{
		while (list)
		{
			next = list->next;
			free_array(list->data);
			ft_memdel((void**)&list);
			list = next;
		}
	}
	*begin_list = 0;
}

void		free_array(void **data)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_memdel((void**)&data[i]);
		i++;
	}
	ft_memdel((void**)&data);
}

t_coords	*setup_coordinates(int x, int y)
{
	t_coords *coords;

	coords = ft_memalloc(sizeof(t_coords));
	coords->x = x;
	coords->y = y;
	return (coords);
}
