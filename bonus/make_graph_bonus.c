/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_graph_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/24 01:59:37 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_adjacency_arr(char **map_arr, int width, int height, \
		t_graph *map_graph)
{
	int	i;
	int	j;

	i = 0;
	while (++i < height - 1)
	{
		j = 0;
		while (++j < width - 1)
		{
			if (map_arr[i][j] == '1')
				continue ;
			if (map_arr[i - 1][j] != '1')
				add_edge(map_graph, (i - 1) * (width - 2) + (j - 1), \
				make_graph_node(j - 1, i - 2, (i - 2) * (width - 2) + (j - 1)));
			if (map_arr[i][j + 1] != '1')
				add_edge(map_graph, (i - 1) * (width - 2) + (j - 1), \
				make_graph_node(j, i - 1, (i - 1) * (width - 2) + (j)));
			if (map_arr[i + 1][j] != '1')
				add_edge(map_graph, (i - 1) * (width - 2) + (j - 1), \
				make_graph_node(j - 1, i, (i) * (width - 2) + (j - 1)));
			if (map_arr[i][j - 1] != '1')
				add_edge(map_graph, (i - 1) * (width - 2) + (j - 1), \
				make_graph_node(j - 2, i - 1, (i - 1) * (width - 2) + (j - 2)));
		}
	}
}

t_graph	*make_graph(char **map_arr)
{
	t_graph	*map_graph;
	int		width;
	int		height;

	get_width_height(map_arr, &width, &height);
	map_graph = init_graph((width - 2) * (height - 2));
	if (!map_graph)
		handle_error(MALLOC_ERROR);
	set_adjacency_arr(map_arr, width, height, map_graph);
	return (map_graph);
}
