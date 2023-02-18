/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 08:07:55 by ychahbi           #+#    #+#             */
/*   Updated: 2023/02/15 11:01:04 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_strcpy(char *dst, char *src)
{
	size_t		dex;
	size_t		n;

	dex = 0;
	if (!src)
		return (NULL);
	n = str_len(src);
	while (dex < n)
	{
		dst[dex] = src[dex];
		dex++;
	}
	free(src);
	return (dst);
}
