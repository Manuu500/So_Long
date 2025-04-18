/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/10 18:08:38 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int arcv, char **argv)
{
	t_map_data map;
	
	(void) arcv;
	map.map_name = argv[1];
	initialize_var(&map);
	read_map(map.map_name, &map);
	map.vars.mlx = mlx_init(map.width * IMAGE_SIZE, map.height * IMAGE_SIZE, "So_Long", 1);
	if (!map.vars.mlx)
		ft_error(&map, "The window is not loading well");
	load_background(&map.vars, &map);	
	process_map(&map, map.width, map.height, &map.vars);
	check_map(&map);
	mlx_key_hook(map.vars.mlx, handle_key_event, &map);
	mlx_close_hook(map.vars.mlx, close_window_x, &map);
	mlx_loop(map.vars.mlx);
	mlx_close_window(map.vars.mlx);
	free_coins(&map);
	return(SUCCESS);
}
