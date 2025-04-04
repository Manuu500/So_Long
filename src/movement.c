/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:45:59 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/04 19:14:11 by mruiz-ur         ###   ########.fr       */
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
    map_x = (vars->player_x) / IMAGE_SIZE;
    map_y = (vars->player_y) / IMAGE_SIZE;
    if (!map || !vars)
        return;
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
        move_player(vars, map, map_x, map_y);
    if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
        move_player(vars, map, map_x, map_y);
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
        move_player(vars, map, map_x, map_y);
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
        move_player(vars, map, map_x, map_y);
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
    {
        free_coins(map);
        free_map(map->map, map->height);
        mlx_close_window(vars->mlx);
        mlx_terminate(vars->mlx);
        exit(EXIT_SUCCESS); // Ensure the program exits
    }
}

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

void    move_player(t_vars *vars, t_map_data *map, int map_x, int map_y)
{
    if (!(map->map[map_y - 1][map_x] == '1') && vars->keydata.key == MLX_KEY_W)
    {
        do_move(vars, 'y', '-');
        vars->coin_count += check_coin(vars, map, map_x, map_y - 1);
        check_exit(vars, map, map_x, map_y);
        go_to_exit(vars, map, map_x, map_y);
    }
    else if (!(map->map[map_y + 1][map_x] == '1') && vars->keydata.key == MLX_KEY_S)
    {
        do_move(vars, 'y', '+');
        vars->coin_count += check_coin(vars, map, map_x, map_y + 1);
        check_exit(vars, map, map_x, map_y);
        go_to_exit(vars, map, map_x, map_y);
    }
    else if (!(map->map[map_y][map_x - 1] == '1') && vars->keydata.key == MLX_KEY_A)
    {
        do_move(vars, 'x', '-');
        vars->coin_count += check_coin(vars, map, map_x - 1, map_y);
        check_exit(vars, map, map_x, map_y);
        go_to_exit(vars, map, map_x, map_y);
    }
    else if (!(map->map[map_y][map_x + 1] == '1') && vars->keydata.key == MLX_KEY_D)
    {
        do_move(vars, 'x', '+');
        vars->coin_count += check_coin(vars, map, map_x + 1, map_y);
        check_exit(vars, map, map_x, map_y);
        go_to_exit(vars, map, map_x, map_y);
    }
}