/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:18:09 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/22 20:27:42 by mruiz-ur         ###   ########.fr       */
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
	int	x;
	int	y;

	map->height = 0;
	while (map->map[map->height])
		map->height++;
	if (map->height > 0)
		map->width = ft_strlen(map->map[0]);
	else
		map->width = 0;
	map->vars.coins_num = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->map[y][x] != '\0')
		{
			if (map->map[y][x] == 'C')
				map->vars.coins_num++;
			x++;
		}
		y++;
	}
	allocate_coins(map);
}

void	clean_close(t_map_data *map)
{
	if (!map->vars.coins)
		free_coins(map);
	if (!map->map)
		free_map(map->map, map->height);
	mlx_terminate(map->vars.mlx);
	exit(SUCCESS);
}

void	close_window_x(void	*param)
{
	t_map_data	*map;

	map = (t_map_data *)param;
	clean_close(map);
	mlx_terminate(map->vars.mlx);
	exit(SUCCESS);
}

void	create_pos_copy(t_map_data *map, int x, int y)
{
	if (map->map[y][x] == 'P')
	{
		map->vars.player_x_copy = x;
		map->vars.player_y_copy = y;
	}
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