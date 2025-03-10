/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:50:36 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/10 20:24:51 by mruiz-ur         ###   ########.fr       */
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
# define MAX_WIDTH 40
# define MAX_HEIGHT 40


typedef struct	s_vars {
	void	*mlx;
	void	*win;
	mlx_image_t	*image;
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
void	load_image(t_vars *vars);
void	key_hooks(mlx_key_data_t keydata, void *param);
void	load_background(t_vars *vars);
void	move_player(mlx_instance_t	*player_pos, mlx_key_data_t keydata);
void    read_map(const char *file, char map[MAX_HEIGHT][MAX_WIDTH], int *width, int *height);
void    process_map(char map[MAX_HEIGHT][MAX_WIDTH], int width, int height, t_vars *vars);

#endif