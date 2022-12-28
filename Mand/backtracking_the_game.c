/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_the_game.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:30:49 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/28 14:34:21 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	backtracking_the_game(struct s_data *t_data, char **tab, int x, int y)
{
	if (t_data->map_to_tab[x][y] == '1' || tab[x][y] == 'Z')
		return (0);
	if (tab[x][y] == 'E')
		return (1);
	tab[x][y] = 'Z';
	return (backtracking_the_game(t_data, tab, x - 1, y)
		|| backtracking_the_game(t_data, tab, x + 1, y)
		|| backtracking_the_game(t_data, tab, x, y + 1)
		|| backtracking_the_game(t_data, tab, x, y - 1));
}

void	free_it(char **s)
{
	int	a;

	a = 0;
	while (s[a])
	{
		free(s[a]);
		a++;
	}
	free(s);
}

int	backtracking(struct s_data *t_data)
{
	char	**tab_tow;
	int		x;
	int		y;
	int		lo[1][2];

	x = 0;
	tab_tow = map_to_table(t_data);
	while (tab_tow[x])
	{
		y = 0;
		while (tab_tow[x][y])
		{
			if (tab_tow[x][y] == 'P')
			{
				lo[0][0] = x;
				lo[0][1] = y;
			}
			y++;
		}
		x++;
	}
	if (backtracking_the_game(t_data, tab_tow, lo[0][0], lo[0][1]) == 0)
		return (free_it(tab_tow), 1);
	return (free_it(tab_tow), 0);
}
