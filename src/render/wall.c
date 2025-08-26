#include "cub3d.h"

static t_wall	calculate_wall_dimension(t_ray *ray_result)
{
	t_wall	wall;

	if (ray_result->side == 0)
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

void	draw_wall(t_cub *cub, int horizontal_slice, t_ray *ray_result)
{
	t_wall	wall;
	int		vertical_slice;

	wall = calculate_wall_dimension(ray_result);
	vertical_slice = wall.draw_start;
	while (vertical_slice < wall.draw_end)
	{
		if (ray_result->side == 1) //horizontal wall
			put_pxl_in_img(&cub->img, horizontal_slice, vertical_slice, create_rgb(0, 0, 176, 16));
		else //vertical wall
			put_pxl_in_img(&cub->img, horizontal_slice, vertical_slice, create_rgb(0, 0, 255, 0));
		vertical_slice++;
	}
}
