/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:15:09 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/18 19:48:48 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_to_left(struct s_data *t_data)
{
    int i = 0;
    int j = 0;
    
    while(t_data->map_to_tab[i])
    {
        j = 0;
        while(t_data->map_to_tab[i][j])
        {
            if(t_data->map_to_tab[i][j] == 'P') {
                if (t_data->map_to_tab[i][j-1] != '0')
                    return;
                t_data->map_to_tab[i][j--] = '0';
                t_data->map_to_tab[i][j] = 'P';
                t_data->count++;
                ft_printnbr(t_data->count);
                write(1,"\n",1);
                return;
            }
            j++;
        }
        i++;
    }
}