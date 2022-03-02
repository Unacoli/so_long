/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:02:03 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/02 20:51:32 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_assets *a, char **map, t_vars *vars)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	vars->point->x = 0;
	vars->point->y = 0;
	while (map[point.x])
	{
		point.y = 0;
		while (map[point.x][point.y])
		{
			if (map[point.x][point.y] == 'P')
			{
				put_asset(point, a->bg, vars, a->player_s);
				vars->point->x = point.x;
				vars->point->y = point.y;
				return ;
			}
			point.y++;
		}
		point.x++;
	}
}
