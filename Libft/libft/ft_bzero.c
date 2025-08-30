/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:26:30 by fleite-j          #+#    #+#             */
/*   Updated: 2025/08/29 23:26:31 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temporary;

	temporary = (unsigned char *) s;
	while (n > 0)
	{
		*(temporary++) = 0;
		n--;
	}
}
