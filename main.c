/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:32:13 by eparviai          #+#    #+#             */
/*   Updated: 2020/01/16 15:04:24 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char **argv)
{
	int			fd;
	t_tetrices	*tetrices;

	tetrices = NULL;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) > 0)
		{
			check_eof(fd, &tetrices);
			close(fd);
			if (!((fd = open(argv[1], O_RDONLY)) > 0))
				output_error(-2, &tetrices);
			if ((tetrices = read_file(fd)) != NULL)
				solve(tetrices);
			else
				output_error(-2, &tetrices);
			close(fd);
			free_list(&tetrices);
		}
		else
			output_error(-2, &tetrices);
	}
	else
		output_error(-1, &tetrices);
	return (1);
}
