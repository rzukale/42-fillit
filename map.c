/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:29:39 by rzukale           #+#    #+#             */
/*   Updated: 2020/01/16 14:48:53 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_map(t_struct *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void**)&(map->map[i]));
		i++;
	}
	ft_memdel((void**)&(map->map));
	ft_memdel((void**)&map);
}

t_struct	*new_map(int size, t_tetrices **tetrices)
{
	int			i;
	int			j;
	t_struct	*map;

	i = 0;
	if (!(map = (t_struct*)malloc(sizeof(t_struct))))
		output_error(-3, tetrices);
	map->size = size;
	if (!(map->map = (char **)malloc(sizeof(char *) * size)))
		output_error(-3, tetrices);
	while (i < size)
	{
		if (!(map->map[i] = ft_strnew(size)))
			output_error(-3, tetrices);
		j = 0;
		while (j < size)
		{
			map->map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int			initial_map_size(int n)
{
	int i;

	i = 2;
	while ((i * i) < n)
		i++;
	return (i);
}

void		print_map(t_struct *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->map[i]);
		ft_putchar('\n');
		i++;
	}
}
