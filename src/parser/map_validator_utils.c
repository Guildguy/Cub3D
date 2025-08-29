/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:17:54 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/28 13:30:09 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	flood_fill(char **map_copy, t_cub *cub, int y, int x)
{
	if (y < 0 || y >= cub->map_set.map_height || x < 0
		|| x >= cub->map_set.map_width)
		return (0);
	if (map_copy[y][x] == ' ')
		return (0);
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
		return (1);
	map_copy[y][x] = 'F';
	if (flood_fill(map_copy, cub, y + 1, x) == 0)
		return (0);
	if (flood_fill(map_copy, cub, y - 1, x) == 0)
		return (0);
	if (flood_fill(map_copy, cub, y, x + 1) == 0)
		return (0);
	if (flood_fill(map_copy, cub, y, x - 1) == 0)
		return (0);
	return (1);
}

int	get_map_width(char **map)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > width)
			width = j;
		i++;
	}
	return (width);
}

char	**duplicate_map(char **map)
{
	int		i;
	size_t	lines_count;
	char	**map_copy;

	lines_count = 0;
	while (map[lines_count])
		lines_count++;
	map_copy = malloc(sizeof(char *) * (lines_count + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			free_array(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	has_only_valid_characters(char **map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				player_count++;
			else if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (0);
	return (1);
}

void	player_coordinates(char **map, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				cub->map_set.x = j;
				cub->map_set.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
