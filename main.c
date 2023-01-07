/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/07 09:08:43 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **file_to_char_arr(char file_name[])
{
    //open file

    //get next line until end;

    //return char **arr
}

void    check_map(char **map_arr)
{
    //check map null

    //get map width

    //firt row should be all wall

    //2~ last -1 should be wall  ... wall

    //last row should be all wall

    //all row should have same width

    //all char chould be wall, empthy, player, collectible, exit
    //last should be '\n'
    //p,e should be only 1
    //c should be larger than one
}

t_graph *make_graph(char **map_arr)
{
    //make map into graph
}

void    check_path(t_graph *map_graph)
{
    //check path to collectible and exit
}

void    make_game(char **map_arr, t_graph *graph)
{
    //init mlx window
    //set game
    //if bonus make enemy if possible
    //hook key
    //loop
}

int main(int argc, char *argv[])
{
    char    **map_arr;
    t_graph *map_graph;
    //vertax list
    //edge list
    //adjacency list

    //argc != 2
    //print error

    //file to char arr

    //check_map

    //make_graph

    //check_path

    //make game

    return (0);
}