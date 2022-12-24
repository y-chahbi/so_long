/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheack_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:49:58 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/24 12:49:02 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void calc_letter(char *str, int *c, int *e, int *p)
{
    int i;

    i = 0;
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

static void count_init(int *c, int *e, int *p)
{
    *c = 0;
    *e = 0;
    *p = 0;
}
static int cheak_open(char *s)
{
    int fd;
    
    if (cheak_map_path(s) == 1)
        return (ft_putstr("(Path Error) >> "), 1);
    fd = open(s, O_RDONLY);
    if (fd < 0 || read(fd, 0, 0) < 0)
	    return (ft_putstr("(Coulden't Read) >> "), 1);
    return (fd);
}
int cheack_map(char *s, struct s_data *t_data)
{
    t_data->map_path = s;
    t_data->map_to_tab = map_to_table(t_data);
    char *first_line;
    char *last_line;
    int len_size;
    int count;
    int p_count;
    int e_count;
    int c_count;
    int fd;

    count = 1;
    fd = cheak_open(s);
    count_init(&c_count, &e_count, &p_count);
    first_line = get_next_line(fd);
    len_size = str_len(first_line);
    last_line = calloc(sizeof(char), len_size);
    while(ft_strcpy(last_line, get_next_line(fd)))
    {
        count++;
        if (str_len(last_line) != len_size)
            return (ft_putstr("(Line size) >> "), 1);
        if(last_line[0] != '1' || last_line[len_size -2] != '1')
            return (ft_putstr("(dont't have closed sides) >> "), 1);
        calc_letter(last_line, &c_count, &e_count, &p_count);
    }
    if( p_count != 1 || e_count != 1 || c_count < 1)
        return (ft_putstr("(player, exit, collectables, one of them or all not exist) >> "), 1);
    if (count < 3)
        return (ft_putstr("(map counine less lines) >> "), 1);
    if (backtracking_the_game(t_data) == 1)
        return (ft_putstr("(The player can't win the game) --> "), 1);
    while(*first_line != '\n' && *last_line != '\n')
    {
        if (*(last_line) == '0' || *(last_line) == '0')
            return (ft_putstr("(Closed side is missing (firrst or last)) >> "), 1);
        (first_line)++;
        (last_line)++;
    }
    t_data->colloctive_s = c_count;
    return (0);
}