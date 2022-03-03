/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_win_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:21:46 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/03 04:09:35 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_asset(void *mlx, t_img *asset)
{
	mlx_destroy_image(mlx, asset->img);
	free(asset);
}

void	free_assets(t_vars *vars)
{
	if (vars->assets != NULL)
	{
		if (vars->assets->bg != NULL)
			free_asset(vars->mlx, vars->assets->bg);
		if (vars->assets->player_bg != NULL)
			free_asset(vars->mlx, vars->assets->player_bg);
		if (vars->assets->player_e != NULL)
			free_asset(vars->mlx, vars->assets->player_e);
		if (vars->assets->player_s != NULL)
			free_asset(vars->mlx, vars->assets->player_s);
		if (vars->assets->exit != NULL)
			free_asset(vars->mlx, vars->assets->exit);
		if (vars->assets->start != NULL)
			free_asset(vars->mlx, vars->assets->start);
		if (vars->assets->item != NULL)
			free_asset(vars->mlx, vars->assets->item);
		if (vars->assets->wall != NULL)
			free_asset(vars->mlx, vars->assets->wall);
		if (vars->assets->player_c != NULL)
			free_asset(vars->mlx, vars->assets->player_c);
		if (vars->assets->ennemi != NULL)
			free_asset(vars->mlx, vars->assets->ennemi);
	}
}

int	win_close(t_vars *vars)
{
	free_assets(vars);
	ft_free_tab((void ***)&vars->map);
	mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}
