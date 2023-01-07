/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/06 20:01:17 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

#include <stdio.h>
int	f(int key, void *s)
{
	printf("%s\n", (char*)s);
	printf("%d\n", key);
	return (0);
}

int f2(void *s)
{
	s++;
	printf("loof hook\n");
	return (0);
}

int main(void)
{
	void	*mlx_ptr;
    void    *win_ptr;
    //t_data  img;

	mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Hello world!");
   	
	//int	x ;
	//int y ;
	//img.img = mlx_xpm_file_to_image(mlx_ptr, "../../goinfre/monero.XPM", &x, &y);
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_key_hook(win_ptr, f, (void*)"hi");
	mlx_loop_hook(mlx_ptr, f2, (void*)"hey");
	mlx_loop(mlx_ptr);
}

//맵 분석
//에러 맵 에러 표시
// 맵생성
// 캐릭터, 유닛, 적 생성
// 키 이벤트 받기
// 케릭터 움직임 쉘, 윈도우에 표시