/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/24 00:10:23 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	**map_arr;
	t_graph	*map_graph;

	if (argc != 2)
		handle_error(ARGC_NUM_ERROR);
	map_arr = file_to_char_arr(check_file_name(argv[1]));
	map_graph = make_graph(map_arr);
	check_path(map_graph, map_arr);
	make_game(map_arr, map_graph);
	free_arr(map_arr);
	free_graph(map_graph);
	return (0);
}
