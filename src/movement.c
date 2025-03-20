/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:45:59 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/20 19:32:03 by mruiz-ur         ###   ########.fr       */
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
    map_x = (vars->player_x - map->offset_x) / PIXEL_SPACING;
    map_y = (vars->player_y - map->offset_y) / PIXEL_SPACING;
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
        move_player(vars, map, map_x, map_y);
    if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
        move_player(vars, map, map_x, map_y);
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
        move_player(vars, map, map_x, map_y);
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
        move_player(vars, map, map_x, map_y);
}

void    move_player(t_vars *vars, t_map_data *map, int map_x, int map_y)
{    
    if (!(map->map[map_y - 1][map_x] == '1') && vars->keydata.key == MLX_KEY_W)
    {
        if (map->map[map_y - 1][map_x] == 'C')
        {
            mlx_delete_image(vars->mlx, vars->coin);
            mlx_delete_image(vars->mlx, vars->image);
            vars->player_y -= PIXEL_SPACING;
            load_protagonist(vars, vars->player_x, vars->player_y);
        }
        else
        {
            mlx_delete_image(vars->mlx, vars->image);
            vars->player_y -= PIXEL_SPACING;
            load_protagonist(vars, vars->player_x, vars->player_y);
        }
    }
    if (!(map->map[map_y + 1][map_x] == '1') && vars->keydata.key == MLX_KEY_S)
    {
        if (map->map[map_y + 1][map_x] == 'C')
        {
            mlx_delete_image(vars->mlx, vars->coin);
            mlx_delete_image(vars->mlx, vars->image);
            vars->player_y += PIXEL_SPACING;
            load_protagonist(vars, vars->player_x, vars->player_y);
        }
        else
        {
            mlx_delete_image(vars->mlx, vars->image);
            vars->player_y += PIXEL_SPACING;
            load_protagonist(vars, vars->player_x, vars->player_y);  
        }
    }
    if (!(map->map[map_y][map_x - 1] == '1') && vars->keydata.key == MLX_KEY_A)
    {
        if (map->map[map_y][map_x - 1] == 'C')
        {
            mlx_delete_image(vars->mlx, vars->coin);
            mlx_delete_image(vars->mlx, vars->image);
            vars->player_x -= PIXEL_SPACING;
            load_protagonist(vars, vars->player_x, vars->player_y);
        }
        else
        {
            mlx_delete_image(vars->mlx, vars->image);
            vars->player_x -= PIXEL_SPACING;
            load_protagonist(vars, vars->player_x, vars->player_y);
        }
    }
    if (!(map->map[map_y][map_x + 1] == '1') && vars->keydata.key == MLX_KEY_D)
    {
        if (map->map[map_y][map_x + 1] == 'C')
        {
            mlx_delete_image(vars->mlx, vars->coin);
            mlx_delete_image(vars->mlx, vars->image);
            vars->player_x += PIXEL_SPACING;
            load_protagonist(vars, vars->player_x, vars->player_y);
        }
        else
        {
            mlx_delete_image(vars->mlx, vars->image);
            vars->player_x += PIXEL_SPACING;
            load_protagonist(vars, vars->player_x, vars->player_y);   
        }
    }
}



// void print_vars(t_vars *vars, t_map_data *map)
// {
//     printf("propiedades de t_vars:\n");
//     printf("mlx: %p\n", vars->mlx);
//     printf("image: %p\n", vars->image);
//     printf("player_x: %d\n", vars->player_x);
//     printf("player_y: %d\n", vars->player_y);
//     if (map->map)
//     {
//         printf("map: %p\n", vars.map);
//         printf("map width: %d\n", vars->map->width);
//         printf("map height: %d\n", vars->map->height);
//         printf("map offset_x: %d\n", vars->map->offset_x);
//         printf("map offset_y: %d\n", vars->map->offset_y);
//     }
//     else
//     {
//         printf("map: NULL\n");
//     }
// }
