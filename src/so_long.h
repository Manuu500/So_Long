/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:50:36 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/25 20:08:21 by mruiz-ur         ###   ########.fr       */
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
# define WIDTH 1920
# define HEIGHT 1080
# define IMAGE_SIZE 60
# define PIXEL_SPACING 20
# define MAX_COINS 4

typedef struct	s_vars {
	void	*mlx;
	mlx_image_t	*image;
	mlx_image_t **coins;
	// mlx_image_t	*coin;
	int	num_coins;
	int coin_count;
	int	player_x;
	int	player_y;
	mlx_key_data_t keydata;
}				t_vars;

typedef struct	s_map_data {
	char **map;
	int	width;
	int	height;
	int	offset_x;
	int offset_y;
	t_vars vars;
}				t_map_data;

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
void    move_player(t_vars *vars, t_map_data *map, int map_x, int map_y);
void	handle_key_event(mlx_key_data_t keydata, void *param);
void	load_background(t_vars *vars);
void    read_map(const char *file, t_map_data *map);
void    process_map(t_map_data *mapping, int width, int height, t_vars *vars);
void    place_walls(t_map_data *mapping, t_vars *vars, int x, int y);
void	print_vars(t_vars *vars, t_map_data *map);
void	draw_map(t_vars *vars, t_map_data *map);
void    pick_coin(t_vars *vars);
int    check_coin(t_vars *vars, t_map_data *map, int map_x, int map_y);
// void	put_exit(t_vars *vars, t_map_data *map);
void	place_exit(t_vars *vars, t_map_data *map, int x, int y);
void	check_exit(t_vars *vars, t_map_data *map, int map_x, int map_y);
int	go_to_exit(t_vars *vars, t_map_data *map, int map_x, int map_y);

#endif