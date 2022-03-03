# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 22:41:32 by nargouse          #+#    #+#              #
#    Updated: 2022/03/03 15:19:30 by nargouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
INCLUDE = ./include/
MLX	= ./mlx_linux/libmlx.a
LIBFT	= ./libft/libft.a
LIB	= $(MLX) $(LIBFT)
CFLAGS	+= -Wall -Werror -Wextra
LFLAGS	= -lXext -lX11

FILES	= main.c init_map.c parse_map.c init_mlx.c init_assets.c start_assets.c\
		  handle_player.c move_up.c move_left.c move_right.c move_down.c\
		  key_hook.c destroy_win.c utils.c
FILES_BONUS	=	main_bonus.c init_map_bonus.c parse_map_bonus.c\
				init_mlx_bonus.c init_assets_bonus.c start_assets_bonus.c\
				handle_player_bonus.c move_up_bonus.c move_left_bonus.c \
				move_right_bonus.c move_down_bonus.c key_hook_bonus.c\
				destroy_win_bonus.c utils_bonus.c utils2_bonus.c

SRCS	= $(addprefix ./srcs/, $(FILES))
OBJS	= $(addprefix ./objs/, $(FILES:.c=.o))
SRCS_BONUS	= $(addprefix ./srcs/bonus/, $(FILES_BONUS))
OBJS_BONUS	= $(addprefix ./objs/bonus/, $(FILES_BONUS:.c=.o))

all: $(NAME)

bonus: $(NAME)_bonus

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIB) $(CFLAGS) $(LFLAGS) -o $@

$(NAME)_bonus: $(MLX) $(LIBFT) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(LIB) $(CFLAGS) $(LFLAGS) -o $@

objs/%.o: srcs/%.c
	mkdir -p ./objs/
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

objs/bonus/%.o: srcs/bonus/%.c
	mkdir -p ./objs/bonus/
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(MLX):
	$(MAKE) -C ./mlx_linux

$(LIBFT):
	$(MAKE) --no-print-directory -C ./libft

clean:
	$(MAKE) -C ./mlx_linux clean
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS) 
	$(RM) $(OBJS_BONUS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAME)_bonus
	$(RM) $(MLX)
	$(RM) $(LIBFT)

re:	fclean all

.PHONY:	all bonus clean fclean re
