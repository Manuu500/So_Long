/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:05:36 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/31 14:20:59 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Debug

static int	check_walls(t_map_data *map)
{
	int	x;
	int	y;
	
	y = 0;
	while (map->map[y + 1])
	{
		x = ft_strlen(map->map[y]) - 1;
		if (map->map[y][0] != '1' || map->map[y][x] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (map->map[x + 1])
	{
		if (map->map[0][x] != '1' || map->map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

void	check_map(t_map_data *map)
{
	if (!check_walls(map))
	{
		//Despues liberar memoria
		return (perror("Las paredes están mal"));
	}
}
