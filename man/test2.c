/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/06 23:52:09 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
int    ll(void *p)
{
    static int a = 1;
    int width;
    int height;
    if (a % 2 == 0)
    {
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/enemy1.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
    }
    else 
    {
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/enemy2.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
    }
    a++;
    p++;
    return (0);
}


int    lk(int s ,void *p)
{
     s++;
    static int a;
    int width;
    int height;
    printf("%p\n%p\n%p\n",img_ptr,mlx_ptr, win_ptr);
    if (a % 2 == 0)
    {
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/man_right1.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
    }
    else 
    {
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/man_right2.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
    }
    a++;
    p++;
    return (0);
}

int main(void)
{
    int     width;
    int     height;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "hello world");
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/man_left1.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/man_left2.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 50);
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/man_right1.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 100);
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/man_right2.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 150);
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/man_up1.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 200);
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/man_up2.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 250);
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/man_down1.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 300);
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/man_down2.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 350);
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/square.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 400);
     img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/enemy1.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 450);
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./use_pic/enemy2.xpm", &width, &height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 50, 50);
    mlx_hook(win_ptr, 2, 0, lk, 0);
    mlx_loop(mlx_ptr);
    
    return (0);
}