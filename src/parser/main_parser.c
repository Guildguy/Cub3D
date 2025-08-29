/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:17:19 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/28 13:00:17 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_boundary_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '1'))
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	return (0);
}

static int	process_line(char *line, t_cub *cub, int fd)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
		parse_texture(line, cub);
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		parse_color(line, cub);
	else if (line[0] != '\n')
	{
		if (all_configs_set(cub) == 0)
			error_handler(cub, "Error: Missing configuration before map\n");
		if (is_valid_boundary_line(line) == 0)
			error_handler(cub, "Error: Invalid content\n");
		parse_map_grid(line, cub, fd);
		return (1);
	}
	return (0);
}

int	main_parser(char *filename, t_cub *cub)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (process_line(line, cub, fd))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
