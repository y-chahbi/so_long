/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 08:07:45 by ychahbi           #+#    #+#             */
/*   Updated: 2023/02/18 16:33:31 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cheak_map_path(char *s)
{
	int		i;
	int		len;
	char	*the_path;

	i = 0;
	len = str_len(s) - 4;
	the_path = ".ber";
	while (s[len] != '\0')
	{
		if (s[len] != the_path[i])
			return (1);
		len++;
		i++;
	}
	return (0);
}

void	my_last_line_last_check(struct s_data *t_data, int count, int len_size)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(t_data->map_path, O_RDONLY);
	i = 1;
	line = NULL;
	while (i <= count)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (len_size - 1 != str_len(line))
	{
		puts("Error");
		free(line);
		exit(1);
	}
}
