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

void    handle_error(int error_reason)
{
    if (ARGC_NUM_ERROR == error_reason)
        write(2, "input only one file name\n", ft_strlen("input only one file name\n"));
    else if (WRONG_FORMAT == error_reason)
        write(2, "file name should end with .ber\n", ft_strlen("file name should end with .ber\n"));
    else if (CANNOT_READ_FILE == error_reason)
        write(2, "cannot read file\n", ft_strlen("cannot read file\n"));
    else if (MALLOC_ERROR == error_reason)
        write(2, "malloc error\n", ft_strlen("malloc error\n"));
    else if (MALLOC_ERROR == error_reason)
        write(2, "malloc() error\n", ft_strlen("malloc() error\n"));
    else if (READ_ERROR == error_reason)
        write(2, "read() error\n", ft_strlen("read() error\n"));
    else if (MAP_ERROR == error_reason)
        write(2, "map error\n", ft_strlen("map error\n"));
    else if (NO_PATH_ERROR == error_reason)
        write(2, "no path error\n", ft_strlen("no path error\n"));    
    exit(0);
}