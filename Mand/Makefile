# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 16:47:33 by ychahbi           #+#    #+#              #
#    Updated: 2022/12/28 19:28:39 by ychahbi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror 


MY_FILES = backtracking_the_game.c cheack_map.c cheak_map_path.c ft_split.c  game_loop.c  get_next_line_utils.c move_to_bottom.c  move_to_top.c so_long.c move_to_left.c ft_printnbr.c ft_strcpy.c get_next_line.c map_to_table.c ft_putstr.c ft_strjoin.c move_to_right.c show_window.c str_len.c

OBJECT = $(MY_FILES:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC)  $(CFLAGS) $^ -o $(NAME)

%.o: %.c so_long.h
	cc $< -c -o $@ $(CFLAGS)

clean:
	rm -f $(OBJECT) 

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : fclean all re clean