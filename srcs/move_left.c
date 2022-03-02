/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:52:01 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/02 18:16:43 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_left(t_vars *vars)
{
	if (vars->map[vars->point->x][vars->point->y - 1] != '1')
	{
		if (vars->map[vars->point->x][vars->point->y - 1] == '0')
			;
		else if (vars->map[vars->point->x][vars->point->y - 1] == 'P')
			;
		else if (vars->map[vars->point->x][vars->point->y - 1] == 'C')
			;
		else if (vars->map[vars->point->x][vars->point->y - 1] == 'E')
			;
		vars->point->y -= 1;
		return (1);
	}
	return (0);
}
