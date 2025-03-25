/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:13:01 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/25 15:50:13 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_exit(t_vars *vars, t_map_data *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (vars->coin_count == 4)
	{
		while (y < map->height)
		{
			x = 0;
			while (x < map->width)
			{
				if (map->map[y][x] == 'E')
					place_exit(vars, map, x, y);
				x++;
			}	
			y++;
		}
	}
}

void	place_exit(t_vars *vars, t_map_data *map, int x, int y)
{
	mlx_texture_t *texture;
	mlx_image_t *image;
	
	texture = mlx_load_png("textures/gatico.png");
	if (!texture)
	{
		printf("No se ha encontardo la textura");
	}
	image = mlx_texture_to_image(vars->mlx, texture); 
	mlx_resize_image(image, IMAGE_SIZE, IMAGE_SIZE);
	mlx_image_to_window(vars->mlx, image, x * IMAGE_SIZE + map->offset_x , y * IMAGE_SIZE + map->offset_y);
	mlx_delete_texture(texture);
}
