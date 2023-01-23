/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/23 23:52:38 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_read(int fd, char buf[], int read_size)
{
	int	read_bytes;

	read_bytes = read(fd, buf, read_size);
	if (read_bytes < 0)
		handle_error(READ_ERROR);
	return (read_bytes);
}

char	*read_map_file(int fd)
{
	char	*map_data;
	char	buf[1024];
	int		read_bytes;

	read_bytes = 1;
	map_data = 0;
	while (read_bytes > 0)
	{
		read_bytes = ft_read(fd, buf, 1023);
		buf[read_bytes] = 0;
		map_data = ft_strjoin_free(map_data, buf);
	}
	return (map_data);
}

char	**file_to_char_arr(char file_name[])
{
	int		fd;
	char	**map_arr;
	char	*map_data;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		handle_error(CANNOT_READ_FILE);
	map_data = read_map_file(fd);
	map_arr = ft_split(map_data, '\n');
	if (!map_arr)
		handle_error(MALLOC_ERROR);
	check_map(map_data, map_arr);
	return (map_arr);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
