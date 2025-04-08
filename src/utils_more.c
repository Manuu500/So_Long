/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:18:09 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/08 17:47:01 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_pos_vars(t_map_data *map, int map_x, int map_y)
{
	map->coords.map_x = map_x;
    map->coords.map_y = map_y;
}

void	load_map_structure(t_map_data *map)
{
	map->height = 0;
    while (map->map[map->height])
		map->height++;
    if (map->height > 0)
		map->width = ft_strlen(map->map[0]);
    else
		map->width = 0;
}

// void	redraw_map(t_map_data *map)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			place_walls(map, &map->vars, x, y);
// 			x++;
// 		}
// 		y++;
// 	}
// }