/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:17:36 by fleite-j          #+#    #+#             */
/*   Updated: 2025/09/11 16:35:26 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_pixel_color(t_img *texture, int x, int y)
{
	char	*pxl_address;

	pxl_address = texture->pxl_ptr + (y * texture->l_len \
	+ x * (texture->bits_per_pxl / 8));
	return (*(unsigned int *)pxl_address);
}

void	put_pxl_in_img(t_img *img, int x, int y, int color)
{
	char	*pxl_address;

	pxl_address = img->pxl_ptr \
	+ (y * img->l_len + x * (img->bits_per_pxl / 8));
	*(unsigned int *)pxl_address = color;
}

void	draw_background(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				put_pxl_in_img(&cub->img, x, y, cub->map_set.ceiling_color);
			else
				put_pxl_in_img(&cub->img, x, y, cub->map_set.floor_color);
			x++;
		}
		y++;
	}
}

int	render(t_cub *cub)
{
	int	x;

	exec_key_event(cub);
	draw_background(cub);
	x = 0;
	while (x < WIDTH)
	{
		raycasting(cub, x);
		x++;
	}
	mlx_put_image_to_window(cub->mlx_connection, cub->mlx_window, \
							cub->img.img_ptr, 0, 0);
	return (0);
}
