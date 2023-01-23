/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/24 04:19:15 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define ARGC_NUM_ERROR 0
# define WRONG_FORMAT 1
# define CANNOT_READ_FILE 2
# define MALLOC_ERROR 3
# define READ_ERROR 4
# define MAP_ERROR 5
# define NO_PATH_ERROR 6
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_graph_node
{
	int						vertax_id;
	int						x;
	int						y;
	struct s_graph_node		*next;
}	t_graph_node;

typedef struct s_graph
{
	int				vertax_count;
	t_graph_node	**adjacency_arr;
}	t_graph;

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*back;
}	t_node;

typedef struct s_queue
{
	t_node	*front;
	t_node	*rear;
}	t_queue;

typedef struct s_map_info
{
	char	**map_arr;
	t_graph	*map_graph;
	int		width;
	int		height;
}	t_map_info;

typedef struct s_mlx_info
{
	t_map_info	*map_info;
	void		*mlx;
	void		*window;
	int			move_count;
	int			pressed_key_code;
	int			sprite_flag;
}	t_mlx_info;

void			handle_error(int error_reason);
char			*check_file_name(char *file_name);
char			**file_to_char_arr(char file_name[]);
int				ft_strlen(const char *s);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strjoin_free(char *s1, char *s2);
void			check_map(char *map_data, char **map_arr);
char			**ft_split(char const *s, char c);
char			*ft_strrchr(const char *s, int c);
void			get_width_height(char **map_arr, int *width, int *height);
t_graph			*init_graph(int vertax_count);
void			add_edge(t_graph *graph, int from, t_graph_node *to);
t_graph_node	*make_graph_node(int x, int y, int vertax_id);
t_graph			*make_graph(char **map_arr);
t_queue			*init_queue(void);
void			enqueue(t_queue *queue, t_node *node);
t_node			*dequeue(t_queue *queue);
t_node			*make_node(int data);
void			check_path(t_graph *map_graph, char **map_arr);
void			*ft_memset(void *b, int c, int len);
void			free_linked_list(t_node *node);
void			make_game(char **map_arr, t_graph *map_graph);
void			free_graph(t_graph *graph);
int				handle_key(int keycode, t_mlx_info *mlx_info);
int				handle_close(t_mlx_info *mlx_info);
void			free_arr(char **arr);
void			fill_window(t_mlx_info *mlx_info);
void			ft_putnbr_fd(int nb, int fd);
char			*ft_itoa(int n);
int				handle_close(t_mlx_info *mlx_info);
void			get_player_coord(t_mlx_info *mlx_info, int *p_x, int *p_y);
int				animation(t_mlx_info *mlx_info);
void			*get_image(t_mlx_info *mlx_info, int x, int y);

#endif
