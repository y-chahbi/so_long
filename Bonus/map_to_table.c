/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:40:08 by ychahbi           #+#    #+#             */
/*   Updated: 2023/02/18 17:23:24 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_p(struct s_data *t_data, int *width, int *height)
{
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

void	iniit(struct s_data *t_data, char *s, int *fd)
{
	t_data->map_path = s;
	t_data->map_to_tab = map_to_table(t_data);
	*fd = cheak_open(s);
}

int	check___ones(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	while___(char *first_line, char *last_line, int i)
{
	while (first_line[i] != '\n' && last_line[i] != '\n')
	{
		if (last_line[i] != '1' || (first_line[i]) != '1')
			return (ft_putstr("(Closed side is missing) >> "), 1);
		i++;
	}
	return (0);
}

char	**map_to_table(struct s_data *t_data)
{
	int		lines;
	int		coll;
	char	*temp;
	char	*last_line;
	int		fd;

	coll = 1;
	last_line = NULL;
	fd = open(t_data->map_path, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	temp = get_next_line(fd);
	lines = str_len(temp);
	while (temp)
	{
		last_line = ft_strjoi(last_line, temp);
		free(temp);
		temp = get_next_line(fd);
		coll++;
	}
	t_data->map_height = coll - 1;
	t_data->map_width = lines - 1;
	close(fd);
	free(temp);
	return (ft_split(last_line, '\n'));
}
