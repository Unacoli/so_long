/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:49:05 by nargouse          #+#    #+#             */
/*   Updated: 2022/03/03 12:54:37 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
# define PLAYER_BG "texturing/player_bg.xpm"
# define PLAYER_S "texturing/player_s.xpm"
# define PLAYER_E "texturing/player_e.xpm"
# define PLAYER_C "texturing/player_c.xpm"
# define ITEM "texturing/collectible.xpm"
# define EXIT "texturing/exit.xpm"
# define START "texturing/start.xpm"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_img
{
	int	*img;
	int	width;
	int	height;
}		t_img;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_assets
{
	t_img	*bg;
	t_img	*player_bg;
	t_img	*player_e;
	t_img	*player_s;
	t_img	*player_c;
	t_img	*exit;
	t_img	*start;
	t_img	*item;
	t_img	*wall;
}		t_assets;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_assets	*assets;
	t_data		*img;
	char		**map;
	t_point		*point;
	int			count;
	int			n_item;
}		t_vars;

void	check_av(int ac, char **av);
char	**read_map(char *file);
void	check_map(char **map, t_vars *vars);
void	check_elements(char **map, t_point *point);

void	init_mlx(t_assets *assets, char **map, t_vars *vars);
void	init_asset(char **map, char *name, t_img *asset, t_vars *vars);
void	init_assets(t_assets *assets, t_vars *vars, char **map);

void	put_asset(t_point point, t_img *asset, t_vars *vars, t_img *bg);
void	put_assets(char **map, t_assets *assets, t_vars *vars);

void	init_player(t_assets *assets, char **map, t_vars *vars);

int		key_hook(int keycode, t_vars *vars);
int		move_up(t_vars *vars);
int		move_left(t_vars *vars);
int		move_right(t_vars *vars);
int		move_down(t_vars *vars);
int		win_close(t_vars *vars);

void	free_assets(t_vars *vars);
void	ft_quit_solong(void ***tab, char *message, t_vars *vars);

#endif
