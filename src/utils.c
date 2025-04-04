/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:13:01 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/04 19:50:52 by mruiz-ur         ###   ########.fr       */
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

void	read_matrix(t_map_data *map, int *p_count, int *c_count, int *e_count)
{
    int	y;
    int	x;

	*c_count = 0;
    *p_count = 0;
    *e_count = 0;
    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->map[y][x] == 'P')
                (*p_count)++;
            else if (map->map[y][x] == 'E')
                (*e_count)++;
			else if (map->map[y][x] == 'C')
				(*c_count)++;
			x++;
        }
        y++;
    }
}

char	**duplicate_map(t_map_data *map, int height)
{
    int	y;
    
    y = 0;
    map->map_copy = malloc(sizeof(char *) * (height + 1));
    if (!map->map_copy)
    {
        printf("NO SE HA GUARDADO LA COPIA DEL MAPA");
        exit(EXIT_FAILURE);
    }
    while (y < height)
    {
        map->map_copy[y] = ft_strdup(map->map[y]);
        if (!map->map_copy[y])
        {
            printf("NO SE HA CARGADO LA FILA EN EL DUPLICADO");
            exit(EXIT_FAILURE);
        }
        y++;
    }
    map->map_copy[height] = NULL;
    return (map->map_copy);
}

void	initialize_var(t_map_data *map)
{
	map->vars.coin_count = 0;
}