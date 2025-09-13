/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:23:10 by fleite-j          #+#    #+#             */
/*   Updated: 2025/08/29 23:23:12 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

/* Structs */

typedef struct s_cub	t_cub;
typedef struct s_img	t_img;

typedef struct s_wall
{
	double	wall_dist;
	int		height;
	int		draw_start;
	int		draw_end;
}				t_wall;

typedef struct s_key_event
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	l_arrow;
	bool	r_arrow;
}				t_key_event;

typedef struct s_player
{
	double	dir_y;
	double	dir_x;
	double	cam_plane_y;
	double	cam_plane_x;
	double	pos_y;
	double	pos_x;
}				t_player;

typedef struct s_ray
{
	bool	hit;
	int		side;
	int		map_y;
	int		map_x;
	int		step_y;
	int		step_x;
	double	ray_dir_y;
	double	ray_dir_x;
	double	delta_dst_y;
	double	delta_dst_x;
	double	side_dst_y;
	double	side_dst_x;
}				t_ray;

/* Functions */

// src/raycasting/
// src/raycasting/raycasting.c
void	raycasting(t_cub *cub, int x);

// src/render/
// src/render/render.c
int		get_pixel_color(t_img *texture, int x, int y);
void	put_pxl_in_img(t_img *img, int x, int y, int color);
void	draw_background(t_cub *cub);
int		render(t_cub *cub);
// src/render/wall.c
void	draw_wall(t_cub *cub, int horizontal_slice, t_ray *ray);

#endif
