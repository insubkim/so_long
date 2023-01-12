# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 08:02:44 by inskim            #+#    #+#              #
#    Updated: 2023/01/12 21:14:36 by inskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRC = check_file.c file_to_char_arr.c ft_strjoin_free.c handle_error.c main.c ft_split.c ft_str.c
OBJ = $(SRC:.c=.o)
HEADER = so_long.h
MLX_DIR = ./mlx_linux

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

all: $(NAME)


$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -L$(MLX_DIR) -L/usr/lib -lmlx -lX11 -lm -lz -o $(NAME)


$(NAMEs): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re: fclean
	make all

.phony: all clean fclean re bonus