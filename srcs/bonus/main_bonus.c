/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:25 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/03 02:41:28 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_vars		vars;
	char		**map;
	t_assets	assets;
	t_data		img;
	t_point		point;

	check_av(ac, av);
	map = read_map(av[1]);
	vars.n_item = 0;
	check_map(map, &vars);
	vars.assets = &assets;
	vars.map = map;
	vars.img = &img;
	init_mlx(&assets, map, &vars);
	vars.point = &point;
	init_player(&assets, map, &vars);
	vars.count = 0;
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, DestroyNotify, 1L << 0, win_close, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
