/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:01:35 by ychahbi           #+#    #+#             */
/*   Updated: 2023/02/18 16:42:05 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "get_next_line.h"

struct s_data{
	void	*mlx;
	void	*mlx_win;
	void	*img_exit;
	void	*img_exit_2;
	void	*img_coll;
	void	*img_freespace;
	void	*img_player;
	void	*img_player_2;
	void	*img_wall;
	char	**map_to_tab;
	int		count;
	int		colloctive_s;
	int		map_width;
	int		map_height;
	int		player_side;
	char	*map_path;
} ;

int		cheack_map(char *s, struct s_data *t_data);
void	ft_putstr(char *s);
int		cheak_map_path(char *s);
int		str_len(char *str);
void	*ft_strcpy(char *dst, char *src);
void	show_the_window(struct s_data *t_data);
void	move_to_right(struct s_data *t_data);
void	move_to_left(struct s_data *t_data);
void	move_to_top(struct s_data *t_data);
void	move_to_bottom(struct s_data *t_data);
char	*ft_strjoi(char *s1, char *s2);
char	**map_to_table(struct s_data *t_data);
char	**ft_split(char *s, char c);
void	ft_printnbr(int n);
int		game_loop(struct s_data *t_data);
int		backtracking(struct s_data *t_data);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		check___ones(char *s);
void	iniit(struct s_data *t_data, char *s, int *fd);
int		cheak_open(char *s);
int		while___(char *first_line, char *last_line, int i);
void	mlx_p(struct s_data *t_data, int *width, int *height);
void	my_last_line_last_check(struct s_data *t_data, int count, int len_size);
#endif