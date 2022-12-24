/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:41:53 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/24 19:01:24 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	if_shorts(struct s_data *t_data, int countt, int count)
{
	if (t_data->map_to_tab[countt][count] == 'P' &&
	t_data->player_side == 0)
		mlx_put_image_to_window(t_data->mlx, t_data->mlx_win,
			t_data->img_player, 96 * count, countt * 96);
	else if (t_data->map_to_tab[countt][count] == 'P')
		mlx_put_image_to_window(t_data->mlx, t_data->mlx_win,
			t_data->img_player_2, 96 * count, countt * 96);
	if (t_data->map_to_tab[countt][count] == 'E' && t_data->colloctive_s == 0)
		mlx_put_image_to_window(t_data->mlx, t_data->mlx_win,
			t_data->img_exit_2, 96 * count, countt * 96);
	else if (t_data->map_to_tab[countt][count] == 'E' &&
		t_data->colloctive_s != 0)
		mlx_put_image_to_window(t_data->mlx, t_data->mlx_win,
			t_data->img_exit, 96 * count, countt * 96);
	if (t_data->map_to_tab[countt][count] == 'C')
		mlx_put_image_to_window(t_data->mlx, t_data->mlx_win,
			t_data->img_coll, 96 * count, countt * 96);
}

static void	first_while(struct s_data *t_data, int count, int countt)
{
	while (t_data->map_to_tab[countt])
	{
		count = 0;
		while (t_data->map_to_tab[countt][count] != '\0')
		{
			if (t_data->map_to_tab[countt][count] == '1')
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win,
					t_data->img_wall, 96 * count, countt * 96);
			else
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win,
					t_data->img_freespace, 96 * count, countt * 96);
			count++;
		}
		countt++;
	}
}

int	game_loop(struct s_data *t_data)
{
	int		count;
	int		countt;

	countt = 0;
	first_while(t_data, count, countt);
	countt = 0;
	while (t_data->map_to_tab[countt])
	{
		count = 0;
		while (t_data->map_to_tab[countt][count] != '\0')
		{
			if_shorts(t_data, countt, count);
			count++;
		}
		countt++;
	}
	return (0);
}
