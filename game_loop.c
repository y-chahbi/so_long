/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:41:53 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/22 16:34:47 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int game_loop(struct s_data *t_data)
{
	int		count;
	int		countt;
	countt = 0;
	count = 0;
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
	countt = 0;
	while(t_data->map_to_tab[countt])
	{
		count = 0;
		while(t_data->map_to_tab[countt][count] != '\0')
		{
			if(t_data->map_to_tab[countt][count] == 'P' && t_data->player_side == 0)
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->img_player, 96 * count, countt * 96);
			else if(t_data->map_to_tab[countt][count] == 'P')
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->img_player_2, 96 * count, countt * 96);
			if(t_data->map_to_tab[countt][count] == 'E' && t_data->colloctive_s == 0)
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->img_exit_2, 96 * count, countt * 96);
			else if(t_data->map_to_tab[countt][count] == 'E' && t_data->colloctive_s != 0)
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->img_exit, 96 * count, countt * 96);
			if(t_data->map_to_tab[countt][count] == 'C')
				mlx_put_image_to_window(t_data->mlx, t_data->mlx_win, t_data->img_coll, 96 * count, countt * 96);
			count++;
		}
		countt++;
    }
	return 0;
}