/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:51:36 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/09/12 17:38:51 by sdavi-al         ###   ########.fr       */
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

static void	destroy_mlx_images(t_cub *cub)
{
	if (cub->north_texture.img_ptr)
		mlx_destroy_image(cub->mlx_connection, cub->north_texture.img_ptr);
	if (cub->south_texture.img_ptr)
		mlx_destroy_image(cub->mlx_connection, cub->south_texture.img_ptr);
	if (cub->west_texture.img_ptr)
		mlx_destroy_image(cub->mlx_connection, cub->west_texture.img_ptr);
	if (cub->east_texture.img_ptr)
		mlx_destroy_image(cub->mlx_connection, cub->east_texture.img_ptr);
	if (cub->img.img_ptr)
		mlx_destroy_image(cub->mlx_connection, cub->img.img_ptr);
}

static void	free_map_data(t_cub *cub)
{
	if (cub->map_set.no_path)
		free(cub->map_set.no_path);
	if (cub->map_set.so_path)
		free(cub->map_set.so_path);
	if (cub->map_set.we_path)
		free(cub->map_set.we_path);
	if (cub->map_set.ea_path)
		free(cub->map_set.ea_path);
	if (cub->map)
		free_array(cub->map);
}

void	cleanup(t_cub *cub)
{
	free_map_data(cub);
	if (cub->mlx_connection)
	{
		destroy_mlx_images(cub);
		if (cub->mlx_window)
			mlx_destroy_window(cub->mlx_connection, cub->mlx_window);
		mlx_destroy_display(cub->mlx_connection);
		free(cub->mlx_connection);
	}
}

int	error_handler(t_cub *cub, char *error_message)
{	
	write(2, error_message, ft_strlen(error_message));
	cleanup(cub);
	exit(EXIT_FAILURE);
}
