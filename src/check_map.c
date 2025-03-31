/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:05:36 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/31 17:46:29 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static int	check_map_extension(char	*filename)
{
	char	*word;
	int	file_length;

	file_length = ft_strlen(filename);
	word = ft_strnstr(filename, ".ber", file_length);
	if (word == NULL)
		return (0);
	return (1);
}

static int	check_walls(t_map_data *map)
{
	int	x;
	int	y;
	
	y = 0;
	while (map->map[y])
	{
		x = ft_strlen(map->map[y]) - 1;
		if (map->map[y][0] != '1' || map->map[y][x] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (map->map[0][x] && map->map[y - 1][x])
	{
		if (map->map[0][x] != '1' || map->map[y - 1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

void	check_map(t_map_data *map)
{
	if (!check_walls(map))
	{
		exit(EXIT_FAILURE);
		//Despues liberar memoria del mapa
	}
	if (!check_map_extension(map->map_name))
	{
		perror("El nombre del archivo no es un .ber");
		exit(EXIT_FAILURE);
	}
}
