/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:26:15 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/22 19:43:09 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_map_data *map, char	*error)
{
	if (map)
	{
		write(2, "Error\n", 6);
		ft_printf(error);
		ft_printf("\n");
		clean_close(map);
	}
}

// mlx_image_t *safe_texture_to_image(mlx_t *mlx, mlx_texture_t *texture)
// {
// 	mlx_image_t	*image;
	
// 	if (!texture)
// 		return 0;
// 	int saved_stderr = dup(STDERR_FILENO);
// 	int dev_null = open("/dev/null", O_WRONLY);
// 	dup2(dev_null, STDERR_FILENO);
// 	close(dev_null);
// 	image = mlx_texture_to_image(mlx, texture);
// 	dup2(saved_stderr, STDERR_FILENO);
// 	close(saved_stderr);

// 	return image;
// }

// mlx_texture_t *safe_load_texture(const char *path)
// {
// 	mlx_texture_t	*texture;
// 	int saved_stderr = dup(STDERR_FILENO);
// 	int dev_null = open("/dev/null", O_WRONLY);
// 	dup2(dev_null, STDERR_FILENO);
// 	close(dev_null);
// 	texture = mlx_load_png(path);
// 	dup2(saved_stderr, STDERR_FILENO);
// 	close(saved_stderr);
// 	return texture;
// }

// void	ft_texture_error()
// {
// 	perror("Error\nFailed to load texture");
// 	exit(FAILURE);
// }

// void	ft_image_error()
// {
// 	perror("Error\nFailed to load image");
// 	exit(FAILURE);
// }
