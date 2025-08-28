/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:12:14 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/20 13:58:11 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* Headers */
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# include "libft.h"
# include "macros.h"

/* Structs */
typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bits_per_pxl;
	int		endian;
	int		l_len;
}				t_img;

typedef struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		map_width;
	int		map_height;
}				t_map;

typedef struct s_ceiling_ground
{
	int	floor_color;
	int	ceilling_color;
}				t_ceiling_ground;

typedef struct s_wall
{
	double	wall_dist;
	int		height;
	int		draw_start;
	int		draw_end;
}				t_wall;

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
	double	delta_dst_y;
	double	delta_dst_x;
	double	side_dst_y;
	double	side_dst_x;
}				t_ray;

typedef struct s_cub
{
	char				*name;
	void				*mlx_connection;
	void				*mlx_window;
	t_img				img;
	t_ceiling_ground	sprite;
	t_player			player;
	char				**map;
}				t_cub;

/*typedef struct s_cube
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_rgb;
	int		ceiling_rgb;
	char	**map;
	int		map_width;

	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
}				t_cube;*/

void	cub_init(t_cub *cub);
void	init_data(t_cub *cub);
int		close_handler(t_cub *cub);
int		error_handler(t_cub *cub, char *error_message);
void	cleanup(t_cub *cub);

void	rotation_handler(int keysym, t_cub *cub);
void	movement_handler(int keysym, t_cub *cub);
int		key_handler(int keysym, t_cub *cub);

void	put_pxl_in_img(t_img *img, int x, int y, int color);

char	**create_hard_map(void);

int		create_rgb(int t, int r, int g, int b);
void	draw_background(t_cub *cub);
int		render(t_cub *cub);
int		valid_format(char *str);

void	init_player(t_cub *cub);

void	raycasting(t_cub *cub, int x);

void	draw_wall(t_cub *cub, int horizontal_slice, t_ray *ray_result);
void	free_map(char **map);
int		valid_format(char *str);

#endif