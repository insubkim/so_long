/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/21 11:10:01 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_graph *init_graph(int vertax_count)
{
    t_graph *graph;
    int     i;
    
    graph = (t_graph*)malloc(sizeof(t_graph));
    if (!graph)
        handle_error(MALLOC_ERROR);
    graph -> vertax_count = vertax_count;
    graph -> adjacency_arr = \
    (t_graph_node **)malloc(sizeof(t_graph_node *)*vertax_count);
    if (!graph -> adjacency_arr)
        handle_error(MALLOC_ERROR);
    i = 0;
    while(i < vertax_count)
        (graph -> adjacency_arr)[i++] = 0;
    return (graph);
}

void    add_edge(t_graph *graph, int from, t_graph_node *to)
{
    to -> next = (graph -> adjacency_arr)[from];
    (graph -> adjacency_arr)[from] = to;
}

t_graph_node    *make_graph_node(int x, int y, int vertax_id)
{
    t_graph_node    *node;

    node = (t_graph_node*)malloc(sizeof(t_graph_node));
    if (!node)
        handle_error(MALLOC_ERROR);
    node -> vertax_id = vertax_id;
    node -> x = x;
    node -> y = y;
    node -> next = 0;
    return (node);
}

void    free_graph(t_graph *graph)
{
    t_graph_node    *node;
    int             i;
    
    i = 0;
    while (i < graph -> vertax_count)
    {
        node = graph -> adjacency_arr[i];
        while (node)
        {
            free(node);
            graph -> adjacency_arr[i] = graph -> adjacency_arr[i] -> next;
            node = graph -> adjacency_arr[i];
        }
        i++;
    }
    free(graph -> adjacency_arr);
    free(graph);
}