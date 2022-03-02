/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:43:18 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/02 18:15:13 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_count(t_vars *vars)
{
	vars->count += 1;
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
//	else if (keycode == XK_a || keycode == XK_A)
//		ret = move_left(vars);
//	else if (keycode == XK_d || keycode == XK_D)
//		ret = move_right(vars);
//	else if (keycode == XK_s || keycode == XK_S)
//		ret = move_down(vars);
	if (ret == 1)
		print_count(vars);
	return (0);
}
