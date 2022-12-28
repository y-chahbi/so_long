/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:15:11 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/28 19:32:39 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	func_short(struct s_data *t_data, int i, int j)
{
	t_data->map_to_tab[i][j] = '0';
	t_data->map_to_tab[i][j + 1] = 'P';
	t_data->count++;
	t_data->player_side = 0;
}

static void	put_youwin(struct s_data *t_data)
{
	int	i;

	i = 0;
	while (t_data->map_to_tab[i])
	{
		free(t_data->map_to_tab[i]);
		i++;
	}
	free(t_data->map_to_tab);
	ft_putstr("You win");
	exit(0);
}

static void	put_youlose(struct s_data *t_data)
{
	int	i;

	i = 0;
	while (t_data->map_to_tab[i])
	{
		free(t_data->map_to_tab[i]);
		i++;
	}
	free(t_data->map_to_tab);
	ft_putstr("You Lose!");
	exit(0);
}

static void	while_func(struct s_data *t_data, int i, int j)
{
	while (t_data->map_to_tab[i])
	{
		j = 0;
		while (t_data->map_to_tab[i][j])
		{
			if (t_data->map_to_tab[i][j] == 'P')
			{
				if (t_data->map_to_tab[i][j + 1] == '1' ||
					(t_data->map_to_tab[i][j + 1] == 'E' &&
					t_data->colloctive_s != 0))
					return ;
				if (t_data->map_to_tab[i][j + 1] == 'E' &&
					t_data->colloctive_s == 0)
					put_youwin(t_data);
				if (t_data->map_to_tab[i][j + 1] == 'I')
					put_youlose(t_data);
				if (t_data->map_to_tab[i][j + 1] == 'C')
					t_data->colloctive_s--;
				func_short(t_data, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_to_right(struct s_data *t_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while_func(t_data, i, j);
}
