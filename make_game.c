/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/24 00:15:44 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_info -> face_status = 0;
	return (mlx_info);
}

void	*get_image(t_mlx_info *mlx_info, int x, int y)
{
	char	c;
	char	*filename;

	c = mlx_info -> map_info -> map_arr[y][x];
	if (c == '1')
		filename = "use_pic/square.xpm";
	else if (c == 'P')
		filename = "use_pic/man_right1.xpm";
	else if (c == 'C')
		filename = "use_pic/images.xpm";
	else if (c == 'E')
		filename = "use_pic/exit.xpm";
	else
		filename = "use_pic/blank.xpm";
	return (mlx_xpm_file_to_image(mlx_info -> mlx, filename, &x, &y));
}

void	fill_window(t_mlx_info *mlx_info)
{
	int		x;
	int		y;
	int		width;
	int		height;
	char	**map_arr;

	map_arr = mlx_info -> map_info -> map_arr;
	y = 0;
	height = mlx_info -> map_info -> height;
	width = mlx_info -> map_info -> width;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			mlx_put_image_to_window(mlx_info -> mlx, mlx_info -> window, \
					get_image(mlx_info, x, y), x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	make_game(char **map_arr, t_graph *map_graph)
{
	t_map_info	*map_info;
	t_mlx_info	*mlx_info;

	map_info = init_map_info(map_arr, map_graph);
	mlx_info = init_mlx_info(map_info);
	fill_window(mlx_info);
	mlx_hook(mlx_info -> window, 2, 0, handle_key, mlx_info);
	mlx_hook(mlx_info -> window, 17, 0, handle_close, mlx_info);
	mlx_loop(mlx_info -> mlx);
}
