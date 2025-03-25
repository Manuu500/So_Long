/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:14:31 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/25 20:26:35 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int check_coin(t_vars *vars, t_map_data *map, int map_x, int map_y)
{
    int counter;
    int i;

    counter = 0;
    if (map->map[map_y][map_x] == 'C')
    {
        map->map[map_y][map_x] = '0'; // Actualizar el mapa
        i = 0;
        while (i < vars->num_coins)
        {
            if (vars->coins[i] && vars->coins[i]->map_x == map_x
                && vars->coins[i]->map_y == map_y)
            {
                mlx_delete_image(vars->mlx, vars->coins[i]->image);
                free(vars->coins[i]);
                vars->coins[i] = NULL;
                break;
            }
            i++;
        }
        load_protagonist(vars, vars->player_x, vars->player_y);
        counter++;
    }
    return (counter);
}

// void    pick_coin(t_vars *vars)
// {
//     int i;

//     i = 0;
//     while (i < vars->num_coins)
//     {
//         if (vars->coins[i] && vars->coins[i]->instances[0].y == vars->player_y
//             && vars->coins[i]->instances[0].x == vars->player_x)
//         {
//             mlx_delete_image(vars->mlx, vars->coins[i]);
//             vars->coins[i] = NULL;
//         }
//         i++;
//     }
// }
