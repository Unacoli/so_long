/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:25 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/01 01:45:50 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	win_close(t_vars *vars)
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
	t_vars	vars;
	char	**map;

	if (ac != 2)
		ft_quit("Usage: ./so_long <*.ber>\n");
	if (isber(av[1]) == 0)
		ft_quit("Use a .ber file\n");
	map = read_map(av[1]);
	check_map(map);
	init_mlx(map, &vars);
	mlx_key_hook(vars.win, key_escp, &vars);
	mlx_hook(vars.win, DestroyNotify, 1L << 0, win_close, &vars);
	ft_free_tab((void ***)&map);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
