/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:18:31 by fleite-j          #+#    #+#             */
/*   Updated: 2025/08/29 23:18:32 by fleite-j         ###   ########.fr       */
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

void	draw_wall(t_cub *cub, int horizontal_slice, t_ray *ray)
{
	t_wall	wall;
	int		vertical_slice;
	int		color;

	wall = calculate_wall_dimension(ray);
	if (ray->side == VERTICAL_WALL)
	{
		if (ray->ray_dir_x > AXYS_ORIGIN)
			color = create_rgb(0, 144, 238, 144);
		else
			color = create_rgb(0, 46, 60, 28);
	}
	else
	{
		if (ray->ray_dir_y > AXYS_ORIGIN)
			color = create_rgb(0, 46, 27, 87);
		else
			color = create_rgb(0, 138, 3, 2);
	}
	vertical_slice = wall.draw_start;
	while (vertical_slice < wall.draw_end)
	{
		put_pxl_in_img(&cub->img, horizontal_slice, vertical_slice, color);
		vertical_slice++;
	}
}
