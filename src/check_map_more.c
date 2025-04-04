/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:08:30 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/04 20:20:31 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_num_collec(t_map_data *map, int *count)
{
	printf("Variable map->vars.allcolleccount: %d\n", map->vars.collec_count);
	printf("Variable count %d\n", *count);
	if ((*count) < map->vars.collec_count)
	{
		perror("No hay un camino válido para el mapa");
		exit(EXIT_FAILURE);
	}
}