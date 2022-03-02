/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:57:56 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/02 20:10:55 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	r_c(t_vars *vars, t_point point, t_img *bg, t_img *player_c)
{
	if (vars->map[vars->point->x][vars->point->y] == 'P')
		put_start(point, bg, vars, vars->assets->start);
	else
		put_back(point, bg, vars);
	point.y += 1;
	vars->map[point.x][point.y] = '0';
	put_asset(point, bg, vars, player_c);
}

static void	r_e(t_vars *vars, t_point point, t_img *bg, t_img *player_e)
{
	if (vars->map[vars->point->x][vars->point->y] == 'P')
		put_start(point, bg, vars, vars->assets->start);
	else
		put_back(point, bg, vars);
	point.y += 1;
	put_player_e(point, bg, vars, player_e);
}

static void	r_s(t_vars *vars, t_point point, t_img *bg, t_img *player_s)
{
	put_back(point, bg, vars);
	point.y += 1;
	put_player_s(point, bg, vars, player_s);
}

static void	r_b(t_vars *vars, t_point point, t_img *bg, t_img *player_bg)
{
	if (vars->map[vars->point->x][vars->point->y] == 'P')
		put_start(point, bg, vars, vars->assets->start);
	else
		put_back(point, bg, vars);
	point.y += 1;
	put_player_bg(point, bg, vars, player_bg);
}

int	move_right(t_vars *vars)
{
	if (vars->map[vars->point->x][vars->point->y + 1] != '1')
	{
		if (vars->map[vars->point->x][vars->point->y + 1] == '0')
			r_b(vars, *vars->point, vars->assets->bg, vars->assets->player_bg);
		else if (vars->map[vars->point->x][vars->point->y + 1] == 'P')
			r_s(vars, *vars->point, vars->assets->bg, vars->assets->player_s);
		else if (vars->map[vars->point->x][vars->point->y + 1] == 'E')
			r_e(vars, *vars->point, vars->assets->bg, vars->assets->player_e);
		else if (vars->map[vars->point->x][vars->point->y + 1] == 'C')
			r_c(vars, *vars->point, vars->assets->bg, vars->assets->player_c);
		vars->point->y += 1;
		return (1);
	}
	return (0);
}
