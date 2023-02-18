/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:15:09 by ychahbi           #+#    #+#             */
/*   Updated: 2023/02/18 18:37:13 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	func_short(struct s_data *t_data, int i, int j)
{
	t_data->map_to_tab[i][j] = '0';
	t_data->map_to_tab[i][j - 1] = 'P';
	t_data->count++;
	t_data->player_side = 1;
}

static void	if_func(struct s_data *t_data, int i, int j)
{
	if (t_data->map_to_tab[i][j - 1] == '1' ||
		(t_data->map_to_tab[i][j - 1] == 'E' && t_data->colloctive_s != 0))
		return ;
	if (t_data->map_to_tab[i][j - 1] == 'E' && t_data->colloctive_s == 0)
		put_youwin(t_data);
	if (t_data->map_to_tab[i][j -1] == 'I')
		put_youlose(t_data);
	if (t_data->map_to_tab[i][j - 1] == 'C')
		t_data->colloctive_s--;
	func_short(t_data, i, j);
	return ;
}

void	move_to_left(struct s_data *t_data)
{
	int	i;
	int	j;

	i = 0;
	while (t_data->map_to_tab[i])
	{
		j = 0;
		while (t_data->map_to_tab[i][j])
		{
			if (t_data->map_to_tab[i][j] == 'P')
				if_func(t_data, i, j);
			j++;
		}
		i++;
	}
}
