/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/12 20:58:08 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ARGC_NUM_ERROR 0
# define WRONG_FORMAT 1
# define CANNOT_READ_FILE 2
# define MALLOC_ERROR 3
# define READ_ERROR 4
# define MAP_ERROR 5

#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void    handle_error(int error_reason);
char    *check_file_name(char *file_name);
char    **file_to_char_arr(char file_name[]);
int  ft_strlen(const char *s);
int     ft_strcmp(char *s1, char *s2);
char    *ft_strjoin_free(char *s1, char *s2);
void    check_map(char *map_data, char **map_arr);
char	**ft_split(char const *s, char c);

#endif