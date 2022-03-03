/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:07:52 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/03 01:01:41 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_back(t_point point, t_img *bg, t_vars *vars)
{
	put_asset(point, bg, vars, bg);
}

static t_img	*heightwidth(char **map, int *height, int *width, t_img *bg)
{	
	int		i;

	i = 0;
	*height = ft_strlen(map[i]) * bg->height;
	while (map[i])
		i++;
	*width = i * bg->width;
	return (bg);
}	

static void	assets_null(t_vars *vars)
{
	vars->assets->bg = NULL;
	vars->assets->player_bg = NULL;
	vars->assets->player_e = NULL;
	vars->assets->player_s = NULL;
	vars->assets->player_c = NULL;
	vars->assets->exit = NULL;
	vars->assets->start = NULL;
	vars->assets->item = NULL;
	vars->assets->wall = NULL;
}

void	init_mlx(t_assets *assets, char **map, t_vars *vars)
{
	int		height;
	int		width;

	height = 0;
	width = 0;
	assets_null(vars);
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		ft_quit_solong((void ***)&map, "Init Minilibx failed\n", vars);
	init_assets(assets, vars, map);
	vars->assets = assets;
	heightwidth(map, &height, &width, assets->bg);
	vars->win = mlx_new_window(vars->mlx, height, width, "so_long");
	if (vars->win == NULL)
		ft_quit_solong((void ***)&map, "Failed creation of window\n", vars);
	vars->img->img = mlx_new_image(vars->mlx, height, width);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel, &vars->img->line_length,
			&vars->img->endian);
	put_assets(map, assets, vars);
}
