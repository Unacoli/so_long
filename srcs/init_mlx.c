/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:07:52 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/01 14:16:06 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_back(t_img background, int height, int width, t_vars *vars)
{
	t_point	point;

	point.x = 0;
	while (point.x < height)
	{
		point.y = 0;
		while (point.y < width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, background.img,
				point.x, point.y);
			point.y += background.width;
		}
		point.x += background.height;
	}
}

t_img	heightwidth(char **map, int *height, int *width, t_vars *vars)
{	
	t_img	background;
	int		i;

	background.img = mlx_xpm_file_to_image(vars->mlx, BACKGROUND,
			&background.height, &background.width);
	if (background.img == NULL)
	{
		ft_free_tab((void ***)&map);
		ft_quit("Failed xpm file to image\n");
	}
	i = 0;
	*height = ft_strlen(map[i]) * background.height;
	while (map[i])
		i++;
	*width = i * background.width;
	return (background);
}	

void	init_mlx(char **map, t_vars *vars)
{
	t_data	img;
	t_img	background;
	int		height;
	int		width;

	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
	{
		ft_free_tab((void ***)&map);
		ft_quit("Init Minilibx failed\n");
	}
	background = heightwidth(map, &height, &width, vars);
	vars->win = mlx_new_window(vars->mlx, height, width, "so_long");
	if (vars->win == NULL)
	{
		ft_free_tab((void ***)&map);
		ft_quit("Failed creation of window\n");
	}
	img.img = mlx_new_image(vars->mlx, height, width);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	put_back(background, height, width, vars);
	put_assets(map, &background, vars);
}
