# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nargouse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 14:54:05 by nargouse          #+#    #+#              #
#    Updated: 2021/11/03 17:40:17 by nargouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
INCLUDE = ./include
MLX	= ./mlx_linux/libmlx.a
LIBFT	= ./libft/libft.a
LIB	= $(MLX) $(LIBFT)
CFLAGS	= -Wall -Werror -Wextra -DLINUX
LFLAGS	= -lXext -lX11

SRCS	= ./srcs/main.c ./srcs/key_hook.c ./srcs/pixel_put.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIB) $(LFLAGS) -o $@

srcs/%.o: srcs/%.c
	$(CC) -I $(INCLUDE) -c $< -o $@

$(MLX):
	$(MAKE) -C ./mlx_linux

$(LIBFT):
	$(MAKE) -C ./libft

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
