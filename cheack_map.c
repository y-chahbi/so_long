/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheack_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:49:58 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/17 22:03:41 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void calc_letter(char *str, int *c, int *e, int *p)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == 'P')
            (*p)++;
        if(str[i] == 'E')
            (*e)++;
        if(str[i] == 'C')
            (*c)++;
        i++;
    }
}

int cheack_map()
{
    char *first_line;
    char *last_line;
    int len_size;
    int count;
    int p_count = 0;
    int e_count = 0;
    int c_count = 0;
    char *map_src = "maps/map.ber";
    count = 1;
    if (cheak_map_path(map_src) == 1)
        return 1;
    int fd = open(map_src, O_RDONLY);
    first_line = get_next_line(fd);
    len_size = str_len(first_line);
    last_line = calloc(sizeof(char), len_size);
    while(ft_strcpy(last_line, get_next_line(fd)))
    {
        count++;
        if (str_len(last_line) != len_size)
            return 1;
        if(last_line[0] != '1' || last_line[len_size -2] != '1')
            return 1;
        calc_letter(last_line, &c_count, &e_count, &p_count);
    }
    if( p_count != 1 || e_count != 1 || c_count < 1)
        return 1;
    if (count < 3)
        return 1;
    char *first_line_temp = first_line;
    char *last_line_temp = last_line;
    while(*first_line != '\n' && *last_line != '\n')
    {
        if (*(last_line) == '0' || *(last_line) == '0')
            return (1);
        (first_line)++;
        (last_line)++;
    }
    free(first_line_temp);
    free(last_line_temp);
    //free(last_line);
    return (0);
}