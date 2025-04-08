/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:45:59 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/08 16:30:45 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    do_move(t_vars *vars, char pos, char op)
{
    if (pos == 'y'){
        mlx_delete_image(vars->mlx, vars->image);
        if (op == '-')
            vars->player_y -= IMAGE_SIZE;
        else if (op == '+')
            vars->player_y += IMAGE_SIZE;
        load_protagonist(vars, vars->player_x, vars->player_y);
    }
    if (pos == 'x'){
        mlx_delete_image(vars->mlx, vars->image);
        if (op == '-')
            vars->player_x -= IMAGE_SIZE;
        else if (op == '+')
            vars->player_x += IMAGE_SIZE;
        load_protagonist(vars, vars->player_x, vars->player_y);
    }
}

void    handle_move(t_map_data *map, t_coords coords, char pos, char op)
{
    do_move(&map->vars, pos, op);
    map->vars.coin_count += check_coin(&map->vars, map, coords.new_x, coords.new_y);
    check_exit(&map->vars, map);
    go_to_exit(&map->vars, map, coords.map_x, coords.map_y);
}

void    move_player(t_map_data *map, int map_x, int map_y)
{
    initialize_pos_vars(map, map_x, map_y);
    if (map->vars.keydata.key == MLX_KEY_W && map->map[map_y - 1][map_x] != '1')
    {
        map->coords.new_x = map_x;
        map->coords.new_y = map_y - 1;
        handle_move(map, map->coords, 'y', '-');
    }
    else if (map->vars.keydata.key == MLX_KEY_S && map->map[map_y + 1][map_x] != '1')
    {
        map->coords.new_x = map_x;
        map->coords.new_y = map_y + 1;
        handle_move(map, map->coords, 'y', '+');
    }
    else if (map->vars.keydata.key == MLX_KEY_A && map->map[map_y][map_x - 1] != '1')
    {
        map->coords.new_x = map_x - 1;
        map->coords.new_y = map_y;
        handle_move(map, map->coords, 'x', '-');
    }
    else if (map->vars.keydata.key == MLX_KEY_D && map->map[map_y][map_x + 1] != '1')
    {
        map->coords.new_x = map_x + 1;
        map->coords.new_y = map_y;
        handle_move(map, map->coords, 'x', '+');
    }
}
