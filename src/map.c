/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:44:16 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/08 16:29:02 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_map(const char *file, t_map_data *mapping)
{
    int fd;
    char    *line;
    char    *temp;
    char    *old_line;

    line = NULL;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        exit(EXIT_FAILURE);
    while ((temp = ft_get_next_line(fd)) != NULL)
    {
        old_line = line;
        line = ft_strjoin(line, temp);
        free(temp);
        free(old_line);
    }
    close (fd);
    mapping->map = ft_split(line, '\n');
    free (line);
    load_map_structure(mapping);
}

void    process_map(t_map_data *mapping, int width, int height, t_vars *vars)
{
    int x;
    int y;
    
    y = 0;
    if (width > mapping->width || height > mapping->height)
        return;
    while (y < mapping->height)
    {
        if (ft_strlen(mapping->map[y]) != mapping->width)
            exit(EXIT_FAILURE);
        x = 0;
        while (x < mapping->width)
        {
            place_walls(mapping, vars, x, y);
            x++;
        }
        y++;
    }
    mapping->map_copy = duplicate_map(mapping, mapping->height);
    printf("Contenido del mapa: %p\n", mapping->map_copy);
}

void    place_walls(t_map_data *mapping, t_vars *vars, int x, int y)
{
    if (y < 0 || y >= mapping->height || x < 0 || x >= mapping->width)
        return;
    if (mapping->map[y][x] == '1')
        load_wall(mapping, x, y);
    else if (mapping->map[y][x] == 'C')
        load_coin_image(mapping, x, y);
    else if(mapping->map[y][x] == 'P')
    {
        load_protagonist(vars, x * IMAGE_SIZE, y * IMAGE_SIZE);
        vars->player_x = x * IMAGE_SIZE;
        vars->player_y = y * IMAGE_SIZE;
    }
    else if(mapping->map[y][x] == 'E')
    {
        mapping->map_x = x;
        mapping->map_y = y;
    }
}


