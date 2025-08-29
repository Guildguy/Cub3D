/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:21:18 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/28 20:56:08 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_line	*new_node(char *line)
{
	t_line	*new;

	new = malloc(sizeof(t_line));
	if (!new)
		return (NULL);
	new->current = ft_strtrim(line, "\n");
	if (!new->current)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

t_line	*add_node_back(t_line **list_head, t_line *new_node)
{
	t_line	*temp;

	if (!list_head || !new_node)
		return (NULL);
	if (!*list_head)
		*list_head = new_node;
	else
	{
		temp = *list_head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	return (*list_head);
}

void	free_list(t_line *head)
{
	t_line	*temp;
	t_line	*next;

	temp = head;
	while (temp)
	{
		next = temp->next;
		free(temp->current);
		free(temp);
		temp = next;
	}
}

int	count_lines(t_line	*map_list)
{
	int	count;

	count = 0;
	while (map_list)
	{
		count++;
		map_list = map_list->next;
	}
	return (count);
}
