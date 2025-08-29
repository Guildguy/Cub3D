/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:32:14 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/27 20:46:38 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_rgb_color(char *rgb_string, t_cub *cub)
{
	char	**s_rgb;
	int		rgb[3];
	int		i;
	int		j;

	s_rgb = ft_split(rgb_string, ',');
	j = 0;
	while (s_rgb && s_rgb[j])
		j++;
	if (j != 3)
	{
		free_array(s_rgb);
		error_handler(cub, "Error: Invalid color format (must be R,G,B)\n");
	}
	i = -1;
	while (++i < 3)
	{
		rgb[i] = ft_atoi(s_rgb[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			error_handler(cub, "Error: Color value out of range (0-255)\n");
	}
	free_array(s_rgb);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	parse_color(char *line, t_cub *cub)
{
	int	i;
	int	color;

	i = 2;
	while (line[i] == ' ')
		i++;
	color = get_rgb_color(&line[i], cub);
	if (!ft_strncmp(line, "F ", 2))
	{
		if (cub->map_set.floor_color != -1)
			error_handler(cub, "Error: Floor color defined multiple times\n");
		cub->map_set.floor_color = color;
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		if (cub->map_set.ceiling_color != -1)
			error_handler(cub, "Error: Ceiling color defined multiple times\n");
		cub->map_set.ceiling_color = color;
	}
}

void	set_texture_path(char **path_to_set, char *path, t_cub *cub)
{
	if (*path_to_set != NULL)
		error_handler(cub, "Error: Texture defined multiple times\n");
	*path_to_set = ft_strdup(path);
	if (!*path_to_set)
		error_handler(cub, "Error: Malloc failed for texture path\n");
}

void	parse_texture(char *line, t_cub *cub)
{
	int	i;

	i = 3;
	while (line[i] == ' ')
		i++;
	if (!ft_strncmp(line, "NO ", 3))
		set_texture_path(&cub->map_set.no_path, &line[i], cub);
	else if (!ft_strncmp(line, "SO ", 3))
		set_texture_path(&cub->map_set.so_path, &line[i], cub);
	else if (!ft_strncmp(line, "WE ", 3))
		set_texture_path(&cub->map_set.we_path, &line[i], cub);
	else if (!ft_strncmp(line, "EA ", 3))
		set_texture_path(&cub->map_set.ea_path, &line[i], cub);
}

int	all_configs_set(t_cub *cub)
{
	if (cub->map_set.no_path && cub->map_set.so_path
		&& cub->map_set.we_path && cub->map_set.ea_path
		&& cub->map_set.floor_color != -1
		&& cub->map_set.ceiling_color != -1)
		return (1);
	return (0);
}
