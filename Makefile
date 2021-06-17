# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 13:22:02 by rzukale           #+#    #+#              #
#    Updated: 2020/01/16 15:27:39 by rzukale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fillit
FLAGS =	-Wall -Wextra -Werror
SCRS =	main.c solver.c map.c reader.c tetris.c utils.c list.c
INCLUDES =	Libft/includes/
LIBFT =	Libft/
all:	$(NAME)
$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SCRS) -I $(INCLUDES) -L. Libft/libft.a
clean:
	make -C $(LIBFT) clean
fclean: clean
	make -C $(LIBFT) fclean
	rm -rf $(NAME)
re: fclean all
PHONY: all clean fclean re
precious: author