/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:32:14 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/09/12 17:28:40 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_rgb_strings(char **s_rgb)
{
	int	i;
	int	j;

	j = 0;
	while (s_rgb && s_rgb[j])
		j++;
	if (j != 3)
		return (0);
	i = -1;
	while (++i < 3)
	{
		if (!is_digit_string(s_rgb[i]))
			return (0);
	}
	return (1);
}

static int	get_rgb_color(char *rgb_string)
{
	char	**s_rgb;
	int		rgb[3];
	int		i;

	trim_trailing_whitespace(rgb_string);
	s_rgb = ft_split(rgb_string, ',');
	if (validate_rgb_strings(s_rgb) == 0)
	{
		free_array(s_rgb);
		return (-1);
	}
	i = -1;
	while (++i < 3)
	{
		rgb[i] = ft_atoi(s_rgb[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			free_array(s_rgb);
			return (-1);
		}
	}
	free_array(s_rgb);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int	parse_color(char *line, t_cub *cub)
{
	int	i;
	int	color;

	i = 2;
	while (ft_isspace(line[i]))
		i++;
	color = get_rgb_color(&line[i]);
	if (color == -1)
		return (0);
	if (!ft_strncmp(line, "F ", 2))
	{
		if (cub->map_set.floor_color != -1)
			return (0);
		cub->map_set.floor_color = color;
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		if (cub->map_set.ceiling_color != -1)
			return (0);
		cub->map_set.ceiling_color = color;
	}
	return (1);
}

static int	set_texture_path(char **path_to_set, char *path)
{
	if (*path_to_set != NULL)
		return (0);
	trim_trailing_whitespace(path);
	*path_to_set = ft_strdup(path);
	if (!*path_to_set)
		return (0);
	return (1);
}

int	parse_texture(char *line, t_cub *cub)
{
	int	i;

	i = 3;
	while (ft_isspace(line[i]))
		i++;
	if (!ft_strncmp(line, "NO ", 3))
		return (set_texture_path(&cub->map_set.no_path, &line[i]));
	else if (!ft_strncmp(line, "SO ", 3))
		return (set_texture_path(&cub->map_set.so_path, &line[i]));
	else if (!ft_strncmp(line, "WE ", 3))
		return (set_texture_path(&cub->map_set.we_path, &line[i]));
	else if (!ft_strncmp(line, "EA ", 3))
		return (set_texture_path(&cub->map_set.ea_path, &line[i]));
	return (1);
}
