/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_assets_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:09:24 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/03 02:14:45 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
				put_asset(point, assets->bg, vars, assets->bg);
			if (map[point.x][point.y] == '1')
				put_asset(point, assets->bg, vars, assets->wall);
			if (map[point.x][point.y] == 'P')
				put_asset(point, assets->bg, vars, assets->start);
			if (map[point.x][point.y] == 'C')
				put_asset(point, assets->bg, vars, assets->item);
			if (map[point.x][point.y] == 'E')
				put_asset(point, assets->bg, vars, assets->exit);
			point.y++;
		}
		point.x++;
	}
}
