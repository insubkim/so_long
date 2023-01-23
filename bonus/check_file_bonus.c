/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/23 23:51:16 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*check_file_name(char *file_name)
{
	char	*format;

	format = ft_strrchr(file_name, '.');
	if (!format || ft_strcmp(format, ".ber"))
		handle_error(WRONG_FORMAT);
	return (file_name);
}

void	get_width_height(char **map_arr, int *width, int *height)
{
	int	i;

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

void	check_body(char **map_arr)
{
	int	p_c_e[3];
	int	i;

	p_c_e[0] = 0;
	p_c_e[1] = 0;
	p_c_e[2] = 0;
	while (*(map_arr + 1))
	{
		i = 0;
		while ((*map_arr)[i])
		{
			if ((*map_arr)[i] == 'P')
				p_c_e[0]++;
			else if ((*map_arr)[i] == 'C')
				p_c_e[1]++;
			else if ((*map_arr)[i] == 'E')
				p_c_e[2]++;
			else if (!((*map_arr)[i] == '1' || (*map_arr)[i] == '0'))
				handle_error(MAP_ERROR);
			i++;
		}
		map_arr++;
	}
	if (p_c_e[0] != 1 || p_c_e[1] == 0 || p_c_e[2] != 1)
		handle_error(MAP_ERROR);
}

void	check_wall(char **s, int width, int height)
{
	int	i;

	i = -1;
	while (++i < width)
		if (s[0][i] != '1' || s[height - 1][i] != '1')
			handle_error(MAP_ERROR);
	i = -1;
	while (++i < height)
		if (s[i][0] != '1' || s[i][width - 1] != '1')
			handle_error(MAP_ERROR);
}

void	check_map(char *map_data, char **map_arr)
{
	int	width;
	int	height;

	if (!map_arr || !map_arr)
		handle_error(MAP_ERROR);
	get_width_height(map_arr, &width, &height);
	if (width < 3 || height < 3)
		handle_error(MAP_ERROR);
	if (map_data[ft_strlen(map_data) - 1] != '\n')
		handle_error(MAP_ERROR);
	free(map_data);
	check_wall(map_arr, width, height);
	check_body(map_arr + 1);
}
