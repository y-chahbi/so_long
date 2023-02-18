/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:34:00 by ychahbi           #+#    #+#             */
/*   Updated: 2023/02/15 14:38:31 by ychahbi          ###   ########.fr       */
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
	if (keycode == 53 || keycode == 12)
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

void	in__pics(struct s_data *t_data, int *width, int *height)
{
	mlx_p(t_data, width, height);
	if (!t_data->img_exit || !t_data->img_exit_2
		|| !t_data->img_freespace || !t_data->img_coll
		|| !t_data->img_player || !t_data->img_player_2
		|| !t_data->img_wall)
	{
		ft_putstr("Mlx - Pics -> Error!");
		exit(1);
	}
}

void	mlx_put_t_data(struct s_data *t_data, int *width, int *height)
{
	t_data->mlx = mlx_init();
	if (!t_data->mlx)
	{
		ft_putstr("Mlx -> Error!");
		exit(1);
	}
	in__pics(t_data, width, height);
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
	if (!t_data->mlx_win)
	{
		ft_putstr("Error!");
		exit(1);
	}
	mlx_loop_hook(t_data->mlx, game_loop, t_data);
	mlx_hook(t_data->mlx_win, 02, 0, key_handler, t_data);
	mlx_hook(t_data->mlx_win, 17, 0, exit_game, t_data);
	mlx_loop(t_data->mlx);
	free(t_data);
}
