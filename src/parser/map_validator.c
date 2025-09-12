/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:33:17 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/09/12 18:44:07 by sdavi-al         ###   ########.fr       */
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
		error_handler(cub, "Error\nMalloc failed for map copy\n");
	return (map_copy);
}

static int	validate_disconnected_areas(char **map_copy, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (ft_strchr("0NSEW", map_copy[i][j]))
			{
				if (flood_fill(map_copy, cub, i, j) == 0)
				{
					free_array(map_copy);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	free_array(map_copy);
	return (1);
}

int	is_map_valid(t_cub *cub)
{
	char	**map_copy;

	map_copy = init_validation(cub);
	if (flood_fill(map_copy, cub, cub->map_set.y, cub->map_set.x) == 0)
	{
		free_array(map_copy);
		return (0);
	}
	if (validate_disconnected_areas(map_copy, cub) == 0)
		return (0);
	return (1);
}
