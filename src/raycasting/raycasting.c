#include "cub3d.h"

static void	init_ray(t_cub *cub, t_ray *ray, double ray_dir_y, double ray_dir_x)
{
	ray->map_y = (int)cub->player.pos_y;
	ray->map_x = (int)cub->player.pos_x;
	if (ray_dir_x == 0)
		ray->delta_dst_x = 1e30;
	else
		ray->delta_dst_x = fabs(1 / ray_dir_x);
	if (ray_dir_y == 0)
		ray->delta_dst_y = 1e30;
	else
		ray->delta_dst_y = fabs(1 / ray_dir_y);
}

static void	get_left_or_right_side(t_cub *cub, t_ray *ray, double ray_dir_y, double ray_dir_x)
{
	if (ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dst_x = (cub->player.pos_x - ray->map_x) * ray->delta_dst_x;
	}
	else
	{
	    ray->step_x = 1;
	    ray->side_dst_x = (ray->map_x + 1.0 - cub->player.pos_x) * ray->delta_dst_x;
	}
	if (ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dst_y = (cub->player.pos_y - ray->map_y) * ray->delta_dst_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dst_y = (ray->map_y + 1.0 - cub->player.pos_y) * ray->delta_dst_y;
	}
}

t_ray	digital_differential_analizer(t_cub *cub, double ray_dir_y, double ray_dir_x)
{
	t_ray	ray;

	init_ray(cub, &ray, ray_dir_y, ray_dir_x);
	get_left_or_right_side(cub, &ray, ray_dir_y, ray_dir_x);
	ray.hit = NO_HIT;
	while (ray.hit == NO_HIT)
	{
		if (ray.side_dst_x < ray.side_dst_y)
		{
			ray.side_dst_x += ray.delta_dst_x;
			ray.map_x += ray.step_x;
			ray.side = ES_WE_WALL;
		}
		else
		{
			ray.side_dst_y += ray.delta_dst_y;
			ray.map_y += ray.step_y;
			ray.side = NO_SO_wALL;
		}
		if (cub->map[ray.map_y][ray.map_x] == '1')
			ray.hit = HIT;
	}
	return (ray);
}

void	raycasting(t_cub *cub, int x)
{
	double	camera_x;
	double	ray_dir_y;
	double	ray_dir_x;
	t_ray	ray_result;

	camera_x = 2 * x / (double)WIDTH - 1;
	ray_dir_x = cub->player.dir_x + cub->player.cam_plane_x * camera_x;
	ray_dir_y = cub->player.dir_y + cub->player.cam_plane_y * camera_x;
	ray_result = digital_differential_analizer(cub, ray_dir_y, ray_dir_x);
	draw_wall(cub, x, &ray_result);
}
