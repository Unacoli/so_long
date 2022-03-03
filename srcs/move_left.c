/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:01:45 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/03 01:36:59 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	l_c(t_vars *vars, t_point point, t_img *bg, t_img *player_c)
{
	if (vars->map[vars->point->x][vars->point->y] == 'P')
		put_asset(point, bg, vars, vars->assets->start);
	else if (vars->map[vars->point->x][vars->point->y] == 'E')
		put_asset(point, bg, vars, vars->assets->exit);
	else
		put_asset(point, bg, vars, bg);
	point.y -= 1;
	vars->map[point.x][point.y] = '0';
	put_asset(point, bg, vars, player_c);
}

static void	l_e(t_vars *vars, t_point point, t_img *bg, t_img *player_e)
{
	if (vars->map[vars->point->x][vars->point->y] == 'P')
		put_asset(point, bg, vars, vars->assets->start);
	else
		put_asset(point, bg, vars, bg);
	point.y -= 1;
	put_asset(point, bg, vars, player_e);
	if (vars->n_item == 0)
	{
		ft_putstr("You won !\n");
		win_close(vars);
	}
}

static void	l_s(t_vars *vars, t_point point, t_img *bg, t_img *player_s)
{
	if (vars->map[vars->point->x][vars->point->y] == 'E')
		put_asset(point, bg, vars, vars->assets->exit);
	else
		put_asset(point, bg, vars, bg);
	point.y -= 1;
	put_asset(point, bg, vars, player_s);
}

static void	l_b(t_vars *vars, t_point point, t_img *bg, t_img *player_bg)
{
	if (vars->map[vars->point->x][vars->point->y] == 'P')
		put_asset(point, bg, vars, vars->assets->start);
	else if (vars->map[vars->point->x][vars->point->y] == 'E')
		put_asset(point, bg, vars, vars->assets->exit);
	else
		put_asset(point, bg, vars, bg);
	point.y -= 1;
	put_asset(point, bg, vars, player_bg);
}

int	move_left(t_vars *vars)
{
	if (vars->map[vars->point->x][vars->point->y - 1] != '1')
	{
		if (vars->map[vars->point->x][vars->point->y - 1] == '0')
			l_b(vars, *vars->point, vars->assets->bg, vars->assets->player_bg);
		else if (vars->map[vars->point->x][vars->point->y - 1] == 'P')
			l_s(vars, *vars->point, vars->assets->bg, vars->assets->player_s);
		else if (vars->map[vars->point->x][vars->point->y - 1] == 'E')
			l_e(vars, *vars->point, vars->assets->bg, vars->assets->player_e);
		else if (vars->map[vars->point->x][vars->point->y - 1] == 'C')
			l_c(vars, *vars->point, vars->assets->bg, vars->assets->player_c);
		vars->point->y -= 1;
		return (1);
	}
	return (0);
}
