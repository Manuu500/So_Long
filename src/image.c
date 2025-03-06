/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:33:39 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/06 19:15:20 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_image(mlx_image_t *image)
{
    if (!image)
        ft_error();
    if ((image->width < 0 || image->width > WIDTH)
            || image->height < 0 || image->height > HEIGHT)
        ft_error();
}