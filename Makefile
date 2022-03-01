# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 22:41:32 by nargouse          #+#    #+#              #
#    Updated: 2022/03/01 14:10:08 by nargouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
INCLUDE = ./include/
MLX	= ./mlx_linux/libmlx.a
LIBFT	= ./libft/libft.a
LIB	= $(MLX) $(LIBFT)
CFLAGS	= -Wall -Werror -Wextra -DLINUX
LFLAGS	= -lXext -lX11

FILES	= main.c key_hook.c pixel_put.c init_map.c parse_map.c init_mlx.c\
			put_asset.c start_assets.c
SRCS	= $(addprefix ./srcs/, $(FILES))
OBJS	= $(addprefix ./objs/, $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIB) $(CFLAGS) $(LFLAGS) -o $@

objs/%.o: srcs/%.c
	mkdir -p ./objs/
	$(CC) -I $(INCLUDE) -c $< -o $@

$(MLX):
	$(MAKE) -C ./mlx_linux

$(LIBFT):
	$(MAKE) --no-print-directory -C ./libft

clean:
	$(MAKE) -C ./mlx_linux clean
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(MLX)
	$(RM) $(LIBFT)

re:	fclean all

.PHONY:	all clean fclean re
