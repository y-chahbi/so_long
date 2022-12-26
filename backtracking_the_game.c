/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_the_game.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:30:49 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/24 18:50:51 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void floodFill(int x, int y, int oldColor, int newColor)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
        return;

    if (image[x][y] != oldColor)
        return;

    image[x][y] = newColor;

    floodFill(x+1, y, oldColor, newColor);
    floodFill(x-1, y, oldColor, newColor);
    floodFill(x, y+1, oldColor, newColor);
    floodFill(x, y-1, oldColor, newColor);
}
void	give_me_x_y(char **tab_tow, int *x, int *y)
{
	int i =0;
	int j = 0;
	while (tab_tow[i])
	{
		j = 0;
		while (tab_tow[i][j])
		{
			if (tab_tow[i][j] == 'P')
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}

int	backtracking(char **tab_tow, int x, int y)
{
	return 0;
}

int	backtracking_the_game(struct s_data *t_data)
{
	char	**tab_tow;

	tab_tow = t_data->map_to_tab;
	int x;
	int y;
	give_me_x_y(tab_tow, &x, &y);
	if (backtracking(tab_tow, x, y) == 1)
		return 1;
	return 0;
}
