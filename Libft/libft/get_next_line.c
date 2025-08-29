/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:38:00 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/28 13:46:48 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_and_conc(int fd, char **read_buffer)
{
	char	*temp_buffer;
	char	*conc_buffer;
	int		bytes_read;

	temp_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buffer)
		return (-1);
	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		temp_buffer[bytes_read] = '\0';
		conc_buffer = ft_strjoin(*read_buffer, temp_buffer);
		free(*read_buffer);
		*read_buffer = conc_buffer;
		if (ft_strchr(*read_buffer, '\n'))
			break ;
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	}
	free(temp_buffer);
	return (bytes_read);
}

static char	*extract_line(char **read_buffer)
{
	char	*line;
	char	*newl_pos;
	char	*remainder;

	newl_pos = ft_strchr(*read_buffer, '\n');
	if (!newl_pos)
	{
		line = ft_strdup(*read_buffer);
		free(*read_buffer);
		*read_buffer = NULL;
		return (line);
	}
	line = ft_substr(*read_buffer, 0, newl_pos - *read_buffer + 1);
	if (!line)
		return (NULL);
	remainder = ft_strdup(newl_pos + 1);
	if (!remainder)
	{
		free(line);
		return (NULL);
	}
	free(*read_buffer);
	*read_buffer = remainder;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*read_buffer;
	int			b_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_buffer)
	{
		read_buffer = (char *)malloc(1);
		if (!read_buffer)
			return (NULL);
		read_buffer[0] = '\0';
	}
	b_read = read_and_conc(fd, &read_buffer);
	if (b_read < 0 || (b_read == 0 && !read_buffer[0]))
	{
		free(read_buffer);
		read_buffer = NULL;
		return (NULL);
	}
	return (extract_line(&read_buffer));
}
