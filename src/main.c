/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/20 19:08:34 by mruiz-ur         ###   ########.fr       */
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
	t_map_data map;
	
	read_map("maps/map.ber", &map);
	map.vars.mlx = mlx_init(WIDTH, HEIGHT, "So_Long", 0);
	if (!map.vars.mlx)
		ft_error();
	mlx_key_hook(map.vars.mlx, handle_key_event, &map);
	mlx_loop_hook(map.vars.mlx, loop_functions, &map);
	load_background(&map.vars);	
	process_map(&map, map.width, map.height, &map.vars);
	mlx_loop(map.vars.mlx);
	mlx_terminate(map.vars.mlx);
	return(EXIT_SUCCESS);
}