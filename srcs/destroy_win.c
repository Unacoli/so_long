/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:21:46 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/02 17:32:41 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_assets(t_vars *vars)
{
	if (vars->assets != NULL)
	{
		if (vars->assets->bg != NULL)
		{
			mlx_destroy_image(vars->mlx, vars->assets->bg->img);
			free(vars->assets->bg);
		}
		if (vars->assets->player_bg != NULL)
		{
			mlx_destroy_image(vars->mlx, vars->assets->player_bg->img);
			free(vars->assets->player_bg);
		}
		if (vars->assets->player_e != NULL)
		{
			mlx_destroy_image(vars->mlx, vars->assets->player_e->img);
			free(vars->assets->player_e);
		}
		if (vars->assets->player_s != NULL)
		{
			mlx_destroy_image(vars->mlx, vars->assets->player_s->img);
			free(vars->assets->player_s);
		}
	}
}

void	free_assets2(t_vars *vars)
{
	if (vars->assets != NULL)
	{
		if (vars->assets->exit != NULL)
		{
			mlx_destroy_image(vars->mlx, vars->assets->exit->img);
			free(vars->assets->exit);
		}
		if (vars->assets->start != NULL)
		{
			mlx_destroy_image(vars->mlx, vars->assets->start->img);
			free(vars->assets->start);
		}
		if (vars->assets->item != NULL)
		{
			mlx_destroy_image(vars->mlx, vars->assets->item->img);
			free(vars->assets->item);
		}
		if (vars->assets->wall != NULL)
		{
			mlx_destroy_image(vars->mlx, vars->assets->wall->img);
			free(vars->assets->wall);
		}
	}
}

int	win_close(t_vars *vars)
{
	free_assets(vars);
	free_assets2(vars);
	ft_free_tab((void ***)&vars->map);
	mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}
