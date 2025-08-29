/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:51:36 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/20 15:30:54 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	cleanup(t_cub *cub)
{
	if (cub->img.img_ptr)
		mlx_destroy_image(cub->mlx_connection, cub->img.img_ptr);
	if (cub->mlx_window)
		mlx_destroy_window(cub->mlx_connection, cub->mlx_window);
	if (cub->mlx_connection)
	{
		mlx_destroy_display(cub->mlx_connection);
		free(cub->mlx_connection);
	}
	if (cub->map)
		free_array(cub->map);
}

int	error_handler(t_cub *cub, char *error_message)
{	
	write(2, error_message, ft_strlen(error_message));
	cleanup(cub);
	exit(EXIT_FAILURE);
}

int	close_handler(t_cub *cub)
{	
	cleanup(cub);
	exit(EXIT_SUCCESS);
}
