/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:25:43 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/19 20:07:23 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(void *param)
{
	t_vars *vars;

	vars = (t_vars *)param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
}

// void	key_hooks(mlx_key_data_t keydata, void *param)
// {
// 	t_vars	*vars;
// 	mlx_image_t	*image;

// 	vars = (t_vars *)param;
// 	image = vars->image;
// 	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP ||
// 		 keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN ||
// 		 keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT ||
// 		 keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
// 		 && keydata.action == MLX_RELEASE)
// 	{
// 		handle_key_event(&vars, image->instances, keydata, param);
// 	}
// }


// void handle_key_event(mlx_key_data_t keydata, t_map_data *mapping, t_vars *vars)
// {
//     int new_x = vars->player_x;
//     int new_y = vars->player_y;

//     if (keydata.key == MLX_KEY_UP)
//         new_y--;
//     if (keydata.key == MLX_KEY_DOWN)
//         new_y++;
//     if (keydata.key == MLX_KEY_LEFT)
//         new_x--;
//     if (keydata.key == MLX_KEY_RIGHT)
//         new_x++;
    
//     move_player(mapping, vars, new_x, new_y);
// }
