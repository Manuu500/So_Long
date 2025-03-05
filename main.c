/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/05 19:07:36 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <MLX42/MLX42.h>
# include <stdlib.h>

int	main(void)
{
	mlx_t *mlx_ptr;

	mlx_ptr = mlx_init(1200, 600, "Prueba", 0);
	if (!mlx_ptr)
		return (EXIT_FAILURE);
	
	
	mlx_loop(mlx_ptr);
	mlx_terminate(mlx_ptr);
	return(EXIT_SUCCESS);
}