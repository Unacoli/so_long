/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:04:12 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/02 22:08:21 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_multiplestart(char **map, t_vars *vars)
{
	t_point	point;
	int		start_found;
	int		n_item;

	point.x = 0;
	start_found = 0;
	n_item = 0;
	while (map[point.x])
	{
		point.y = 0;
		while (map[point.x][point.y])
		{
			if (map[point.x][point.y] == 'P' && start_found == 0)
				start_found = 1;
			else if (map[point.x][point.y] == 'P' && start_found == 1)
				map[point.x][point.y] = '0';
			if (map[point.x][point.y] == 'C')
				n_item += 1;
			point.y++;
		}
		point.x++;
	}
	vars->n_item = n_item;
}

static void	check_element(char **map)
{
	int	i;
	int	str[3];

	ft_bzero(str, sizeof(int) * 3);
	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'P') != 0)
			str[0] = 1;
		if (ft_strchr(map[i], 'C') != 0)
			str[1] = 1;
		if (ft_strchr(map[i], 'E') != 0)
			str[2] = 1;
		i++;
	}
	if (str[0] != 1 || str[1] != 1 || str[2] != 1)
	{
		ft_quit_solong((void ***)&map,
			"One or multiple elements are missing\n", NULL);
	}
}

static void	check_rectangle(char **map)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			ft_quit_solong((void ***)&map, "Map isn't a rectangle\n", NULL);
		i++;
	}
}

static void	check_wall(char **map)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	while (map[point.x])
	{
		while (map[point.x][point.y])
		{
			if ((point.x == 0 && map[0][point.y] != '1')
				|| (point.y == 0 && map[point.x][0] != '1')
				|| (map[point.x + 1] == NULL && map[point.x][point.y] != '1')
				|| (point.y == ft_strlen(map[point.x]) - 1
					&& map[point.x][point.y] != '1'))
			{
				ft_quit_solong((void ***)&map, "Missing wall\n", NULL);
			}
			point.y++;
		}
		point.x++;
	}
}

void	check_map(char **map, t_vars *vars)
{
	check_element(map);
	check_rectangle(map);
	check_wall(map);
	check_multiplestart(map, vars);
}
