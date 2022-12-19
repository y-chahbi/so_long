/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:01:35 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/18 19:40:06 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include "get_next_line.h"

struct s_data{
	void	*mlx;
	void	*mlx_win;
	void 	*img_exit;
	void 	*img_coll;
	void 	*img_freespace;
	void 	*img_player;
	void 	*img_wall;
	char	**map_to_tab;
    int     count;
};

int cheack_map();

void ft_putstr(char *s);

int cheak_map_path(char *s);

int str_len(char *str);

void	*ft_strcpy(char *dst, char *src);

void show_the_window();

void    check_map_lines(int *coll, int *linee);

void    move_to_right(struct s_data *t_data);

void    move_to_left(struct s_data *t_data);

void    move_to_top(struct s_data *t_data);

void    move_to_bottom(struct s_data *t_data);

char	*ft_strjoi(char const *s1, char const *s2);

char **map_to_table();

char	**ft_split(char const *s, char c);

void	ft_printnbr(int n);



#endif