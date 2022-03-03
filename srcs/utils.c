/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:35:58 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/03 05:37:57 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_elements(char **map, t_point *point)
{
	if (!(map[point->x][point->y] == 'P' || map[point->x][point->y] == 'E'
						|| map[point->x][point->y] == 'C'
						|| map[point->x][point->y] == '0'
						|| map[point->x][point->y] == '1'))
		ft_quit_solong((void ***)&map, "Wrong elements in map\n", NULL);
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
	if (vars != NULL)
		free_assets(vars);
	ft_free_tab((void ***)tab);
	ft_quit(message);
}
