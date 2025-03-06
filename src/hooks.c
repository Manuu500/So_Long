/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:25:43 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/06 19:08:59 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print(mlx_key_data_t keydata, void *param)
{
	t_vars *vars;

	vars = (t_vars *)param;
	if(keydata.key == MLX_KEY_1 && keydata.action == MLX_RELEASE)
		printf("42");
}

void	close_window(void *param)
{
	t_vars *vars;

	vars = (t_vars *)param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
}