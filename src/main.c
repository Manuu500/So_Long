/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/10 12:33:11 by mruiz-ur         ###   ########.fr       */
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

	vars.mlx = mlx_init(WIDTH, HEIGHT, "Prueba", 0);
	if (!vars.mlx)
		ft_error();
	mlx_loop_hook(vars.mlx, loop_functions, &vars);
	load_background(&vars);
	load_image(&vars);
	mlx_loop(vars.mlx);
	mlx_key_hook(vars.mlx, print, &vars);
	mlx_terminate(vars.mlx);
	return(EXIT_SUCCESS);
}