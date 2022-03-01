/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:21:46 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/02 00:28:52 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_assets(t_vars *vars)
{
	if (vars->assets != NULL)
	{
		mlx_destroy_image(vars->mlx, vars->assets->bg->img);
		free(vars->assets->bg);
		mlx_destroy_image(vars->mlx, vars->assets->player_bg->img);
		free(vars->assets->player_bg);
		mlx_destroy_image(vars->mlx, vars->assets->player_e->img);
		free(vars->assets->player_e);
		mlx_destroy_image(vars->mlx, vars->assets->player_s->img);
		free(vars->assets->player_s);
		mlx_destroy_image(vars->mlx, vars->assets->exit->img);
		free(vars->assets->exit);
		mlx_destroy_image(vars->mlx, vars->assets->start->img);
		free(vars->assets->start);
		mlx_destroy_image(vars->mlx, vars->assets->item->img);
		free(vars->assets->item);
		mlx_destroy_image(vars->mlx, vars->assets->wall->img);
		free(vars->assets->wall);
	}
}

int	key_escp(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		win_close(vars);
	return (0);
}

int	win_close(t_vars *vars)
{
	free_assets(vars);
	mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}