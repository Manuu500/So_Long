/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:21:20 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/04 19:21:40 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void free_coins(t_map_data *map)
{
	int	i;
	
	i = 0;
	if (!map->vars.coins)
		return;
	while (i < map->vars.num_coins)
	{
		free(map->vars.coins[i]);
		i++;
	}
	free(map->vars.coins);
	map->vars.coins = NULL;
}
void	free_map(char **map, int height)
{
	int	y;

	y = 0;
	if (!map)
		return;
	while (y < height)
	{
		free(map[y]);
		y++;
	}
	free(map);
	map = NULL;
}