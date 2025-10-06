# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phly <phly@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 13:43:11 by phly              #+#    #+#              #
#    Updated: 2025/09/23 18:00:22 by phly             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = 	cc
CFLAGS = 	-Wall -Wextra -Werror
NAME = 		so_long
SRCS =		final.c

OBJS = $(SRCS:.c=.o)

MLX = ./minilibx-linux
GNL = ./get_next_line
PRINTF = ./ft_printf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX) -lmlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

