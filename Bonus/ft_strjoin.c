/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:29:49 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/28 02:16:51 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		dex;

	ptr = (char *)malloc((ft_strlen(s1) + 1));
	if (!ptr)
		return (NULL);
	else
	{
		dex = 0;
		while (s1[dex] != '\0')
		{
			ptr[dex] = s1[dex];
			dex++;
		}
		ptr[dex] = '\0';
	}
	return (ptr);
}

char	*ft_strjoi(char *s1, char *s2)
{
	size_t		dex;
	size_t		dexx;
	char		*ptr;

	if (!s1)
		s1 = ft_strdup("");
	dex = 0;
	dexx = 0;
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (dex < ft_strlen(s1))
	{
		ptr[dex] = s1[dex];
		dex++;
	}
	while (dexx < ft_strlen(s2))
		ptr[dex++] = s2[dexx++];
	ptr[dex] = '\0';
	return (free(s1), ptr);
}
