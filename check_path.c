/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/21 10:57:44 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int *get_vertax_id_by_char(t_graph *map_graph, char **map_arr, char c)
{
    int i;
    int j;
    int k;
    int width_height[2];
    int *arr;

    arr = (int *)malloc(sizeof(int) * (map_graph -> vertax_count + 1));
    if (!arr)
        handle_error(MALLOC_ERROR);
    ft_memset(arr, -1, sizeof(int) * (map_graph -> vertax_count + 1));
    get_width_height(map_arr, width_height, width_height + 1);
    i = 0;
    k = 0;
    while (map_arr[i])
    {
        j = 0;
        while (map_arr[i][j])
        {
            if (map_arr[i][j] == c)
                arr[k++] = (i - 1) * (width_height[0] - 2) + (j - 1);
            j++;
        }
        i++;
    }
    return (arr);
}

int is_in_visited(t_node    *node_visitied, int vertax_id)
{
    while (node_visitied)
    {
        if (node_visitied -> data == vertax_id)
            return (1);
        node_visitied = node_visitied -> back;
    }
    return (0);
}

void    check_visited(t_node *visited, t_graph *map_graph, char **map_arr, char c)
{
    int *vertax_id;
    int     i;

    vertax_id = get_vertax_id_by_char(map_graph, map_arr, c);
    i = 0;
    while (vertax_id[i] != -1)
    {
        if (!is_in_visited(visited, vertax_id[i]))
            handle_error(NO_PATH_ERROR);
        i++;
    }
    free(vertax_id);
}

void    check_c_e_visited(t_node *visited, t_graph *map_graph, char **map_arr)
{
    check_visited(visited, map_graph, map_arr, 'C');
    check_visited(visited, map_graph, map_arr, 'E');
    free_linked_list(visited);
}

void    check_path(t_graph *map_graph, char **map_arr)
{
    t_queue *queue;
    int     *vertax_id;
    t_node  *current;
    t_node  *node_visited;
    t_graph_node *node;

    vertax_id = get_vertax_id_by_char(map_graph, map_arr, 'P');
    queue = init_queue();
    enqueue(queue, make_node(*vertax_id));
    free(vertax_id);
    node_visited = 0;
    while (queue -> front)
    {
        current = dequeue(queue);
        node = map_graph -> adjacency_arr[current -> data];
        while (node)
        {
            if (!is_in_visited(node_visited, node -> vertax_id))
                enqueue(queue, make_node(node -> vertax_id));
            node = node -> next;
        }
        current -> back = node_visited;
        node_visited = current;
    }
    check_c_e_visited(node_visited, map_graph, map_arr);
    free(queue);
}