/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:25 by nargouse          #+#    #+#             */
/*   Updated: 2022/02/28 19:59:24 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
}

static int	isber(char *name_file)
{
	int	len;

	len = ft_strlen(name_file);
	if (name_file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(name_file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	img;
	t_vars	vars;
	t_img	wall;
	t_img	player;
	char	**map;

	if (ac != 2)
		ft_quit("Usage: ./so_long <*.ber>\n");
	if (isber(av[1]) == 0)
		ft_quit("Use a .ber file");
	map = read_map(av[1]);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (EXIT_FAILURE);
	vars.win = mlx_new_window(vars.mlx, 640, 480, "so_long");
	img.img = mlx_new_image(vars.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	player.img = mlx_xpm_file_to_image(vars.mlx, PLAYER, &player.img_width, &player.img_height);
	if (player.img == NULL)
		return (EXIT_FAILURE);
	wall.img = mlx_xpm_file_to_image(vars.mlx, WALL, &wall.img_width, &wall.img_height);
	if (wall.img == NULL)
		return (EXIT_FAILURE);
	mlx_put_image_to_window(vars.mlx, vars.win, player.img, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, wall.img, 0, 0);
	mlx_key_hook(vars.win, key_escp, &vars);
	mlx_hook(vars.win, DestroyNotify, 1L << 0, win_close, &vars);
	ft_free_tab((void ***)&map);
	if (vars.win == NULL)
		return (EXIT_FAILURE);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
