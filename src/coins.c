/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:14:31 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/22 20:27:55 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_coin(t_vars *vars, t_map_data *map, int map_x, int map_y)
{
	int	counter;
	int	i;

	counter = 0;
	if (map->map[map_y][map_x] == 'C')
	{
		vars->image->instances->enabled = false;
		map->map[map_y][map_x] = '0';
		i = 0;
		while (i < vars->num_coins)
		{
			if (vars->coins[i] && vars->coins[i]->map_x == map_x
				&& vars->coins[i]->map_y == map_y)
			{
				mlx_delete_image(vars->mlx, vars->coins[i]->image);
				free(vars->coins[i]);
				vars->coins[i] = NULL;
				break ;
			}
			i++;
		}
		load_protagonist(map, vars->player_x, vars->player_y);
		counter++;
	}
	return (counter);
}

int	check_coin_surround(t_map_data *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'C')
			{
				if (map->map[y - 1][x] == '1' &&
					map->map[y + 1][x] == '1' &&
					map->map[y][x - 1] == '1' &&
					map->map[y][x + 1] == '1')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	allocate_coins(t_map_data *map)
{
	map->vars.coins = malloc(sizeof(t_coin *) * map->vars.coins_num);
	if (!map->vars.coins)
		ft_error(map, "Failed to allocate memory for coins");
}
