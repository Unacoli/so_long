/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:04:12 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/02 00:48:03 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	isber(char *name_file)
{
	int	len;

	len = ft_strlen(name_file);
	if (name_file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(name_file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
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
		ft_free_tab((void ***)&map);
		ft_quit("One or multiple elements are missing\n");
	}
}

static void	check_rectangle(char **map)
{
	int	i;

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
				ft_free_tab((void ***)&map);
				ft_quit("Missing wall\n");
			}
			point.y++;
		}
		point.x++;
	}
}

void	check_map(char **map)
{
	check_element(map);
	check_rectangle(map);
	check_wall(map);
}
