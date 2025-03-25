/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:14:31 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/25 15:24:29 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    check_coin(t_vars *vars, t_map_data *map, int map_x, int map_y)
{
    int counter;

    counter = 0;
    if (map->map[map_y][map_x] == 'C' )
    {
        pick_coin(vars);
        map->map[map_y][map_x] = '0';
        load_protagonist(vars, vars->player_x, vars->player_y);
        counter++;
    }
    return (counter);
}

int    pick_coin(t_vars *vars)
{
    int i;
    int counter;

    counter = 0;
    i = 0;
    while (i < vars->num_coins)
    {
        if (vars->coins[i] && vars->coins[i]->instances[0].y == vars->player_y
            && vars->coins[i]->instances[0].x == vars->player_x)
        {
            printf("Hola\n");
            counter++;
            mlx_delete_image(vars->mlx, vars->coins[i]);
            mlx_delete_image(vars->mlx, vars->image);
            vars->coins[i] = NULL;
        }
        i++;
    }
    return counter;
}
