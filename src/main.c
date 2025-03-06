/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/06 19:45:38 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error()
{
	exit(EXIT_FAILURE);
}

void	loop_functions(void	*param)
{	
	close_window(param);
}

int32_t	main(void)
{
	t_vars vars;
	mlx_texture_t *texture;
	mlx_image_t *image;
	int x;
	int y;
	
	x = WIDTH / 2;
	y = HEIGHT / 2;
	vars.mlx = mlx_init(WIDTH, HEIGHT, "Prueba", 0);
	if (!vars.mlx)
		ft_error();
	// image = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	texture = mlx_load_png("textures/protagonist.png");
	if (!texture)
		ft_error();
	image = mlx_texture_to_image(vars.mlx, texture);
	// check_image(image);
	// mlx_put_pixel(image, WIDTH/2, HEIGHT/2, 0xFFFFFFFF);
	if (mlx_image_to_window(vars.mlx, image, x, y) < 0)
		ft_error();
	mlx_loop_hook(vars.mlx, loop_functions, &vars);
	mlx_key_hook(vars.mlx, print, &vars);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	return(EXIT_SUCCESS);
}