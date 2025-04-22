/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:45:59 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/22 21:04:55 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h" // Include the MLX42 library header for mlx_key_data

void	do_move(t_map_data *map, char pos, char op)
{
	if (pos == 'y')
	{
		mlx_delete_image(map->vars.mlx, map->vars.image);
		if (op == '-')
			map->vars.player_y -= IMAGE_SIZE;
		else if (op == '+')
			map->vars.player_y += IMAGE_SIZE;
		load_protagonist(map, map->vars.player_x, map->vars.player_y);
	}
	if (pos == 'x')
	{
		mlx_delete_image(map->vars.mlx, map->vars.image);
		if (op == '-')
			map->vars.player_x -= IMAGE_SIZE;
		else if (op == '+')
			map->vars.player_x += IMAGE_SIZE;
		load_protagonist(map, map->vars.player_x, map->vars.player_y);
	}
}

void	handle_move(t_map_data *map, t_coords coords, char pos, char op)
{
	do_move(map, pos, op);
	map->vars.coin_count += check_coin(&map->vars, map,
			coords.new_x, coords.new_y);
	check_exit(&map->vars, map);
	go_to_exit(&map->vars, map, coords.map_x, coords.map_y);
	map->vars.move_count++;
	ft_printf("%d", map->vars.move_count);
	ft_printf("\n");
}

void	move_player(t_map_data *map, int map_x, int map_y)
{
	initialize_pos_vars(map, map_x, map_y);
	if (map->vars.keydata.key == MLX_KEY_W && map->map[map_y - 1][map_x] != '1')
		process_move(map, map_x, map_y, MLX_KEY_W);
	else if (map->vars.keydata.key == MLX_KEY_S
		&& map->map[map_y + 1][map_x] != '1')
		process_move(map, map_x, map_y, MLX_KEY_S);
	else if (map->vars.keydata.key == MLX_KEY_A
		&& map->map[map_y][map_x - 1] != '1')
		process_move(map, map_x, map_y, MLX_KEY_A);
	else if (map->vars.keydata.key == MLX_KEY_D
		&& map->map[map_y][map_x + 1] != '1')
		process_move(map, map_x, map_y, MLX_KEY_D);
}

void	process_move(t_map_data *map, int map_x, int map_y, keys_t key)
{
	if (key == MLX_KEY_W)
	{
		map->coords.new_x = map_x;
		map->coords.new_y = map_y - 1;
		handle_move(map, map->coords, 'y', '-');
	}
	else if (key == MLX_KEY_S)
	{
		map->coords.new_x = map_x;
		map->coords.new_y = map_y + 1;
		handle_move(map, map->coords, 'y', '+');
	}
	else if (key == MLX_KEY_A)
	{
		map->coords.new_x = map_x - 1;
		map->coords.new_y = map_y;
		handle_move(map, map->coords, 'x', '-');
	}
	else if (key == MLX_KEY_D)
	{
		map->coords.new_x = map_x + 1;
		map->coords.new_y = map_y;
		handle_move(map, map->coords, 'x', '+');
	}
}
