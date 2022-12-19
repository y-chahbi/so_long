/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:34:00 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/18 19:59:26 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, struct s_data *t_data)
{
	
	if (keycode == 2 || keycode == 124) {
		move_to_right(t_data);
	}
	if (keycode == 0 || keycode == 123) {
		move_to_left(t_data);
	}
	if (keycode == 13 || keycode == 126) {
		move_to_top(t_data);
	}	
	if (keycode == 1 || keycode == 125) {
		move_to_bottom(t_data);
	}
	return (0);
}

int game_loop(struct s_data *t_data)
{
	int		count;
	int		countt;
	countt = 0;
	count = 0;
	mlx_clear_window(t_data->mlx, t_data->mlx_win);
	while(t_data->map_to_tab[countt])
    {
		count = 0;
		while(t_data->map_to_tab[countt][count] != '\n')
		{
			if(t_data->map_to_tab[countt][count] == '1')
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->img_wall, 96 * count, countt * 96);
			else
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->img_freespace, 96 * count, countt * 96);
			count++;
		}
		countt++;
    }
	countt = 0;
	while(t_data->map_to_tab[countt])
    {
		count = 0;
		while(t_data->map_to_tab[countt][count])
		{
			if(t_data->map_to_tab[countt][count] == 'P')
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->img_player, 96 * count, countt * 96);
			if(t_data->map_to_tab[countt][count] == 'E')
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->img_exit, 96 * count, countt * 96);
			if(t_data->map_to_tab[countt][count] == 'C')
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->img_coll, 96 * count, countt * 96);
			count++;
		}
		countt++;
    }
	return 0;
}

void show_the_window()
{
	int		count;
	int		countt;
	int		coll;
	int		linee;
	char 	*last_line;
	int 	height;
	int 	width;
	struct s_data *t_data = malloc(sizeof(struct s_data));
	t_data->map_to_tab = map_to_table();
	check_map_lines(&coll, &linee);
	t_data->mlx = mlx_init();
	t_data->mlx_win = mlx_new_window(t_data->mlx, (linee - 1)*96, coll*96, "So Long");
	t_data->img_exit = mlx_xpm_file_to_image(t_data->mlx, "pics/exit.xmp", &width, &height);
	t_data->img_freespace = mlx_xpm_file_to_image(t_data->mlx, "pics/freespace.xmp", &width, &height);
	t_data->img_player = mlx_xpm_file_to_image(t_data->mlx, "pics/player.xmp", &width, &height);
	t_data->img_wall = mlx_xpm_file_to_image(t_data->mlx, "pics/wall.xmp", &width, &height);
	t_data->img_coll = mlx_xpm_file_to_image(t_data->mlx, "pics/coll.xmp", &width, &height);
	mlx_key_hook(t_data->mlx_win, key_handler, t_data);
	mlx_loop_hook(t_data->mlx, game_loop, t_data);
	mlx_loop(t_data->mlx);
}