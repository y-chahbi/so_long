/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:40:08 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/17 23:45:11 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **map_to_table(){
    char *last_line = NULL;
    char *temp;
	int fd = open("maps/map.ber", O_RDONLY);
	temp = get_next_line(fd);
    while(temp)
    {
        last_line = ft_strjoi(last_line,temp);
        temp = get_next_line(fd);
    }
    close(fd);
   return (ft_split(last_line, '\n'));
}