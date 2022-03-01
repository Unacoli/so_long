/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:09:24 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/01 14:09:28 by nargouse         ###   ########.fr       */
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

static int	put_start(t_point point, t_img *bg, t_vars *vars)
{
	return (put_asset(START, point, bg, vars));
}

void	put_assets(char **map, t_img *bg, t_vars *vars)
{
	t_point	point;

	point.x = 0;
	while (map[point.x])
	{
		point.y = 0;
		while (map[point.x][point.y])
		{
			if (map[point.x][point.y] == '1')
				put_wall(point, bg, vars);
			if (map[point.x][point.y] == 'P')
				put_start(point, bg, vars);
			if (map[point.x][point.y] == 'C')
				put_collectible(point, bg, vars);
			if (map[point.x][point.y] == 'E')
				put_exit(point, bg, vars);
			point.y++;
		}
		point.x++;
	}
}
