# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nargouse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 14:54:05 by nargouse          #+#    #+#              #
#    Updated: 2021/11/02 17:43:24 by nargouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
INCLUDE = ./include/so_long.h
LIB	= ./mlx_linux/libmlx.a
CFLAGS	= -Wall -Werror -Wextra -DLINUX
LFLAGS	= -lXext -lX11

SRCS	= ./srcs/main.c ./srcs/key_hook.c ./srcs/pixel_put.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): minilibx $(OBJS)
	$(CC) $(OBJS) $(LIB) $(LFLAGS) -o $@

srcs/%.o : srcs/%.c
	$(CC) $(LIB) -c $< -o $@

minilibx :
	$(MAKE) -C ./mlx_linux

clean:
	$(MAKE) -C ./mlx_linux/. clean
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) ./mlx_linux/libmlx.a

re:	fclean all

.PHONY:	all clean fclean re
