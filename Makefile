# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inskim <inskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 08:02:44 by inskim            #+#    #+#              #
#    Updated: 2023/01/24 11:56:37 by inskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

SRC = check_file.c file_to_char_arr.c ft_strjoin_free.c handle_error.c main.c ft_split.c ft_str.c graph.c make_graph.c queue.c check_path.c make_game.c handle_key.c ft_putnbr_fd.c handle_close.c paint.c animation.c
BONUS_SRC = bonus/animation_bonus.c bonus/check_file_bonus.c bonus/check_path_bonus.c bonus/file_to_char_arr_bonus.c bonus/ft_split_bonus.c bonus/ft_str_bonus.c bonus/ft_strjoin_free_bonus.c bonus/graph_bonus.c bonus/handle_close_bonus.c bonus/handle_error_bonus.c bonus/handle_key_bonus.c bonus/main_bonus.c bonus/make_game_bonus.c bonus/make_graph_bonus.c bonus/paint_bonus.c bonus/queue_bonus.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
HEADER = so_long.h
BONUS_HEADER = bonus/so_long_bonus.h
MLX_DIR = ./mlx

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): | MAKE_MAN

bonus: | MAKE_BONUS

MAKE_MAN: $(OBJ) $(HEADER)
	touch MAKE_MAN
	rm -f MAKE_BONUS
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit  

MAKE_BONUS: $(BONUS_OBJ) $(BONUS_HEADER)
	touch MAKE_BONUS
	rm -f MAKE_MAN
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJ) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)
	rm -f MAKE_BONUS MAKE_MAN

fclean:clean
	rm -f $(NAME)

re: fclean
	make all

.phony: all clean fclean re bonus
