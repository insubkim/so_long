/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.close_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/24 01:59:50 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_close(t_mlx_info *mlx_info)
{
	mlx_destroy_window(mlx_info -> mlx, mlx_info -> window);
	free_arr(mlx_info -> map_info -> map_arr);
	free_graph(mlx_info -> map_info -> map_graph);
	free(mlx_info -> map_info);
	free(mlx_info);
	exit(0);
}
