/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:43:18 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/03 04:50:20 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	print_count(t_vars *vars)
{
	char	*count;
	t_point	reprint;

	vars->count += 1;
	reprint.x = 0;
	reprint.y = 0;
	put_asset(reprint, vars->assets->bg, vars, vars->assets->wall);
	count = ft_itoa(vars->count);
	if (count == NULL)
		ft_quit_solong((void ***)&vars->map, "Malloc error\n", vars);
	mlx_string_put(vars->mlx, vars->win, 25, 25, 0x00FFFFFF, count);
	free(count);
	if (vars->count > 1)
		ft_putstr("\033[A\033[2K");
	ft_putnbr(vars->count);
	write(1, "\n", 1);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	ret;

	ret = 0;
	if (keycode == XK_Escape)
		win_close(vars);
	else if (keycode == XK_w || keycode == XK_W)
		ret = move_up(vars);
	else if (keycode == XK_a || keycode == XK_A)
		ret = move_left(vars);
	else if (keycode == XK_d || keycode == XK_D)
		ret = move_right(vars);
	else if (keycode == XK_s || keycode == XK_S)
		ret = move_down(vars);
	if (ret == 1)
		print_count(vars);
	return (0);
}
