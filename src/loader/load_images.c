/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:28:23 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/30 13:51:01 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_cub *cub, t_img *texture_img, char *path)
{
	int	width;
	int	height;

	texture_img->img_ptr = mlx_xpm_file_to_image(cub->mlx_connection,
			path, &width, &height);
	if (!texture_img->img_ptr)
		error_handler(cub, "Error\nFailed to load texture image.\n");
	texture_img->pxl_ptr = mlx_get_data_addr(texture_img->img_ptr,
			&texture_img->bits_per_pxl, &texture_img->l_len,
			&texture_img->endian);
	if (!texture_img->pxl_ptr)
		error_handler(cub, "Error\nFailed to get texture data address.\n");
}

// void	cub_init(t_cub *cub)
// {
// 	load_texture(cub, &cub->north_texture, cub->map_set.no_path);
// 	load_texture(cub, &cub->south_texture, cub->map_set.so_path);
// 	load_texture(cub, &cub->west_texture, cub->map_set.we_path);
// 	load_texture(cub, &cub->east_texture, cub->map_set.ea_path);
// }