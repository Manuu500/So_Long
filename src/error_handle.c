/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:26:15 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/08 22:02:15 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_map_data *map, char	*error)
{
	if (map)
	{
		write(2, "Error\n", 6);
		perror(error);
		clean_close(map);
	}
}

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
