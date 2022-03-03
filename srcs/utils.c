/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:35:58 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/03 01:09:18 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	check_av(int ac, char **av)
{
	if (ac != 2)
		ft_quit("Usage: ./so_long <*.ber>\n");
	if (isber(av[1]) == 0)
		ft_quit("Use a .ber file\n");
}

void	put_asset(t_point point, t_img *bg, t_vars *vars, t_img *asset)
{
	mlx_put_image_to_window(vars->mlx, vars->win, asset->img,
		(point.y * bg->width), (point.x * bg->height));
}

void	ft_quit_solong(void ***tab, char *message, t_vars *vars)
{
	free_assets(vars);
	ft_free_tab((void ***)tab);
	ft_quit(message);
}
