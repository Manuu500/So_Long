/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/05 20:21:04 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <MLX42/MLX42.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	close_window(void *param)
{
	t_vars *vars;

	vars = (t_vars *)param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
}

void	print(void *param)
{
	t_vars *vars;

	vars = (t_vars *)param;
	if(mlx_is_key_down(vars->mlx, MLX_KEY_1))
	{
		printf("42");
	}
}

void	loop_functions(void	*param)
{
	print(param);
	close_window(param);
}

int	main(void)
{
	t_vars vars;

	vars.mlx = mlx_init(1200, 600, "Prueba", 0);
	if (!vars.mlx)
		return (EXIT_FAILURE);
	
	mlx_loop_hook(vars.mlx, loop_functions, &vars);
		
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	return(EXIT_SUCCESS);
}