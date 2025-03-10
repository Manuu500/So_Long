/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:44:16 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/10 20:37:11 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    read_map(const char *file, char map[MAX_HEIGHT][MAX_WIDTH], int *width, int *height)
{
    int fd;
    char    *line;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("Fallo al cargar el archivo");
        exit(EXIT_FAILURE);
    }
    *height = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        *width = 0;
        while (line[*width] != '\n' && line[*width] != '\0')
        {
            map[*height][*width] = line[*width];
            (*width)++;
        }
        (*height)++;
        free(line);
        if (*height >= HEIGHT)
            break;
    }
    close(fd);
}

void    process_map(char map[MAX_HEIGHT][MAX_WIDTH], int width, int height, t_vars *vars)
{
    int x;
    int y;
    mlx_image_t *image;
    mlx_texture_t   *texture;

    y = 0;
    image = vars->image;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            if(map[y][x] == '1')
            {
                texture = mlx_load_png("textures/pared.png");
                image = mlx_texture_to_image(vars->mlx, texture); 
                mlx_resize_image(image, 21, 21);
                mlx_image_to_window(vars->mlx, image, x * 21, y * 21);
                mlx_delete_texture(texture);
            }
            x++;
        }
        y++;
    }
}
