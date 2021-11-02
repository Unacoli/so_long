/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:49:05 by nargouse          #+#    #+#             */
/*   Updated: 2021/11/02 17:49:44 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define	SO_LONG_H
# include "../mlx_linux/mlx.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# define XK_MISCELLANY
# define XK_LATIN1
# include <X11/X.h>
# include <X11/keysymdef.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

void	pixel_put(t_data *data, int x, int y, int color);
int	key_hook(int keycode, t_vars *vars);

#endif
