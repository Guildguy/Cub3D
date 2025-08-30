/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:17:19 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/30 18:00:56 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	process_line(char *line, t_cub *cub, int fd)
{
	char	*trim_line;

	trim_line = line;
	while (ft_isspace(*trim_line))
		trim_line++;
	if (!ft_strncmp(trim_line, "NO ", 3) || !ft_strncmp(trim_line, "SO ", 3)
		|| !ft_strncmp(trim_line, "WE ", 3) || !ft_strncmp(trim_line, "EA ", 3))
	{
		if (parse_texture(trim_line, cub) == 0)
			return (0);
	}
	else if (!ft_strncmp(trim_line, "F ", 2) || !ft_strncmp(trim_line, "C ", 2))
	{
		if (parse_color(trim_line, cub) == 0)
			return (0);
	}
	else if (trim_line[0] != '\n' && trim_line[0] != '\0')
	{
		if (all_configs_set(cub) == 0)
			return (0);
		parse_map_grid(line, cub, fd);
		return (1);
	}
	return (2);
}

int	main_parser(char *filename, t_cub *cub)
{
	int		fd;
	char	*line;
	int		status;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		status = process_line(line, cub, fd);
		if (status == 1)
			break ;
		if (status == 0)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
