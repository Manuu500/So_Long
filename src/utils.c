/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:45:59 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/10 12:57:27 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(mlx_instance_t *player_pos, mlx_key_data_t keydata)
{
	int	counter;

	counter = 0;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
	{
		player_pos->y -= 20;
		counter++;
	}
	if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
	{
		player_pos->y += 20;
		counter++;
	}
	if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
	{
		player_pos->x -= 20;
		counter++;
	}
	if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
	{
		player_pos->x += 20;
		counter++;
	}
}
