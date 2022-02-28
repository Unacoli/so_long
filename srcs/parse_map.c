/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:04:12 by nargouse          #+#    #+#             */
/*   Updated: 2022/02/28 23:07:18 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_element(char **map)
{
	int	i;
	int	str[3];

	ft_bzero(str, 3);
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
		ft_free_tab((void ***)&map);
		ft_quit("One or multiple elements are missing\n");
	}
}

static void	check_rectangle(char **map)
{
	int i;

	i = 0; 
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
		{
			ft_free_tab((void ***)&map);
			ft_quit("Map isn't a rectangle\n");
		}
		i++;
	}
}

static void	check_wall(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (x == 0 && map[0][y] != '1')
				ft_quit("Missing wall\n");
			if (y == 0 && map[x][0] != '1')
				ft_quit("Missing wall\n");
			if (map[x + 1] == NULL && map[x][y] != '1')
				ft_quit("Missing wall\n");
			if (y == ft_strlen(map[x]) - 1 && map[x][y] != '1')
				ft_quit("Missing wall\n");
			y++;
		}
		x++;
	}
}

void	check_map(char **map)
{
	check_element(map);
	check_rectangle(map);
	check_wall(map);
}
