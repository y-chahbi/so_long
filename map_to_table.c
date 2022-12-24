/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:40:08 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/24 06:16:33 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **map_to_table(struct s_data *t_data)
{
    int lines;
    int coll;
    char *temp;
    char *last_line;

    coll = 1;
    last_line = NULL;
	int fd = open(t_data->map_path, O_RDONLY);
    if (fd < 0 || read(fd, 0, 0) < 0)
	    return (NULL);;
	temp = get_next_line(fd);
    lines = str_len(temp);
    while(temp)
    {
        last_line = ft_strjoi(last_line,temp);
        temp = get_next_line(fd);
        coll++;
    }
    t_data->map_height = coll - 1;
	t_data->map_width = lines - 1;
    close(fd);
    free(temp);
   return (ft_split(last_line, '\n'));
}