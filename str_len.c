/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 08:08:20 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/24 15:11:45 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int str_len(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (0);
}