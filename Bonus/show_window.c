/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:34:00 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/28 19:32:49 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, struct s_data *t_data)
{
	if (keycode == 2 || keycode == 124)
		move_to_right(t_data);
	if (keycode == 0 || keycode == 123)
		move_to_left(t_data);
	if (keycode == 13 || keycode == 126)
		move_to_top(t_data);
	if (keycode == 1 || keycode == 125)
		move_to_bottom(t_data);
	if (t_data->colloctive_s == 0)
		game_loop(t_data);
	if (keycode == 53)
		exit (1);
	return (0);
}

int	exit_game(struct s_data *t_data)
{
	int	i;

	i = 0;
	while (t_data->map_to_tab[i])
	{
		free(t_data->map_to_tab[i]);
		i++;
	}
	free(t_data->map_to_tab);
	exit (0);
	return (0);
}

static void	mlx_put_t_data(struct s_data *t_data, int *width, int *height)
{
	t_data->mlx = mlx_init();
	t_data->img_exit = mlx_xpm_file_to_image(
			t_data->mlx, "pics/exit.xmp", width, height);
	t_data->img_exit_2 = mlx_xpm_file_to_image(
			t_data->mlx, "pics/exit_2.xmp", width, height);
	t_data->img_freespace = mlx_xpm_file_to_image(
			t_data->mlx, "pics/freespace.xmp", width, height);
	t_data->img_player = mlx_xpm_file_to_image(
			t_data->mlx, "pics/player.xmp", width, height);
	t_data->img_player_2 = mlx_xpm_file_to_image(
			t_data->mlx, "pics/player_2.xmp", width, height);
	t_data->img_wall = mlx_xpm_file_to_image(
			t_data->mlx, "pics/wall.xmp", width, height);
	t_data->img_coll = mlx_xpm_file_to_image(
			t_data->mlx, "pics/coll.xmp", width, height);
	t_data->img_enm = mlx_xpm_file_to_image(
			t_data->mlx, "pics/enm.xmp", width, height);
	t_data->img_enm_rev = mlx_xpm_file_to_image(
			t_data->mlx, "pics/enm_rev.xmp", width, height);
}

void	show_the_window(struct s_data *t_data)
{
	int	height;
	int	width;

	t_data->count = 0;
	mlx_put_t_data(t_data, &width, &height);
	t_data->mlx_win = mlx_new_window(
			t_data->mlx, t_data->map_width * 96,
			t_data->map_height * 96, "So Long");
	mlx_loop_hook(t_data->mlx, game_loop, t_data);
	mlx_hook(t_data->mlx_win, 02, 0, key_handler, t_data);
	mlx_hook(t_data->mlx_win, 17, 0, exit_game, t_data);
	mlx_loop(t_data->mlx);
}
