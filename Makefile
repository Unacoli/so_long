# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nargouse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 14:54:05 by nargouse          #+#    #+#              #
#    Updated: 2021/11/02 13:27:09 by nargouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
INCLUDE = -L. mlx_linux/libmlx.a -lXext -lX11 -lm -lbsd -lpthread
LIB	= ./mlx_linux/libmlx.a
CFLAGS	= -Wall -Werror -Wextra -DLINUX

SRCS	= ./srcs/ft_so_long.c ./srcs/main.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): minilibx $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(LIB)

.c.o :
	$(CC) -w $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o) $(LIB)

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
