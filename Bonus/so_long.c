/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:01:27 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/31 18:49:42 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	struct s_data	*t_data;

	if (argc == 2)
	{
		t_data = malloc(sizeof(struct s_data));
		if (!t_data)
			return (ft_putstr("Memory Error!"), 0);
		if (cheack_map(argv[1], t_data) == 1)
			return (ft_putstr("Map Error"), 0);
		show_the_window(t_data);
	}
}
