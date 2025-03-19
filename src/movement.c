/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:45:59 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/19 20:37:24 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_key_event(mlx_key_data_t keydata, void *param)
{
    t_vars *vars;
	t_map_data *map;

	vars = (t_vars *)param;
	map = vars->map;

    if (keydata.key == MLX_KEY_W)
        move_player(vars, map, keydata);
}

void	move_player(t_vars *vars, t_map_data *map, mlx_key_data_t keydata)
{
	while (!(map->map[vars->player_y + 1][vars->player_x] == '1'))
	{
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		vars->player_y -= PIXEL_SPACING;	
	}
}