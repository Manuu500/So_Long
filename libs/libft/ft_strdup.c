/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:17:36 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/03/18 15:21:06 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s, ft_strlen(s) + 1);
	return (str);
}
