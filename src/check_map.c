/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:05:36 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/04 20:21:22 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_duplicate(t_map_data *map)
{
	int	e_count;
	int	p_count;
	int	c_count;
	
	read_matrix(map, &p_count, &c_count, &e_count);
	printf("Numero personajes: %d, Numero salidas: %d, Numero monedas: %d", p_count, e_count, c_count);
	if ((p_count > 1 || e_count > 1) || (p_count < 1 ||
		e_count < 1 || c_count < 1))
		return (0);
	map->vars.collec_count = c_count + e_count;
	printf("El numero total de coleccionables que hay son: %d\n", map->vars.collec_count);
	return (1);
}

int	check_map_extension(char	*filename)
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

static int	check_path(t_map_data *map, int x, int y, int *count)
{
	if (x < 0 || y < 0 || y >= map->height || x >= map->width)
		return (0);
	if (map->map_copy[y][x] == '1' || map->map_copy[y][x] == '*')
		return (0);
	if (map->map_copy[y][x] == 'E' || map->map_copy[y][x] == 'C')
		(*count)++;
	printf("La funcion 'check_path' ha contado el siguiente numero de coleccionables: %d\n", *count);
	map->map_copy[y][x] = '*';
	check_path(map, x, y - 1, count);
    check_path(map, x, y + 1, count);
    check_path(map, x + 1, y, count);
    check_path(map, x - 1, y, count);
	return (*count);
}

void	check_map(t_map_data *map)
{
	int	count;

	count = 0;
	if (!check_walls(map))
	{
		exit(EXIT_FAILURE);
		perror("Las paredes fallan");
	}
	if (!check_map_extension(map->map_name))
	{
		perror("El nombre del archivo no es un .ber");
		exit(EXIT_FAILURE);
	}
	if (!check_duplicate(map))
	{
		perror("Hay duplicados");
		exit(EXIT_FAILURE);
	}
	if (!check_coin_surround(map))
	{
		perror("Una moneda es inaccesible");
		exit(EXIT_FAILURE);
	}
	map->vars.all_collec_count = check_path(map, 1, 1, &count);
	check_num_collec(map, &count);
}
