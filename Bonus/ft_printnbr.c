/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:39:07 by ychahbi           #+#    #+#             */
/*   Updated: 2022/12/18 19:47:24 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printnbr(int n)
{
	unsigned int	mv;
	unsigned int	tmp;

	if (n < 0)
	{
		mv = -n;
		write(1, "-", 1);
	}
	else
		mv = n;
	if (mv <= 9)
	{
		tmp = mv + 48;
		write(1, &tmp, 1);
	}
	else
	{
		ft_printnbr(mv / 10);
		ft_printnbr(mv % 10);
	}
}
