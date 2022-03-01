/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:09:24 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/01 15:46:12 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	put_wall(t_point point, t_img *bg, t_vars *vars)
{
	return (put_asset(WALL, point, bg, vars));
}

static int	put_collectible(t_point point, t_img *bg, t_vars *vars)
{
	return (put_asset(COLLECTIBLE, point, bg, vars));
}

static int	put_exit(t_point point, t_img *bg, t_vars *vars)
{
	return (put_asset(EXIT, point, bg, vars));
}

static int	put_start(char **map, t_point point, t_img *bg, t_vars *vars)
{
	int	start_found;

	start_found = 0;
	while (map[point.x])
	{
		point.y = 0;
		while (map[point.x][point.y])
		{
			if (map[point.x][point.y] == 'P' && start_found == 0)
			{
				start_found = 1;
				if (put_asset(START, point, bg, vars) == -1)
					return (-1);
			}
			else if (map[point.x][point.y] == 'P' && start_found == 1)
				map[point.x][point.y] = '0';
			point.y++;
		}
		point.x++;
	}
	return (0);
}

int	put_assets(char **map, t_img *bg, t_vars *vars)
{
	t_point	point;

	point.x = 0;
	while (map[point.x])
	{
		point.y = 0;
		while (map[point.x][point.y])
		{
			if (map[point.x][point.y] == '1')
				if (put_wall(point, bg, vars) == -1)
					return (-1);
			if (map[point.x][point.y] == 'P')
				if (put_start(map, point, bg, vars) == -1)
					return (-1);
			if (map[point.x][point.y] == 'C')
				if (put_collectible(point, bg, vars) == -1)
					return (-1);
			if (map[point.x][point.y] == 'E')
				if (put_exit(point, bg, vars) == -1)
					return (-1);
			point.y++;
		}
		point.x++;
	}
	return (0);
}
