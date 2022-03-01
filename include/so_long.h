/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:49:05 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/01 15:45:19 by nargouse         ###   ########.fr       */
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
# include "../libft/include/libft.h"
# define WALL "texturing/wall.xpm"
# define BACKGROUND "texturing/background.xpm"
# define PLAYER "texturing/player.xpm"
# define COLLECTIBLE "texturing/collectible.xpm"
# define EXIT "texturing/exit.xpm"
# define START "texturing/start.xpm"
# define ENNEMI "texturing/ennemi.xpm"

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

typedef struct	s_img
{
	int	*img;
	int	width;
	int	height;
}		t_img;

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

void	pixel_put(t_data *data, int x, int y, int color);
int	key_escp(int keycode, t_vars *vars);
char	**read_map(char *file);
void	check_map(char **map);
void	init_mlx(char **map, t_vars *vars);
t_img	heightwidth(char **map, int *height, int *width, t_vars *vars);
int		put_assets(char **map, t_img *bg, t_vars *vars);
int		put_asset(char *name, t_point point, t_img *bg, t_vars *vars);
void	ft_quit_solong(void ***tab, char *message);

#endif
