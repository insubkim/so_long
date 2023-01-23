/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/24 04:18:59 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_map_info	*init_map_info(char **map_arr, t_graph *map_graph)
{
	t_map_info	*map_info;

	map_info = (t_map_info *)malloc(sizeof(t_map_info));
	if (!map_info)
		handle_error(MALLOC_ERROR);
	map_info -> map_arr = map_arr;
	map_info -> map_graph = map_graph;
	get_width_height(map_arr, &(map_info -> width), &(map_info -> height));
	return (map_info);
}

t_mlx_info	*init_mlx_info(t_map_info *map_info)
{
	t_mlx_info	*mlx_info;

	mlx_info = (t_mlx_info *)malloc(sizeof(t_mlx_info));
	if (!mlx_info)
		handle_error(MALLOC_ERROR);
	mlx_info -> map_info = map_info;
	mlx_info -> mlx = mlx_init();
	mlx_info -> window = mlx_new_window(mlx_info ->mlx, \
			(map_info -> width) * 50, (map_info -> height) * 50, "so_long");
	mlx_info -> move_count = 0;
	mlx_info -> pressed_key_code = 2;
	mlx_info -> sprite_flag = 0;
	return (mlx_info);
}

void	make_enemy(t_map_info *map_info)
{
	int		x;
	int		y;
	char	**arr;

	x = 0;
	arr = map_info -> map_arr;
	while (x < map_info -> width)
	{
		y = 0;
		while (y < map_info -> height)
		{
			while (y < map_info -> height && arr[y][x] != '0')
				y++;
			if (y + 3 < map_info -> height && arr[y + 1][x] == '0' \
					&& arr[y + 2][x] == '0' && arr[y + 3][x] == '0')
			{
				arr[y][x] = 'X';
				y = y + 3;
			}
			y++;
		}
		x = x + 2;
	}
}

void	make_game(char **map_arr, t_graph *map_graph)
{
	t_map_info	*map_info;
	t_mlx_info	*mlx_info;

	map_info = init_map_info(map_arr, map_graph);
	mlx_info = init_mlx_info(map_info);
	make_enemy(map_info);
	fill_window(mlx_info);
	mlx_hook(mlx_info -> window, 2, 0, handle_key, mlx_info);
	mlx_hook(mlx_info -> window, 17, 0, handle_close, mlx_info);
	mlx_loop_hook(mlx_info -> mlx, animation, mlx_info);
	mlx_loop(mlx_info -> mlx);
}
