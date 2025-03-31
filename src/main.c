/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/31 17:23:44 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "so_long.h"

int	main(void)
{
	t_map_data map;
	
	read_map("maps/map2.ber", &map);
	map.vars.mlx = mlx_init(map.width * IMAGE_SIZE, map.height * IMAGE_SIZE, "So_Long", 0);
	if (!map.vars.mlx)
		ft_error();
	map.vars.coins = malloc(sizeof(t_coin *) * MAX_COINS);
	if (!map.vars.coins)
		free(map.vars.coins);
	map.vars.num_coins = 0;
	mlx_key_hook(map.vars.mlx, handle_key_event, &map);
	load_background(&map.vars, &map);	
	process_map(&map, map.width, map.height, &map.vars);
	check_map(&map);
	mlx_loop(map.vars.mlx);
	free(map.vars.coins);
	mlx_terminate(map.vars.mlx);
	return(EXIT_SUCCESS);
}