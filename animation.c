/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/24 01:55:05 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_face(t_mlx_info *mlx_info, int x, int y)
{
	char	*filename;
	int		i;

	if (mlx_info -> pressed_key_code == 0 && mlx_info -> sprite_flag < 15)
		filename = "use_pic/man_left2.xpm";
	else if (mlx_info -> pressed_key_code == 0 && mlx_info -> sprite_flag)
		filename = "use_pic/man_left1.xpm";
	else if (mlx_info -> pressed_key_code == 1 && mlx_info -> sprite_flag < 15)
		filename = "use_pic/man_down2.xpm";
	else if (mlx_info -> pressed_key_code == 1 && mlx_info -> sprite_flag)
		filename = "use_pic/man_down1.xpm";
	else if (mlx_info -> pressed_key_code == 2 && (mlx_info->sprite_flag) < 15)
		filename = "use_pic/man_right2.xpm";
	else if (mlx_info -> pressed_key_code == 2 && mlx_info -> sprite_flag)
		filename = "use_pic/man_right1.xpm";
	else if (mlx_info -> pressed_key_code == 13 && mlx_info -> sprite_flag < 15)
		filename = "use_pic/man_up1.xpm";
	else
		filename = "use_pic/man_up2.xpm";
	mlx_put_image_to_window(mlx_info -> mlx, mlx_info -> window, \
	mlx_xpm_file_to_image(mlx_info -> mlx, "use_pic/blank.xpm", \
	&i, &i), x * 50, y * 50);
	mlx_put_image_to_window(mlx_info -> mlx, mlx_info -> window, \
	mlx_xpm_file_to_image(mlx_info -> mlx, filename, &i, &i), x * 50, y * 50);
}

int	animation(t_mlx_info *mlx_info)
{
	int	x;
	int	y;

	get_player_coord(mlx_info, &x, &y);
	change_face(mlx_info, x, y);
	mlx_info -> sprite_flag++;
	if (mlx_info -> sprite_flag == 30)
		mlx_info -> sprite_flag = !(mlx_info -> sprite_flag);
	return (0);
}
