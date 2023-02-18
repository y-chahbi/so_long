/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:41:53 by ychahbi           #+#    #+#             */
/*   Updated: 2023/02/18 18:34:55 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_moves(struct s_data *t_data, int countt, int count)
{
	if (t_data->enm_side == 0)
	{
		if (t_data->map_to_tab[countt][count - 1] == '0')
		{
			t_data->map_to_tab[countt][count - 1] = 'I';
			t_data->map_to_tab[countt][count] = '0';
		}
		else
			t_data->enm_side = 1;
		if (t_data->map_to_tab[countt][count - 1] == 'P')
			put_youlose(t_data);
	}
	if (t_data->enm_side == 1)
	{
		if (t_data->map_to_tab[countt][count + 1] == '0')
		{
			t_data->map_to_tab[countt][count + 1] = 'I';
			t_data->map_to_tab[countt][count] = '0';
		}
		else
			t_data->enm_side = 0;
		if (t_data->map_to_tab[countt][count + 1] == 'P')
			put_youlose(t_data);
	}
}

void	if_part_2(struct s_data *t_data, int countt, int count, int cc)
{
	static int		c;

	if (c > 100)
		c = 0;
	if (t_data->map_to_tab[countt][count] == 'C')
		mlx_put_image_to_window(t_data->mlx, t_data->mlx_win,
			t_data->img_coll, 96 * count, countt * 96);
	if (t_data->map_to_tab[countt][count] == 'I' && cc <= 250)
		mlx_put_image_to_window(t_data->mlx, t_data->mlx_win,
			t_data->img_enm, 96 * count, countt * 96);
	if (t_data->map_to_tab[countt][count] == 'I' && c == 10)
		enemy_moves(t_data, countt, count);
	if (t_data->map_to_tab[countt][count] == 'I' && cc > 250)
		mlx_put_image_to_window(t_data->mlx, t_data->mlx_win,
			t_data->img_enm_rev, 96 * count, countt * 96);
	c++;
}

void	if_shorts(struct s_data *t_data, int countt, int count, int cc)
{
	char	*reload;

	reload = ft_itoa(t_data->count);
	mlx_string_put(t_data->mlx, t_data->mlx_win, 44,
		44, 6420079, reload);
	if (t_data->map_to_tab[countt][count] == 'P' && t_data->player_side == 0)
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
	if_part_2(t_data, countt, count, cc);
	free(reload);
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
	int				count;
	int				countt;
	static int		cc;

	if (cc > 500)
		cc = 0;
	count = 0;
	countt = 0;
	first_while(t_data, count, countt);
	while (t_data->map_to_tab[countt])
	{
		count = 0;
		while (t_data->map_to_tab[countt][count] != '\0')
		{
			if_shorts(t_data, countt, count, cc);
			count++;
		}
		countt++;
		cc++;
	}
	return (0);
}
