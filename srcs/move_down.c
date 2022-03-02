/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:01:59 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/02 18:25:57 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_down(t_vars *vars)
{
	if (vars->map[vars->point->x - 1][vars->point->y] != '1')
	{
		if (vars->map[vars->point->x - 1][vars->point->y] == '0')
			;
		else if (vars->map[vars->point->x - 1][vars->point->y] == 'P')
			;
		else if (vars->map[vars->point->x - 1][vars->point->y] == 'C')
			;
		else if (vars->map[vars->point->x - 1][vars->point->y] == 'E')
			;
		vars->point->x -= 1;
		return (1);
	}
	return (0);
}
