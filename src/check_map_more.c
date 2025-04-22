/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:08:30 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/22 18:06:00 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_num_collec(t_map_data *map, int *count)
{
	ft_printf("Despues del mensaje: %d\0", map->vars.collec_count);
	if ((*count) < map->vars.collec_count)
		ft_error(map, "There's no valid path");
}
