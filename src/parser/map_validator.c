/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:33:17 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/28 20:47:48 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_closed(t_cub *cub)
{
	char	**map_copy;
	int		is_closed;

	cub->map_set.map_width = get_map_width(cub->map);
	player_coordinates(cub->map, cub);
	map_copy = duplicate_map(cub->map);
	if (!map_copy)
		error_handler(cub, "Error: Malloc failed for map copy\n");
	is_closed = flood_fill(map_copy, cub, cub->map_set.y, cub->map_set.x);
	free_array(map_copy);
	return (is_closed);
}
