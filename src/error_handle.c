/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:26:15 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/27 16:19:49 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error()
{
	exit(EXIT_FAILURE);
}

void	check_image_limit(t_vars *vars, mlx_image_t *image, int x, int y)
{
	if (!image)
	{
		perror("No se ha encontrado la imagen");
		exit(EXIT_FAILURE);
	}
	else if (mlx_image_to_window(vars->mlx, image, x, y) < 0)
		ft_error();
}