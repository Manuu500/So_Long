/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:33:39 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/07 19:29:53 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_image(mlx_image_t *image)
{
    if (!image)
        ft_error();
    if ((image->width < 0 || image->width > WIDTH)
            || image->height < 0 || image->height > HEIGHT)
        ft_error();
}

void	load_image(t_vars *vars)
{
	mlx_texture_t *texture;
	int x;
	int y;
	
	x = WIDTH / 2;
	y = HEIGHT / 2;
	texture = mlx_load_png("textures/protagonist.png");
	if (!texture)
		ft_error();
	vars->image = mlx_texture_to_image(vars->mlx, texture);
	if (!vars->image)
		ft_error();
	// check_image(image);
	// mlx_put_pixel(image, WIDTH/2, HEIGHT/2, 0xFFFFFFFF);
	if (mlx_image_to_window(vars->mlx, vars->image, x, y) < 0)
		ft_error();
	mlx_key_hook(vars->mlx, key_hooks, vars);
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
}