/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:12:14 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/27 19:11:47 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_line	*read_map_to_list(char *line, t_cub *cub, int fd)
{
	t_line	*temp;
	t_line	*map_list;

	map_list = NULL;
	while (1)
	{
		temp = new_node(line);
		if (!temp)
		{
			free(line);
			free_list(map_list);
			error_handler(cub, "Error: Malloc failed during map parsing\n");
		}
		add_node_back(&map_list, temp);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	return (map_list);
}

char	**convert_list_to_array(t_line *list, t_cub *cub)
{
	char	**array;
	int		count;
	t_line	*temp;
	int		i;

	count = count_lines(list);
	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	temp = list;
	i = 0;
	while (temp)
	{
		array[i] = ft_strdup(temp->current);
		if (!array[i])
		{
			free_array(array);
			return (NULL);
		}
		temp = temp->next;
		i++;
	}
	cub->map_set.map_height = i;
	array[i] = NULL;
	return (array);
}

void	parse_map_grid(char *line, t_cub *cub, int fd)
{
	t_line	*map_list;

	map_list = read_map_to_list(line, cub, fd);
	cub->map = convert_list_to_array(map_list, cub);
	if (!cub->map)
	{
		free_list(map_list);
		error_handler(cub, "Error: Malloc failed during map conversion\n");
	}
	free_list(map_list);
}
