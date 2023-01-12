/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/07 09:08:46 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    *ft_strrchr(const char *s, int c)
{
        int     i;

        i = ft_strlen(s);
        while (i >= 0)
                if (s[i--] == (char)c)
                        return ((char *)&(s[++i]));
        return (0);
}

char    *check_file_name(char *file_name)
{
    char    *format;

    format = ft_strrchr(file_name, '.');
    if (!format || !ft_strcmp(format, ".ber"))
        handle_error(WRONG_FORMAT);
    return (file_name);
}

void    get_width_height(char **map_arr, int *width, int *height)
{
    int i;
    
    *width = 0;
    *height = 0;
    i = 0;
    while (*map_arr)
    {
        i = 0;
        (*height)++;
        while ((*map_arr)[i])
            i++;
        if (*width != i && *width != 0)
            handle_error(MAP_ERROR);
        if (*width == 0)
            *width = i;
        map_arr++;
    }
}

void    check_body(char **map_arr)
{
    int player;
    int collectible;
    int exit;
    int i;

    player = 0;
    collectible = 0;
    exit = 0;
    while (*map_arr)
    {
        i = 0;
        while ((*map_arr)[i])
        {
            if ((*map_arr)[i] == 'P')
                player++;
            else if ((*map_arr)[i] == 'E')
                exit++;
            else if ((*map_arr)[i] == 'C')
                collectible++;
            else if (!((*map_arr)[i] == '1' || (*map_arr)[i] == '0'))
                handle_error(MAP_ERROR);
            i++;
        }
        map_arr++;
    }
    if (player != 1 || collectible == 0 || exit != 1)
        handle_error(MAP_ERROR);
}

void    check_map(char *map_data, char **map_arr)
{
    int width;
    int height;
    //null check
    if (!map_arr || !map_arr)
        handle_error(MAP_ERROR);
    //width > 2 , height > 2 체크
    get_width_height(map_arr, &width, &height);
    if (width < 3 || height < 3)
        handle_error(MAP_ERROR);
    //map data 마지막 \n 있는지 체크
    if (!(char *)(ft_strrchr(map_data, '\n') + 1))
        handle_error(MAP_ERROR);
    free(map_data);    
    //free map data
    //1line all wall
    while (*map_arr[0])
        if (*(map_arr[0])++ != '1')
            handle_error(MAP_ERROR);
    while (height)
    //2 ~ last -l line 
    //first is wall last is wall
    //other is o l c p e
    //count c p e
    //c is > 0
    //p and e is 1
    check_body(++map_arr);
    //last is wall
    while (*map_arr[height - 1])
        if (*(map_arr[0])++ != '1')
            handle_error(MAP_ERROR);
}