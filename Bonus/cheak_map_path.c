/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 08:07:45 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/24 18:35:05 by ychahbi          ###   ########.fr       */
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
