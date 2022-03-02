/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:59:38 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/02 21:01:30 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	d_c(t_vars *vars, t_point point, t_img *bg, t_img *player_c)
{
	if (vars->map[vars->point->x][vars->point->y] == 'P')
		put_asset(point, bg, vars, vars->assets->start);
	else if (vars->map[vars->point->x][vars->point->y] == 'E')
		put_asset(point, bg, vars, vars->assets->exit);
	else
		put_asset(point, bg, vars, bg);
	point.x += 1;
	vars->map[point.x][point.y] = '0';
	vars->n_item -= 1;
	put_asset(point, bg, vars, player_c);
}

static void	d_e(t_vars *vars, t_point point, t_img *bg, t_img *player_e)
{
	if (vars->map[vars->point->x][vars->point->y] == 'P')
		put_asset(point, bg, vars, vars->assets->start);
	else
		put_asset(point, bg, vars, bg);
	point.x += 1;
	put_asset(point, bg, vars, player_e);
	if (vars->n_item == 0)
	{
		ft_putstr("You win !\n");
		win_close(vars);
	}
}

static void	d_s(t_vars *vars, t_point point, t_img *bg, t_img *player_s)
{
	if (vars->map[vars->point->x][vars->point->y] == 'E')
		put_asset(point, bg, vars, vars->assets->exit);
	else
		put_asset(point, bg, vars, bg);
	point.x += 1;
	put_asset(point, bg, vars, player_s);
}

static void	d_b(t_vars *vars, t_point point, t_img *bg, t_img *player_bg)
{
	if (vars->map[vars->point->x][vars->point->y] == 'P')
		put_asset(point, bg, vars, vars->assets->start);
	else if (vars->map[vars->point->x][vars->point->y] == 'E')
		put_asset(point, bg, vars, vars->assets->exit);
	else
		put_asset(point, bg, vars, bg);
	point.x += 1;
	put_asset(point, bg, vars, player_bg);
}

int	move_down(t_vars *vars)
{
	if (vars->map[vars->point->x + 1][vars->point->y] != '1')
	{
		if (vars->map[vars->point->x + 1][vars->point->y] == '0')
			d_b(vars, *vars->point, vars->assets->bg, vars->assets->player_bg);
		else if (vars->map[vars->point->x + 1][vars->point->y] == 'P')
			d_s(vars, *vars->point, vars->assets->bg, vars->assets->player_s);
		else if (vars->map[vars->point->x + 1][vars->point->y] == 'E')
			d_e(vars, *vars->point, vars->assets->bg, vars->assets->player_e);
		else if (vars->map[vars->point->x + 1][vars->point->y] == 'C')
			d_c(vars, *vars->point, vars->assets->bg, vars->assets->player_c);
		vars->point->x += 1;
		return (1);
	}
	return (0);
}
