# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inskim <inskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 08:02:44 by inskim            #+#    #+#              #
#    Updated: 2023/01/23 23:45:34 by inskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

SRC = check_file.c file_to_char_arr.c ft_strjoin_free.c handle_error.c main.c ft_split.c ft_str.c graph.c make_graph.c queue.c check_path.c make_game.c handle_key.c ft_putnbr_fd.c
BONUS_SRC = main.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
HEADER = so_long.h
BONUS_HEADER = so_long_bonus.h
MLX_DIR = ./mlx

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

MAKE_BONUS: $(BONUS_OBJ) $(BONUS_HEADER)
	touch MAKE_BONUS
	$(CC) $(CFLAGS) $(BONUS_OBJ) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

bonus: | MAKE_BONUS

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)
	rm -f MAKE_BONUS

fclean:clean
	rm -f $(NAME)

re: fclean
	make all

.phony: all clean fclean re bonus