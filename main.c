/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/05 19:59:03 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <MLX42/MLX42.h>
# include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	close_window(mlx_key_data_t keydata, void *param)
{
	t_vars *vars;

	vars = (t_vars *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(vars->mlx);
}

int	main(void)
{
	t_vars vars;

	vars.mlx = mlx_init(1200, 600, "Prueba", 0);
	if (!vars.mlx)
		return (EXIT_FAILURE);
	
	mlx_key_hook(vars.mlx, close_window, &vars);
		
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	return(EXIT_SUCCESS);
}