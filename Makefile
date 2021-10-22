# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nargouse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 14:54:05 by nargouse          #+#    #+#              #
#    Updated: 2021/10/22 18:11:01 by nargouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
INCLUDE = ./so_long/include/so_long.h
CFLAGS	= -g -Wall -Werror -Wextra

SRCS	= ./srcs/ft_so_long.c ./srcs/main.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) -lmlx -framework OpenGL -framework Appkit -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
