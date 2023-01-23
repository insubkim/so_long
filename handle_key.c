/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/24 00:14:04 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_coord(t_mlx_info *mlx_info, int *p_x, int *p_y)
{
	int		x;
	int		y;
	char	**map_arr;

	y = 0;
	map_arr = mlx_info -> map_info -> map_arr;
	while (y < mlx_info -> map_info -> height)
	{
		x = 0;
		while (x < mlx_info -> map_info -> width)
		{
			if (map_arr[y][x] == 'P')
			{
				*p_x = x;
				*p_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	no_more_c(char **arr, char c)
{
	int	i;

	while (*arr)
	{
		i = 0;
		while ((*arr)[i])
			if ((*arr)[i++] == c)
				return (0);
		arr++;
	}
	return (1);
}

void	move_player(t_mlx_info *mlx_info, \
		int cur_x, int cur_y, int mov_x, int mov_y)
{
	char	**map_arr;

	map_arr = mlx_info -> map_info -> map_arr;
	map_arr[cur_y][cur_x] = '0';
	if (no_more_c(map_arr, 'E'))
		map_arr[cur_y][cur_x] = 'E';
	if (map_arr[mov_y][mov_x] == '0')
		map_arr[mov_y][mov_x] = 'P';
	else if (map_arr[mov_y][mov_x] == 'C')
		map_arr[mov_y][mov_x] = 'P';
	else if (map_arr[mov_y][mov_x] == 'X')
		handle_close(mlx_info);
	else if (map_arr[mov_y][mov_x] == 'E')
	{
		map_arr[mov_y][mov_x] = 'P';
		if (no_more_c(map_arr, 'C'))
			handle_close(mlx_info);
	}
	else
		map_arr[cur_y][cur_x] = 'P';
}

void	set_map_arr(int keycode, t_mlx_info *mlx_info)
{
	int	x;
	int	y;

	get_player_coord(mlx_info, &x, &y);
	if (keycode == 0)
		move_player(mlx_info, x, y, x - 1, y);
	else if (keycode == 1)
		move_player(mlx_info, x, y, x, y + 1);
	else if (keycode == 2)
		move_player(mlx_info, x, y, x + 1, y);
	else
		move_player(mlx_info, x, y, x, y - 1);
}

int	handle_key(int keycode, t_mlx_info *mlx_info)
{
	if ((0 <= keycode && keycode <= 2) || keycode == 13)
	{
		ft_putnbr_fd(++(mlx_info -> move_count), 1);
		write(1, "\n", 1);
		set_map_arr(keycode, mlx_info);
		fill_window(mlx_info);
		mlx_string_put(mlx_info -> mlx, mlx_info -> window, 25, 25, \
			0x0000ff00, ft_itoa(mlx_info->move_count));
	}
	else if (keycode == 53)
		handle_close(mlx_info);
	return (0);
}

int	handle_close(t_mlx_info *mlx_info)
{
	mlx_destroy_window(mlx_info -> mlx, mlx_info -> window);
	free_arr(mlx_info -> map_info -> map_arr);
	free_graph(mlx_info -> map_info -> map_graph);
	free(mlx_info -> map_info);
	free(mlx_info);
	exit(0);
}
