/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:44:03 by eparviai          #+#    #+#             */
/*   Updated: 2020/01/16 14:02:35 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			find_hash_line(char **array)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (array[y][x])
		{
			if (array[y][x] == '#')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int			find_height_max(char **str)
{
	int x;
	int y;
	int hashes;

	hashes = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (str[y][x])
		{
			if (str[y][x] == '#')
				hashes++;
			if (hashes == 4)
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int			find_tetri_height(char **str)
{
	return (find_height_max(str) - find_hash_line(str) + 1);
}

int			find_tetri_length(void **data)
{
	int		length;
	int		temp;
	int		x;
	int		y;
	char	**tmp;

	tmp = (char**)data;
	y = 0;
	temp = 0;
	length = 0;
	while (y < 4)
	{
		x = 0;
		while (tmp[y][x])
		{
			if (tmp[y][x] == '#')
				temp++;
			x++;
		}
		if (temp > length)
			length = temp;
		temp = 0;
		y++;
	}
	return (length);
}

int			skip_amount(char **line)
{
	int x;
	int y;
	int	min;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (line[y][x] != '#' && line[y][x])
			x++;
		if (y == 0)
			min = x;
		else if (x < min)
			min = x;
		y++;
	}
	return (min);
}
