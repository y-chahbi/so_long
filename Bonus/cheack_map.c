/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheack_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:49:58 by ychahbi           #+#    #+#             */
/*   Updated: 2023/02/15 14:07:23 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	calc_letter(char *str, int *c, int *e, int *p)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == 'P')
			(*p)++;
		else if (str[i] == 'E')
			(*e)++;
		else if (str[i] == 'C')
			(*c)++;
		else if (str[i] != '0' && str[i] != '1' && str[i] != 'C'
			&& str[i] != 'P' && str[i] != 'E' && str[i] != 'I')
		{
			ft_putstr("Error\n");
			exit(1);
		}
		i++;
	}
}

static void	count_init(int *c, int *e, int *p)
{
	*c = 0;
	*e = 0;
	*p = 0;
}

int	cheak_open(char *s)
{
	int	fd;

	if (cheak_map_path(s) == 1)
		return (ft_putstr("(Path Error) >> "), 1);
	fd = open(s, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (ft_putstr("(Coulden't Read) >> "), 1);
	return (fd);
}

int	while_count(struct s_data *t_data, char *last_line, int len_size, int fd)
{
	int	p_count;
	int	e_count;
	int	c_count;
	int	count;

	count = 1;
	count_init(&c_count, &e_count, &c_count);
	while (ft_strcpy(last_line, get_next_line(fd)))
	{
		if (str_len(last_line) != len_size)
			return (ft_putstr("(Line size) >> "), 1);
		if (last_line[0] != '1' || last_line[str_len(last_line) - 2] != '1')
			return (ft_putstr("(dont't have closed sides) >> "), 1);
		calc_letter(last_line, &c_count, &e_count, &p_count);
		count++;
	}
	if (check___ones(last_line) == 0)
		return (ft_putstr("(last line ) >> "), 1);
	if (p_count != 1 || e_count != 1 || c_count < 1)
		return (ft_putstr("(one of elements or all not exist) >> "), 1);
	if (count < 3)
		return (ft_putstr("(map counine less lines) >> "), 1);
	my_last_line_last_check(t_data, count, len_size);
	t_data->colloctive_s = c_count;
	return (0);
}

int	cheack_map(char *s, struct s_data *t_data)
{
	char	*first_line;
	char	*last_line;
	int		len_size;
	int		fd;
	int		i;

	iniit(t_data, s, &fd);
	first_line = get_next_line(fd);
	if (check___ones(first_line) == 0)
		return (ft_putstr("(First line ) >> "), 1);
	len_size = str_len(first_line);
	last_line = ft_calloc(sizeof(char), len_size);
	if (while_count(t_data, last_line, len_size, fd) == 1)
		return (1);
	if (backtracking(t_data) == 1)
		return (ft_putstr("(The player can't win the game) --> "), 1);
	if (t_data->map_height > 18 || t_data->map_width > 34)
		return (ft_putstr("(Map Large) --> "), 1);
	i = 0;
	if (while___(first_line, last_line, i) == 1)
		return (1);
	return (free(first_line), free(last_line), 0);
}
