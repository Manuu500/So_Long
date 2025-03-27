/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:33:39 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/27 16:02:35 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_protagonist(t_vars *vars, int x, int y)
{
	mlx_texture_t *texture;

	texture = mlx_load_png("textures/protagonist.png");
	if (!texture)
		ft_error();
	vars->image = mlx_texture_to_image(vars->mlx, texture);
	if (!vars->image)
		ft_error();
	mlx_resize_image(vars->image, IMAGE_SIZE, IMAGE_SIZE);
	if (mlx_image_to_window(vars->mlx, vars->image, x, y) < 0)
		ft_error();
	mlx_delete_texture(texture);
}

void	load_background(t_vars *vars)
{
	mlx_texture_t *texture;
	mlx_image_t *image;
	int	x;
	int	y;

	x = 0;
	y = 0;
	image = vars->image;
	texture = mlx_load_png("textures/hierba.png");
	if (!texture)
		ft_error();
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			image = mlx_texture_to_image(vars->mlx, texture);
			if (!image)
				ft_error();
			if (mlx_image_to_window(vars->mlx, image, x, y) < 0)
				ft_error();
			x += texture->width;
		}
		y += texture->height;
	}
	mlx_delete_texture(texture);
}


void	place_exit(t_vars *vars, t_map_data *map, int x, int y)
{
	mlx_texture_t *texture;
	mlx_image_t *image;
	
	texture = mlx_load_png("textures/gatico.png");
	image = mlx_texture_to_image(vars->mlx, texture); 
	mlx_resize_image(image, IMAGE_SIZE, IMAGE_SIZE);
	mlx_image_to_window(vars->mlx, image, x * IMAGE_SIZE + map->offset_x , y * IMAGE_SIZE + map->offset_y);
	mlx_delete_texture(texture);
	// go_to_exit(vars, map, x, y);
}