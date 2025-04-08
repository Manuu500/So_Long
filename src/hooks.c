/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:25:43 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/08 19:45:30 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_key_event(mlx_key_data_t keydata, void *param)
{
	t_map_data *map;
    int map_x;
    int map_y;
    
    map = (t_map_data *)param;
    map->vars.keydata = keydata;
    map_x = map->vars.player_x;
    map_y = map->vars.player_y;
    if (!map)
        return;
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
        move_player(map, map_x / IMAGE_SIZE, map_y / IMAGE_SIZE);
    if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
        move_player(map, map_x / IMAGE_SIZE, map_y / IMAGE_SIZE);
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
        move_player(map, map_x / IMAGE_SIZE, map_y / IMAGE_SIZE);
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
        move_player(map, map_x / IMAGE_SIZE, map_y / IMAGE_SIZE);
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
        clean_close(map);
}      
