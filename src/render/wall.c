/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:18:31 by fleite-j          #+#    #+#             */
/*   Updated: 2025/09/11 16:36:14 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_wall	calculate_wall_dimension(t_ray *ray_result)
{
	t_wall	wall;

	if (ray_result->side == VERTICAL_WALL)
		wall.wall_dist = (ray_result->side_dst_x - ray_result->delta_dst_x);
	else
		wall.wall_dist = (ray_result->side_dst_y - ray_result->delta_dst_y);
	wall.height = (int)(HEIGHT / wall.wall_dist);
	wall.draw_start = -wall.height / 2 + HEIGHT / 2;
	if (wall.draw_start < 0)
		wall.draw_start = 0;
	wall.draw_end = wall.height / 2 + HEIGHT / 2;
	if (wall.draw_end >= HEIGHT)
		wall.draw_end = HEIGHT - 1;
	return (wall);
}

static t_img	*get_wall_textures(t_cub *cub, t_ray *ray)
{
	if (ray->side == VERTICAL_WALL)
	{
		if (ray->ray_dir_x > AXYS_ORIGIN)
			return (&cub->west_texture);
		else
			return (&cub->east_texture);
	}
	else
	{
		if (ray->ray_dir_y > AXYS_ORIGIN)
			return (&cub->north_texture);
		else
			return (&cub->south_texture);
	}
}

static int	get_texture_coordinates(t_cub *cub, t_ray *ray, t_wall *wall)
{
	int		texture;
	double	wallx;

	if (ray->side == VERTICAL_WALL)
		wallx = cub->player.pos_y + wall->wall_dist * ray->ray_dir_y;
	else
		wallx = cub->player.pos_x + wall->wall_dist * ray->ray_dir_x;
	wallx -= floor(wallx);
	texture = (int)(wallx * (double)TEXTURE_WIDTH);
	if ((ray->side == VERTICAL_WALL && ray->ray_dir_x < 0) || \
	(ray->side == HORIZONTAL_WALL && ray->ray_dir_y > 0))
		texture = TEXTURE_HEIGHT - texture - 1;
	return (texture);
}

void	draw_wall(t_cub *cub, int horizontal_slice, t_ray *ray)
{
	t_wall	wall;
	t_img	*textures;
	int		coordinates_x;
	int		coordinates_y;
	int		y_to_texture;
	int		vertical_slice;
	int		color;

	wall = calculate_wall_dimension(ray);
	textures = get_wall_textures(cub, ray);
	coordinates_x = get_texture_coordinates(cub, ray, &wall);
	vertical_slice = wall.draw_start;
	while (vertical_slice <= wall.draw_end)
	{
		y_to_texture = vertical_slice * 256 - HEIGHT * 128 + wall.height * 128;
		coordinates_y = ((y_to_texture * TEXTURE_HEIGHT) / wall.height) / 256;
		color = get_pixel_color(textures, coordinates_x, coordinates_y);
		put_pxl_in_img(&cub->img, horizontal_slice, vertical_slice, color);
		vertical_slice++;
	}
}
