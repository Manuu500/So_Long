/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:13:01 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/27 16:11:32 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(t_vars *vars, t_map_data *map, int map_x, int map_y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	(void) map_x;
	(void) map_y;
	if (vars->coin_count == 4)
	{
		while (y < map->height)
		{
			x = 0;
			while (x < map->width)
			{
				if (map->map[y][x] == 'E' )
					place_exit(vars, map);
				x++;
			}	
			y++;
		}
	}
}

int	go_to_exit(t_vars *vars, t_map_data *map, int map_x, int map_y)
{
	if (vars->coin_count == 4)
	{
		if (map->map[map_y - 1][map_x] == 'E' && vars->keydata.key == MLX_KEY_W)
		{
			mlx_terminate(vars->mlx);
			exit(EXIT_SUCCESS);
		}
		if (map->map[map_y + 1][map_x] == 'E' && vars->keydata.key == MLX_KEY_S)
		{
			mlx_terminate(vars->mlx);
			exit(EXIT_SUCCESS);
		}
		if (map->map[map_y][map_x - 1] == 'E' && vars->keydata.key == MLX_KEY_A)
		{
			mlx_terminate(vars->mlx);
			exit(EXIT_SUCCESS);
		}
		if (map->map[map_y][map_x + 1] == 'E' && vars->keydata.key == MLX_KEY_D)
		{
			mlx_terminate(vars->mlx);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
