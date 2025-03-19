/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:50:36 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/19 20:34:19 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>
# define WIDTH 1200
# define HEIGHT 600
# define PIXEL_SPACING 20

typedef struct	s_map_data {
	char **map;
	int	width;
	int	height;
	int	offset_x;
	int offset_y;
}				t_map_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	mlx_image_t	*image;
	int	player_x;
	int	player_y;
	t_map_data *map;

}				t_vars;

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;


void	close_window(void *param);
void	print_text(mlx_key_data_t keydata, void *params);
void	loop_functions(void	*param);
void	ft_error();
void	check_image(mlx_image_t *image);
void	load_protagonist(t_vars *vars, int x, int y);
void	move_player(t_vars *vars, t_map_data *map, mlx_key_data_t keydata);
// void	key_hooks(mlx_key_data_t keydata, void *param);
void	handle_key_event(mlx_key_data_t keydata, void *param);
void	load_background(t_vars *vars);
// void	move_player(t_map_data *mapping, t_vars *vars, int new_x, int new_y);
void    read_map(const char *file, t_map_data *map);
void    process_map(t_map_data *mapping, int width, int height, t_vars *vars);
void    place_walls(t_map_data *mapping, t_vars *vars, int x, int y);

#endif