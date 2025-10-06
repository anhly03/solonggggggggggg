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

MLX = ./minilibx-linux
GNL = ./get_next_line
PRINTF = ./ft_printf

SRCS =	cleanup_and_exit.c final.c game_play.c ..../tu tu bo sung
OBJS = $(SRCS:.c=.o)

GNL_SRCS = $(GNL)/get_next_line.c $(GNL)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)
GNL_LIB = libgnl.a

PRINTF_SRCS = $(PRINTF)/ft_printchar.c $(PRINTF)/ft_printhex.c $(PRINTF)/print_number.c $(PRINTF)/ft_printpercent.c\
				$(PRINTF)/ft_printstr.c $(PRINTF)/ft_printunsigned.c $(PRINTF)/ft_printvoid.c $(PRINTF)/handle.c
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
PRINTF_LIB = libftprintf.a

all: $(GNL_LIB) $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS) $(GNL_LIB) $(PRINTF_LIB)
    $(CC) $(CFLAGS) $(OBJS) -L$(MLX) -lmlx -L. -lgnl -lftprintf -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX) -c $< -o $@

$(GNL_LIB): $(GNL_OBJS)
	ar rcs $@ $^

$(PRINTF_LIB): $(PRINTF_OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS)

fclean: clean
	rm -f $(NAME) $(GNL_LIB) $(PRINTF_LIB)

re: fclean all

.PHONY: all clean fclean re
