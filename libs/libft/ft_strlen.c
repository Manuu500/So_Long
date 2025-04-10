/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:06:30 by mruiz-ur          #+#    #+#             */
/*   Updated: 2024/09/12 15:06:30 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;
	int	cont;

	cont = 0;
	i = -1;
	if (str == NULL)
		return (0);
	while (str[++i] != '\0')
		cont++;
	return (cont);
}
