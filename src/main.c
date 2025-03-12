/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/12 13:51:53 by mruiz-ur         ###   ########.fr       */
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

int	main(void)
{
	t_vars vars;
	t_map_data map;
	int	width;
	int height;
	
	vars.mlx = mlx_init(WIDTH, HEIGHT, "Prueba", 0);
	if (!vars.mlx)
		ft_error();
	mlx_loop_hook(vars.mlx, loop_functions, &vars);
	load_background(&vars);
	/*
	Las variables width y height se pasan por referencia. (&width, &heigth)
	
	Dichas variables cuando las pasas a una función y cambian su valor ahí dentro,
	si quisieras usar width y heigth en otras funciones, estas tendrían el valor
	de la función a las que se le ha pasado.
	*/ 	
	read_map("maps/map.ber", &map, &width, &height);
	process_map(&map, width, height, &vars);
	mlx_loop(vars.mlx);
	mlx_key_hook(vars.mlx, print_text, &vars);
	mlx_terminate(vars.mlx);
	return(EXIT_SUCCESS);
}