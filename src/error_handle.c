/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:26:15 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/08 19:32:40 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error()
{
	exit(EXIT_FAILURE);
}

void	ft_texture_error()
{
	perror("Failed to load texture");
	exit(EXIT_FAILURE);
}

void	ft_image_error()
{
	perror("Failed to load image");
	exit(EXIT_FAILURE);
}
