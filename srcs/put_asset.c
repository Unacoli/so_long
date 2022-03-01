/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_asset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:48:24 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/01 17:17:14 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_asset(t_point point, t_img *asset, t_vars *vars, t_img *bg)
{
	mlx_put_image_to_window(vars->mlx, vars->win, asset->img,
		(point.y * bg->width), (point.x * bg->height));
}
