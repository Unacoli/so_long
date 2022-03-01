/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_asset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:48:24 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/01 14:15:10 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_asset(char *name, t_point point, t_img *bg, t_vars *vars)
{
	t_img	asset;

	asset.img = mlx_xpm_file_to_image(vars->mlx, name, &bg->height, &bg->width);
	if (asset.img == NULL)
		return (-1);
	mlx_put_image_to_window(vars->mlx, vars->win, asset.img,
		(point.y * bg->width), (point.x * bg->height));
	return (0);
}
