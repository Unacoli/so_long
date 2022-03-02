/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:09:24 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/02 16:39:02 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(t_point point, t_img *bg, t_vars *vars, t_img *wall)
{
	put_asset(point, bg, vars, wall);
}

void	put_item(t_point point, t_img *bg, t_vars *vars, t_img *item)
{
	put_asset(point, bg, vars, item);
}

void	put_exit(t_point point, t_img *bg, t_vars *vars, t_img *exit)
{
	put_asset(point, bg, vars, exit);
}

void	put_start(t_point point, t_img *bg, t_vars *vars, t_img *start)
{
	put_asset(point, bg, vars, start);
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
			if (map[point.x][point.y] == '0')
				put_back(point, assets->bg, vars);
			if (map[point.x][point.y] == '1')
				put_wall(point, assets->bg, vars, assets->wall);
			if (map[point.x][point.y] == 'P')
				put_start(point, assets->bg, vars, assets->start);
			if (map[point.x][point.y] == 'C')
				put_item(point, assets->bg, vars, assets->item);
			if (map[point.x][point.y] == 'E')
				put_exit(point, assets->bg, vars, assets->exit);
			point.y++;
		}
		point.x++;
	}
}
