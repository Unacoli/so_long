/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:07:52 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/01 19:37:23 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_back(t_img bg, int height, int width, t_vars *vars)
{
	t_point	point;

	point.x = 0;
	while (point.x < height)
	{
		point.y = 0;
		while (point.y < width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, bg.img,
				point.x, point.y);
			point.y += bg.width;
		}
		point.x += bg.height;
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
	t_data	img;
	int		height;
	int		width;

	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		ft_quit_solong((void ***)&map, "Init Minilibx failed\n");
	init_assets(assets, vars, map);
	heightwidth(map, &height, &width, &assets->bg);
	vars->win = mlx_new_window(vars->mlx, height, width, "so_long");
	if (vars->win == NULL)
		ft_quit_solong((void ***)&map, "Failed creation of window\n");
	img.img = mlx_new_image(vars->mlx, height, width);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	put_back(assets->bg, height, width, vars);
	put_assets(map, assets, vars);
}
