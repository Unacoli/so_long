/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:15:59 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/01 19:34:46 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_asset(char **map, char *name, t_img *asset, t_vars *vars)
{
	asset->height = 0;
	asset->width = 0;
	asset->img = mlx_xpm_file_to_image(vars->mlx, name, &asset->height,
			&asset->width);
	if (asset->img == NULL)
		ft_quit_solong((void ***)map, "Failed xpm to image\n");
}

void	init_assets(t_assets *assets, t_vars *vars, char **map)
{
	init_asset(map, BACKGROUND, &assets->bg, vars);
	init_asset(map, PLAYER_BG, &assets->player_bg, vars);
	init_asset(map, PLAYER_E, &assets->player_e, vars);
	init_asset(map, PLAYER_S, &assets->player_s, vars);
	init_asset(map, EXIT, &assets->exit, vars);
	init_asset(map, START, &assets->start, vars);
	init_asset(map, ITEM, &assets->item, vars);
	init_asset(map, WALL, &assets->wall, vars);
}
