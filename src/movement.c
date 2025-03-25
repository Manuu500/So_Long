/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:45:59 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/25 15:49:31 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_key_event(mlx_key_data_t keydata, void *param)
{
    t_vars *vars;
	t_map_data *map;
    int map_x;
    int map_y;
    
    map = (t_map_data *)param;
    vars = &map->vars;
    vars->keydata = keydata;
    // print_vars(vars, map);
    map_x = (vars->player_x - map->offset_x) / IMAGE_SIZE;
    map_y = (vars->player_y - map->offset_y) / IMAGE_SIZE;
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
        move_player(vars, map, map_x, map_y);
    if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
        move_player(vars, map, map_x, map_y);
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
        move_player(vars, map, map_x, map_y);
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
        move_player(vars, map, map_x, map_y);
}

void    do_move(t_vars *vars, char pos, char op){
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

void    move_player(t_vars *vars, t_map_data *map, int map_x, int map_y)
{    
    if (!(map->map[map_y - 1][map_x] == '1') && vars->keydata.key == MLX_KEY_W)
    {
        vars->coin_count += check_coin(vars, map, map_x, map_y);
        do_move(vars, 'y', '-');
    }
    else if (!(map->map[map_y + 1][map_x] == '1') && vars->keydata.key == MLX_KEY_S)
    {
        vars->coin_count += check_coin(vars, map, map_x, map_y);
        do_move(vars, 'y', '+');
    }
    else if (!(map->map[map_y][map_x - 1] == '1') && vars->keydata.key == MLX_KEY_A)
    {
        vars->coin_count += check_coin(vars, map, map_x, map_y);
        do_move(vars, 'x', '-');   
    }
    else if (!(map->map[map_y][map_x + 1] == '1') && vars->keydata.key == MLX_KEY_D)
    {
        vars->coin_count += check_coin(vars, map, map_x, map_y);
        do_move(vars, 'x', '+');
    }
    if (vars->coin_count == 4)
        put_exit(vars, map);
}
