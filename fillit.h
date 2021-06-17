/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:48:19 by eparviai          #+#    #+#             */
/*   Updated: 2020/01/16 13:53:55 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "Libft/includes/libft.h"
# include <fcntl.h>

typedef struct			s_coords
{
	int			x;
	int			y;
}						t_coords;

typedef struct			s_struct
{
	char	**map;
	int		size;
}						t_struct;

typedef struct			s_tetrices
{
	struct s_tetrices	*next;
	void				*data;
	char				c;
	int					length;
	int					height;
	int					start;
	int					sk;
}						t_tetrices;

void					output_error(int error_nbr, t_tetrices **tetrices);
t_tetrices				*read_file(int fd);
char					**fill_tetris(char *str);
int						find_tetri_length(void **data);
int						find_tetri_height(char **str);
int						find_hash_line(char **array);
char					**validate_tetrimino(char *str);
char					**validate_block(char *str, int ret);
void					print_map(t_struct *map);
int						initial_map_size(int n);
t_struct				*new_map(int size, t_tetrices **tetrices);
void					free_map(t_struct *map);
int						number_of_tetrices(t_tetrices **tetrices);
void					ft_tetrices_push_back(t_tetrices **begin_list,
						void **data, char c);
t_tetrices				*ft_create_elem(void **data, char c);
void					free_array(void **data);
void					free_list(t_tetrices **begin_list);
int						check_placement(t_tetrices *tetris, t_struct *map,
						int x, int y);
int						place_tetris(t_tetrices *tetris, t_struct *map,
						char letter, t_coords *coords);
int						skip_amount(char **line);
char					*hash_coords(char *line, int amount);
int						solve_map(t_struct *map, t_tetrices *tetrices);
t_coords				*setup_coordinates(int x, int y);
void					solve(t_tetrices *tetrices);
void					check_eof(int fd, t_tetrices **tetrices);

#endif
