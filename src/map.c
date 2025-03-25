/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:44:16 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/25 19:44:12 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_map(const char *file, t_map_data *mapping)
{
    int fd;
    char    *line;
    char    *temp;
    
    line = NULL;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        exit(EXIT_FAILURE);
    while ((temp = ft_get_next_line(fd)) != NULL)
    {
        char *old_line = line;
        line = ft_strjoin(line, temp);
        free(temp);
        free(old_line);
    }
    close (fd);
    mapping->map = ft_split(line, '\n');
    free (line);
    mapping->height = 0;
    while (mapping->map[mapping->height])
        mapping->height++;
    if (mapping->height > 0)
        mapping->width = ft_strlen(mapping->map[0]);
    else
        mapping->width = 0;
}

void    process_map(t_map_data *mapping, int width, int height, t_vars *vars)
{
    int x;
    int y;
    
    (void) height;
    (void) width;
    y = 0;
    if (width > mapping->width || height > mapping->height)
        return;
    mapping->offset_x = (WIDTH - (width * IMAGE_SIZE)) / 2;
    mapping->offset_y = (HEIGHT - (height * IMAGE_SIZE)) / 2;
    while (y < mapping->height)
    {
        x = 0;
        while (x < mapping->width)
        {
            place_walls(mapping, vars, x, y);
            x++;
        }
        y++;
    }
}

void    place_walls(t_map_data *mapping, t_vars *vars, int x, int y)
{
	mlx_texture_t *texture;
	mlx_image_t	*image;
	
    if (y < 0 || y >= mapping->height || x < 0 || x >= mapping->width)
        return;
    if (mapping->map[y][x] == '1')
	{
		texture = mlx_load_png("textures/pared.png");
		image = mlx_texture_to_image(vars->mlx, texture); 
		mlx_resize_image(image, IMAGE_SIZE, IMAGE_SIZE);
		mlx_image_to_window(vars->mlx, image, x * IMAGE_SIZE + mapping->offset_x , y * IMAGE_SIZE + mapping->offset_y);
		mlx_delete_texture(texture);
	}
    else if (mapping->map[y][x] == 'C')
    {
        texture = mlx_load_png("textures/box.png");
        image = mlx_texture_to_image(vars->mlx, texture);
        mlx_resize_image(image, IMAGE_SIZE, IMAGE_SIZE);
        mlx_image_to_window(vars->mlx, image, x * IMAGE_SIZE + mapping->offset_x, y * IMAGE_SIZE + mapping->offset_y);
        mlx_delete_texture(texture);
        vars->coins[vars->num_coins] = image;
        printf("Coordenadas monedas: %d, %d\n", image->instances->x, image->instances->y);
        vars->num_coins++;
    }
    else if(mapping->map[y][x] == 'P')
    {
        load_protagonist(vars, x * IMAGE_SIZE + mapping->offset_x, y * IMAGE_SIZE + mapping->offset_y);
        vars->player_x = x * IMAGE_SIZE + mapping->offset_x;
        vars->player_y = y * IMAGE_SIZE + mapping->offset_y;
    }
}

