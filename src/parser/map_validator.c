/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:33:17 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/30 14:46:20 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**init_validation(t_cub *cub)
{
	char	**map_copy;

	cub->map_set.map_width = get_map_width(cub->map);
	player_coordinates(cub->map, cub);
	map_copy = duplicate_map(cub->map);
	if (!map_copy)
		error_handler(cub, "Error: Malloc failed for map copy\n");
	return (map_copy);
}

static int	check_tile_adjacency(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (ft_strchr("0NSEW", cub->map[i][j]))
			{
				if (cub->map[i][j + 1] == ' ' || cub->map[i][j - 1] == ' ' ||
					cub->map[i + 1][j] == ' ' || cub->map[i - 1][j] == ' ')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_valid(t_cub *cub)
{
	char	**map_copy;

	if (!has_only_valid_characters(cub->map))
		return (0);
	map_copy = init_validation(cub);
	if (flood_fill(map_copy, cub, cub->map_set.y, cub->map_set.x) == 0)
	{
		free_array(map_copy);
		return (0); 
	}
	free_array(map_copy);
	if (!check_tile_adjacency(cub))
		return (0);
	return (1);
}
