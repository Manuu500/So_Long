/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:45:59 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/12 20:21:18 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_vars *vars, mlx_instance_t *player_pos, mlx_key_data_t keydata, void *param)
{
	int	counter;
	int x;
	int y;
	t_map_data *mapping;
	
	x = vars->player_x;
	y = vars->player_y;
	mapping = (t_map_data *)param;
	if (!mapping)
    {
        fprintf(stderr, "Error: Invalid map data\n");
        return;
    }
	counter = 0;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
	{
		printf("Antes de meterme a la condicion puta\n");
		if (mapping->map[y - 1][x] != '1')
		{
			printf("Estoy dentroooooo. La y es: %d y el caracter es: %c\n", y, mapping->map[y - 1][x]);
			player_pos->y -= PIXEL_SPACING;
			vars->player_y--;
			y = vars->player_y;
			counter++;
			printf("Soy y despues: %d, soy el de la estrucura: %d\n", y, vars->player_y);
		}
	}
	if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
	{
		player_pos->y += PIXEL_SPACING;
		counter++;
	}
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
	{
		player_pos->x -= PIXEL_SPACING;
		counter++;
	}
	if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
	{
		player_pos->x += PIXEL_SPACING;
		counter++;
	}
}

