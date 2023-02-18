/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:21:24 by ychahbi           #+#    #+#             */
/*   Updated: 2023/02/18 18:37:05 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	func_short(struct s_data *t_data, int i, int j)
{
	t_data->map_to_tab[i][j] = '0';
	t_data->map_to_tab[i - 1][j] = 'P';
	t_data->count++;
}

static void	if_func(struct s_data *t_data, int i, int j)
{
	if (t_data->map_to_tab[i - 1][j] == '1'
		|| (t_data->map_to_tab[i - 1][j] == 'E' &&
		t_data->colloctive_s != 0))
		return ;
	if (t_data->map_to_tab[i - 1][j] == 'E' &&
	t_data->colloctive_s == 0)
		put_youwin(t_data);
	if (t_data->map_to_tab[i - 1][j] == 'I')
		put_youlose(t_data);
	if (t_data->map_to_tab[i - 1][j] == 'C')
		t_data->colloctive_s--;
	func_short(t_data, i, j);
	return ;
}

void	move_to_top(struct s_data *t_data)
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
