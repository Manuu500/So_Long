/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:05:36 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/27 17:32:05 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_coin_sur(t_map_data *map, int	x,	int y)
{	
	if (x < 0 || y < 0 || x > map->width || y > map->height)
		return;
	if (map->map[y][x] != 'C')
		return;
	map->map[y][x] = 'V';
	if (map->map[y - 1][x] == '1'
		&& map->map[y + 1][x] == '1'
		&& map->map[y][x - 1] == '1'
		&& map->map[y][x + 1] == '1')
		exit(EXIT_FAILURE);
}
