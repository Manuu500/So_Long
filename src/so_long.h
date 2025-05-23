/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:50:36 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/22 21:02:50 by mruiz-ur         ###   ########.fr       */
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
# define IMAGE_SIZE 60
# define FAILURE 1
# define SUCCESS 0
// # define PIXEL_SPACING 20
// # define MAX_COINS 250

typedef struct s_coords
{
	int	map_x;
	int	map_y;
	int	new_x;
	int	new_y;
}				t_coords;

typedef struct s_coin
{
	int			map_x;
	int			map_y;
	mlx_image_t	*image;
}				t_coin;

typedef struct s_vars
{
	mlx_key_data_t	keydata;
	void			*mlx;
	mlx_image_t		*image;
	t_coin			**coins;
	int				num_coins;
	int				coin_count;
	int				coins_num;
	int				move_count;
	int				player_x_copy;
	int				player_y_copy;
	int				player_x;
	int				player_y;
	int				collec_count;
	int				all_collec_count;
}				t_vars;

typedef struct s_map_data
{
	char		**map;
	char		**map_copy;
	char		*map_name;
	int			width;
	int			height;
	int			offset_x;
	int			offset_y;
	int			map_x;
	int			map_y;
	t_coords	coords;
	t_vars		vars;
}				t_map_data;

mlx_texture_t	*safe_load_texture(const char *path);
mlx_image_t		*safe_texture_to_image(mlx_t *mlx, mlx_texture_t *texture);
void			loop_functions(void	*param);
void			check_image(mlx_image_t *image);
void			load_protagonist(t_map_data *map, int x, int y);
void			move_player(t_map_data *map, int map_x, int map_y);
void			handle_key_event(mlx_key_data_t keydata, void *param);
void			load_background(t_vars *vars, t_map_data *map);
void			read_map(const char *file, t_map_data *map);
void			process_map(t_map_data *mapping, int width,
					int height, t_vars *vars);
void			place_walls(t_map_data *mapping, t_vars *vars, int x, int y);
void			print_vars(t_vars *vars, t_map_data *map);
void			draw_map(t_vars *vars, t_map_data *map);
void			pick_coin(t_vars *vars);
int				check_coin(t_vars *vars, t_map_data *map, int map_x, int map_y);
void			place_exit(t_vars *vars, t_map_data *map);
void			check_exit(t_vars *vars, t_map_data *map);
int				go_to_exit(t_vars *vars, t_map_data *map, int map_x, int map_y);
void			check_coin_sur(t_map_data *map, int x, int y);
void			check_limits(t_map_data *map, int x, int y);
void			check_flood(char **map);
void			check_map(t_map_data *map);
void			read_matrix(t_map_data *map, int *p_count,
					int *c_count, int *e_count);
int				check_coin_surround(t_map_data *map);
// int	check_map_extension(char	*filename);
char			**duplicate_map(t_map_data *map, int height);
void			debug_mapa(t_map_data *map);
void			free_duplicate_map(char **map_copy, int height);
int				count_coins(t_map_data *map);
void			initialize_var(t_map_data *map);
void			free_coins(t_map_data *map);
void			free_map(char **map, int height);
void			check_num_collec(t_map_data *map, int *count);
void			load_wall(t_map_data *map, int x, int y);
void			load_coin_image(t_map_data *map, int x, int y);
void			initialize_pos_vars(t_map_data *map, int map_x, int map_y);
void			load_map_structure(t_map_data *map);
void			redraw_map(t_map_data *map);
// void	ft_texture_error();
// void	ft_image_error();
void			clean_close(t_map_data *map);
void			close_window_x(void	*param);
void			ft_error(t_map_data *map, char	*error);
void			create_pos_copy(t_map_data *map, int x, int y);
void			allocate_coins(t_map_data	*map);
void			process_move(t_map_data *map, int map_x, int map_y, keys_t key);

#endif