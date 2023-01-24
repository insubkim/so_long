/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/24 12:04:19 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_player_image_name(int pressed_key_code)
{
	if (pressed_key_code == 0)
		return ("use_pic/man_left1.xpm");
	else if (pressed_key_code == 1)
		return ("use_pic/man_down1.xpm");
	else if (pressed_key_code == 2)
		return ("use_pic/man_right1.xpm");
	else
		return ("use_pic/man_up1.xpm");
}

void	*get_image(t_mlx_info *mlx_info, int x, int y)
{
	char	c;
	char	*filename;

	c = mlx_info -> map_info -> map_arr[y][x];
	if (c == '1')
		filename = "use_pic/square.xpm";
	else if (c == 'P')
		filename = get_player_image_name(mlx_info -> pressed_key_code);
	else if (c == 'C')
		filename = "use_pic/images.xpm";
	else if (c == 'E')
		filename = "use_pic/exit.xpm";
	else if (c == 'X' || c == 'x')
		filename = "use_pic/enemy1.xpm";
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
