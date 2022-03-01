/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:09:24 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/01 17:13:58 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_wall(t_point point, t_img *bg, t_vars *vars, t_img *wall)
{
	put_asset(point, wall, vars, bg);
}

static void	put_item(t_point point, t_img *bg, t_vars *vars, t_img *item)
{
	put_asset(point, item, vars, bg);
}

static void	put_exit(t_point point, t_img *bg, t_vars *vars, t_img *exit)
{
	put_asset(point, exit, vars, bg);
}

static void	put_start(char **map, t_point point, t_assets *a, t_vars *vars)
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
				put_asset(point, &a->start, vars, &a->bg);
			}
			else if (map[point.x][point.y] == 'P' && start_found == 1)
				map[point.x][point.y] = '0';
			point.y++;
		}
		point.x++;
	}
}

void	put_assets(char **map, t_assets *assets, t_vars *vars)
{
	t_point	point;

	point.x = 0;
	while (map[point.x])
	{
		point.y = 0;
		while (map[point.x][point.y])
		{
			if (map[point.x][point.y] == '1')
				put_wall(point, &assets->bg, vars, &assets->wall);
			if (map[point.x][point.y] == 'P')
				put_start(map, point, assets, vars);
			if (map[point.x][point.y] == 'C')
				put_item(point, &assets->bg, vars, &assets->item);
			if (map[point.x][point.y] == 'E')
				put_exit(point, &assets->bg, vars, &assets->exit);
			point.y++;
		}
		point.x++;
	}
}
