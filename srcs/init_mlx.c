/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:07:52 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/02 00:28:01 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_back(t_img *bg, int height, int width, t_vars *vars)
{
	t_point	point;

	point.x = 0;
	while (point.x < height)
	{
		point.y = 0;
		while (point.y < width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, bg->img,
				point.x, point.y);
			point.y += bg->width;
		}
		point.x += bg->height;
	}
}

t_img	*heightwidth(char **map, int *height, int *width, t_img *bg)
{	
	int		i;

	i = 0;
	*height = ft_strlen(map[i]) * bg->height;
	while (map[i])
		i++;
	*width = i * bg->width;
	return (bg);
}	

void	init_mlx(t_assets *assets, char **map, t_vars *vars)
{
	int		height;
	int		width;

	height = 0;
	width = 0;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		ft_quit_solong((void ***)&map, "Init Minilibx failed\n");
	init_assets(assets, vars, map);
	vars->assets = assets;
	heightwidth(map, &height, &width, assets->bg);
	vars->win = mlx_new_window(vars->mlx, height, width, "so_long");
	if (vars->win == NULL)
		ft_quit_solong((void ***)&map, "Failed creation of window\n");
	vars->img->img = mlx_new_image(vars->mlx, height, width);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel, &vars->img->line_length,
			&vars->img->endian);
	put_back(assets->bg, height, width, vars);
	put_assets(map, assets, vars);
}
