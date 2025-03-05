/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/05 17:53:05 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>

int	close_window(void	*mlx_ptr)
{
	(void)mlx_ptr;
	exit(0);
	return(0);
}

int key_press(int keycode, void *mlx_ptr)
{
	(void)mlx_ptr;
	if (keycode == 65307)
		exit (0);
	return(0);
}

int	main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 600, 400, "holis");
	
	mlx_hook(win_ptr, 17, 0, close_window, mlx_ptr);
	mlx_key_hook(win_ptr, key_press, mlx_ptr);

	mlx_loop(mlx_ptr);
	return(0);
}