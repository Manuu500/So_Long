/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:25:43 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/31 17:15:57 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	handle_key_event(mlx_key_data_t keydata, void *param)
// {
//     t_vars *vars;
// 	t_map_data *map;
//     int map_x;
//     int map_y;
    
//     map = (t_map_data *)param;
//     vars = &map->vars;
//     vars->keydata = keydata;
//     // print_vars(vars, map);
//     map_x = (vars->player_x - map->offset_x) / IMAGE_SIZE;
//     map_y = (vars->player_y - map->offset_y) / IMAGE_SIZE;
//     if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
//         move_player(vars, map, map_x, map_y);
//     if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
//         move_player(vars, map, map_x, map_y);
//     if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
//         move_player(vars, map, map_x, map_y);
//     if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
//         move_player(vars, map, map_x, map_y);
//     if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
//         mlx_close_window(vars->mlx);
// }


//        if (ft_strlen(mapping->map[y]) != mapping->width)
