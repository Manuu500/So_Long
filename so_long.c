/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/05 18:39:58 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <MLX42/MLX42.h>
# include <stdlib.h>

int	close_window(void	*mlx_ptr)
{
	(void)mlx_ptr;
	mlx_close_window(0);
	return(0);
}

int key_press(int keycode, void *mlx_ptr)
{
	(void)mlx_ptr;
	if (keycode == 65307)
		mlx_close_window(0);
	return(0);
}

int	main(void)
{
	mlx_t *mlx_ptr;
	mlx_t *win_ptr;

	mlx_ptr = mlx_init(600, 400, "Prueba", 0);
	if (!mlx_ptr)
		return (EXIT_FAILURE);
	
	
	mlx_loop(mlx_ptr);
	mlx_terminate(mlx_ptr);
	return(EXIT_SUCCESS);
}