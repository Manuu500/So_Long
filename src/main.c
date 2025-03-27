/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/27 16:03:31 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "so_long.h"

// void	ft_error()
// {
// 	exit(EXIT_FAILURE);
// }

// void	loop_functions(void	*param)
// {	
// 	close_window(param);
// }

int	main(void)
{
	t_map_data map;
	
	read_map("maps/map.ber", &map);
	map.vars.mlx = mlx_init(map.width * IMAGE_SIZE, map.height * IMAGE_SIZE, "So_Long", 0);
	if (!map.vars.mlx)
		ft_error();
	map.vars.coins = malloc(sizeof(mlx_image_t *) * MAX_COINS);
	if (!map.vars.coins)
		ft_error();
	map.vars.coins = malloc(sizeof(t_coin *) * MAX_COINS);
	map.vars.num_coins = 0;
	mlx_key_hook(map.vars.mlx, handle_key_event, &map);
	load_background(&map.vars);	
	process_map(&map, map.width, map.height, &map.vars);
	mlx_loop(map.vars.mlx);
	free(map.vars.coins);
	mlx_terminate(map.vars.mlx);
	return(EXIT_SUCCESS);
}