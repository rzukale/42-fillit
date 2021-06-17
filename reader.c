/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 15:31:35 by rzukale           #+#    #+#             */
/*   Updated: 2020/01/16 14:55:59 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**validate_block(char *str, int ret)
{
	int	i;
	int point;
	int hash;

	hash = 0;
	i = 0;
	point = 0;
	while (str[i] == '.' || str[i] == '#' || str[i] == '\n' || str[i] != '\0')
	{
		if (str[i] == '\n' && !(((i + 1) % 5) == 0) && i < 20)
			return (NULL);
		if (str[i] == '.')
			point++;
		if (str[i] == '#')
			hash++;
		i++;
	}
	if (ret == 21)
		if (str[i - 1] != '\n' || hash != 4 || point != 12)
			return (NULL);
	if (ret == 20)
		if (str[i - 1] != '\n' || hash != 4 || point != 12 || str[i] != '\0')
			return (NULL);
	return (validate_tetrimino(str));
}

char		**validate_tetrimino(char *str)
{
	int connections;
	int	i;

	i = 0;
	connections = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i + 1 < 20 && str[i + 1] == '#')
				connections++;
			if (i - 1 >= 0 && str[i - 1] == '#')
				connections++;
			if (i + 5 < 20 && str[i + 5] == '#')
				connections++;
			if (i - 5 >= 0 && str[i - 5] == '#')
				connections++;
		}
		i++;
	}
	if (connections == 6 || connections == 8)
		return (fill_tetris(str));
	return (NULL);
}

char		**fill_tetris(char *str)
{
	char	**array;
	int		j;
	int		x;
	int		y;

	y = 0;
	j = 0;
	if (!(array = ft_memalloc(sizeof(char *) * 4)))
		return (NULL);
	while (y < 4)
	{
		x = 0;
		array[y] = ft_strnew(4);
		while (x < 4)
		{
			array[y][x] = str[j];
			x++;
			j++;
		}
		array[y][x] = '\0';
		j++;
		y++;
	}
	return (array);
}

t_tetrices	*read_file(int fd)
{
	char		buf[22];
	char		**tmp;
	t_tetrices	*tetrices;
	int			ret;
	char		c;

	c = 'A';
	tetrices = NULL;
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		if (ret < 20)
			output_error(-2, &tetrices);
		if ((tmp = validate_block(buf, ret)) == NULL)
			output_error(-2, &tetrices);
		ft_tetrices_push_back(&tetrices, (void**)tmp, c++);
	}
	if (number_of_tetrices(&tetrices) > 26)
		output_error(-2, &tetrices);
	return (tetrices);
}
