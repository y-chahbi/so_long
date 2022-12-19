/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 08:54:16 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/17 23:40:03 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_map_lines(int *coll, int *linee)
{
    char *the_line_of;
    int i = 1; 
    int fd = open("maps/map.ber", O_RDONLY);
    char *the_line = get_next_line(fd);
    *linee = str_len(the_line);
    the_line_of = malloc(sizeof(char) * (*linee) - 1);
    while(ft_strcpy(the_line_of, get_next_line(fd)))
        i++;
    *coll = i;
    free(the_line);
    free(the_line_of);
}
