/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:27:29 by rzukale           #+#    #+#             */
/*   Updated: 2020/01/16 14:01:46 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(t_tetrices *tetrices)
{
	int			size;
	t_struct	*map;

	size = initial_map_size(number_of_tetrices(&tetrices) * 4);
	map = new_map(size, &tetrices);
	while (!(solve_map(map, tetrices)))
	{
		size++;
		free_map(map);
		map = new_map(size, &tetrices);
	}
	print_map(map);
	free_map(map);
}

int		solve_map(t_struct *map, t_tetrices *tetrices)
{
	int x;
	int y;

	if (tetrices == NULL)
		return (1);
	y = 0;
	while (y < (map->size - tetrices->height + 1))
	{
		x = 0;
		while (x < (map->size - tetrices->length + 1))
		{
			if (check_placement(tetrices, map, x, y))
			{
				if (solve_map(map, tetrices->next))
					return (1);
				else
				{
					place_tetris(tetrices, map, '.', setup_coordinates(x, y));
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		place_tetris(t_tetrices *tetris, t_struct *map, char letter,
		t_coords *coords)
{
	int		x;
	int		y;
	int		hashes;
	char	**tmp;

	hashes = 0;
	tmp = (char**)tetris->data;
	y = 0;
	while (y < tetris->height && hashes < 4)
	{
		x = 0;
		while (x < tetris->length + 1)
		{
			if (tmp[tetris->start + y][x + tetris->sk] == '#')
			{
				map->map[coords->y + y][coords->x + x] = letter;
				hashes++;
			}
			x++;
		}
		y++;
	}
	ft_memdel((void**)&coords);
	return (1);
}

int		check_placement(t_tetrices *tetris, t_struct *map, int x, int y)
{
	int		j;
	int		k;
	int		hashes;
	char	**tmp;

	hashes = 0;
	tmp = (char**)tetris->data;
	k = 0;
	while (k < tetris->height && hashes < 4)
	{
		j = 0;
		while (j < tetris->length + 1)
		{
			if (tmp[tetris->start + k][j + tetris->sk] == '#' &&
				map->map[y + k][x + j] != '.')
				return (0);
			if (tmp[tetris->start + k][j + tetris->sk] == '#' &&
				map->map[y + k][x + j] == '.')
				hashes++;
			j++;
		}
		k++;
	}
	return (place_tetris(tetris, map, tetris->c, setup_coordinates(x, y)));
}
