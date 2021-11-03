/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:25 by nargouse          #+#    #+#             */
/*   Updated: 2021/11/03 17:41:00 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	win_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_data	img;
	t_vars	vars;
	t_img	wall;
	
	if (ac != 2)
		return (EXIT_FAILURE);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (EXIT_FAILURE);
	vars.win = mlx_new_window(vars.mlx, 640, 480, "so_long");
	img.img = mlx_new_image(vars.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	wall.img = mlx_xpm_file_to_image(vars.mlx, "texturing/wall.xpm", &wall.img_width, &wall.img_height);
	if (wall.img == NULL)
		return (EXIT_FAILURE);
	pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, wall.img, 10, 10);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, DestroyNotify, 1L<<0, win_close, &vars);
	if (vars.win == NULL)
		return (EXIT_FAILURE);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
