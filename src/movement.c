/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:45:59 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/04 19:38:36 by mruiz-ur         ###   ########.fr       */
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

void    move_player(t_map_data *map, int map_x, int map_y)
{
    if (!(map->map[map_y - 1][map_x] == '1') && map->vars.keydata.key == MLX_KEY_W)
    {
        do_move(&map->vars, 'y', '-');
        map->vars.coin_count += check_coin(&map->vars, map, map_x, map_y - 1);
        check_exit(&map->vars, map, map_x, map_y);
        go_to_exit(&map->vars, map, map_x, map_y);
    }
    else if (!(map->map[map_y + 1][map_x] == '1') && map->vars.keydata.key == MLX_KEY_S)
    {
        do_move(&map->vars, 'y', '+');
        map->vars.coin_count += check_coin(&map->vars, map, map_x, map_y + 1);
        check_exit(&map->vars, map, map_x, map_y);
        go_to_exit(&map->vars, map, map_x, map_y);
    }
    else if (!(map->map[map_y][map_x - 1] == '1') && map->vars.keydata.key == MLX_KEY_A)
    {
        do_move(&map->vars, 'x', '-');
        map->vars.coin_count += check_coin(&map->vars, map, map_x - 1, map_y);
        check_exit(&map->vars, map, map_x, map_y);
        go_to_exit(&map->vars, map, map_x, map_y);
    }
    else if (!(map->map[map_y][map_x + 1] == '1') && map->vars.keydata.key == MLX_KEY_D)
    {
        do_move(&map->vars, 'x', '+');
        map->vars.coin_count += check_coin(&map->vars, map, map_x + 1, map_y);
        check_exit(&map->vars, map, map_x, map_y);
        go_to_exit(&map->vars, map, map_x, map_y);
    }
}
