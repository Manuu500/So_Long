/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/01 18:20:59 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int arcv, char **argv)
{
	t_map_data map;
	t_init_vars ivars;
	
	(void) arcv;
	map.map_name = argv[1];
	read_map(map.map_name, &map);
	map.vars.mlx = mlx_init(map.width * IMAGE_SIZE, map.height * IMAGE_SIZE, "So_Long", 0);
	if (!map.vars.mlx)
		ft_error();
	map.vars.coins = malloc(sizeof(t_coin *) * MAX_COINS);
	if (!map.vars.coins)
		free(map.vars.coins);
	map.vars.num_coins = 0;
	initialize_var(&ivars);
	mlx_key_hook(map.vars.mlx, handle_key_event, &map);
	load_background(&map.vars, &map);	
	process_map(&map, map.width, map.height, &map.vars);
	check_map(&map, &ivars);
	mlx_loop(map.vars.mlx);
	free(map.vars.coins);
	mlx_terminate(map.vars.mlx);
	return(EXIT_SUCCESS);
}
