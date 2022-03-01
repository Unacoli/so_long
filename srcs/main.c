/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:25 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/02 00:25:53 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars		vars;
	char		**map;
	t_assets	assets;
	t_data		img;

	if (ac != 2)
		ft_quit("Usage: ./so_long <*.ber>\n");
	if (isber(av[1]) == 0)
		ft_quit("Use a .ber file\n");
	map = read_map(av[1]);
	check_map(map);
	vars.img = &img;
	init_mlx(&assets, map, &vars);
	mlx_key_hook(vars.win, key_escp, &vars);
	mlx_hook(vars.win, DestroyNotify, 1L << 0, win_close, &vars);
	ft_free_tab((void ***)&map);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
