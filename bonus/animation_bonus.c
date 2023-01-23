/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/24 04:17:57 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	change_face(t_mlx_info *mlx_info, int x, int y)
{
	char	*filename;
	int		i;

	if (mlx_info -> pressed_key_code == 0 && mlx_info -> sprite_flag < 15)
		filename = "../use_pic/man_left2.xpm";
	else if (mlx_info -> pressed_key_code == 0 && mlx_info -> sprite_flag)
		filename = "../use_pic/man_left1.xpm";
	else if (mlx_info -> pressed_key_code == 1 && mlx_info -> sprite_flag < 15)
		filename = "../use_pic/man_down2.xpm";
	else if (mlx_info -> pressed_key_code == 1 && mlx_info -> sprite_flag)
		filename = "../use_pic/man_down1.xpm";
	else if (mlx_info -> pressed_key_code == 2 && (mlx_info->sprite_flag) < 15)
		filename = "../use_pic/man_right2.xpm";
	else if (mlx_info -> pressed_key_code == 2 && mlx_info -> sprite_flag)
		filename = "../use_pic/man_right1.xpm";
	else if (mlx_info -> pressed_key_code == 13 && mlx_info -> sprite_flag < 15)
		filename = "../use_pic/man_up1.xpm";
	else
		filename = "../use_pic/man_up2.xpm";
	mlx_put_image_to_window(mlx_info -> mlx, mlx_info -> window, \
	mlx_xpm_file_to_image(mlx_info -> mlx, "../use_pic/blank.xpm", \
	&i, &i), x * 50, y * 50);
	mlx_put_image_to_window(mlx_info -> mlx, mlx_info -> window, \
	mlx_xpm_file_to_image(mlx_info -> mlx, filename, &i, &i), x * 50, y * 50);
}

void	move_enemy_up(t_mlx_info *mlx_info, int x, int y)
{
	char	**arr;

	arr = mlx_info -> map_info -> map_arr;
	if (arr[y - 1][x] == 'P')
		handle_close(mlx_info);
	else if (arr[y - 1][x] == '1' || arr[y - 1][x] == 'E' || \
	arr[y - 1][x] == 'C')
		arr[y][x] = 'x';
	else
	{
		arr[y][x] = '0';
		arr[y - 1][x] = 'X';
		mlx_put_image_to_window(mlx_info -> mlx, mlx_info -> window, \
		get_image(mlx_info, x, y), x * 50, y * 50);
		mlx_put_image_to_window(mlx_info -> mlx, mlx_info -> window, \
		get_image(mlx_info, x, y - 1), x * 50, (y - 1) * 50);
	}
}

void	move_enemy_down(t_mlx_info *mlx_info, int x, int y)
{
	char	**arr;

	arr = mlx_info -> map_info -> map_arr;
	if (arr[y + 1][x] == 'P')
		handle_close(mlx_info);
	else if (arr[y + 1][x] == '1' || arr[y + 1][x] == 'E' || \
	arr[y + 1][x] == 'C')
		arr[y][x] = 'X';
	else
	{
		arr[y][x] = '0';
		arr[y + 1][x] = 'x';
		mlx_put_image_to_window(mlx_info -> mlx, mlx_info -> window, \
		get_image(mlx_info, x, y), x * 50, y * 50);
		mlx_put_image_to_window(mlx_info -> mlx, mlx_info -> window, \
		get_image(mlx_info, x, y +1), x * 50, (y + 1) * 50);
	}
}

void	move_enemy(t_mlx_info *mlx_info)
{
	int	x;
	int	y;

	x = 1;
	while (x < mlx_info -> map_info -> width)
	{
		y = 1;
		while (y < mlx_info -> map_info -> height)
		{
			if (mlx_info -> map_info -> map_arr[y][x] == 'X')
			{
				move_enemy_up(mlx_info, x, y);
				break ;
			}
			else if (mlx_info -> map_info -> map_arr[y][x] == 'x')
			{
				move_enemy_down(mlx_info, x, y);
				break ;
			}	
			y++;
		}
		x++;
	}
}

int	animation(t_mlx_info *mlx_info)
{
	int	x;
	int	y;

	get_player_coord(mlx_info, &x, &y);
	change_face(mlx_info, x, y);
	if (mlx_info -> sprite_flag == 29)
		move_enemy(mlx_info);
	mlx_info -> sprite_flag++;
	if (mlx_info -> sprite_flag == 30)
		mlx_info -> sprite_flag = !(mlx_info -> sprite_flag);
	return (0);
}
