/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:19:21 by fleite-j          #+#    #+#             */
/*   Updated: 2025/08/29 23:19:24 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_wall(t_cub *cub, double x, double y)
{
	if (cub->map[(int)y][(int)x] == WALL)
		return (true);
	return (false);
}

static void	forward_backward_move(t_cub *cub, double direction)
{
	double	new_y;
	double	new_x;

	new_y = cub->player.pos_y + cub->player.dir_y * M_SPEED * direction;
	new_x = cub->player.pos_x + cub->player.dir_x * M_SPEED * direction;
	if (!is_wall(cub, new_x, cub->player.pos_y))
		cub->player.pos_x = new_x;
	if (!is_wall(cub, cub->player.pos_x, new_y))
		cub->player.pos_y = new_y;
}

static void	left_right_move(t_cub *cub, double direction)
{
	double	new_y;
	double	new_x;

	new_y = cub->player.pos_y + cub->player.cam_plane_y * M_SPEED * direction;
	new_x = cub->player.pos_x + cub->player.cam_plane_x * M_SPEED * direction;
	if (!is_wall(cub, new_x, cub->player.pos_y))
		cub->player.pos_x = new_x;
	if (!is_wall(cub, cub->player.pos_x, new_y))
		cub->player.pos_y = new_y;
}

void	movement_handler(int keysym, t_cub *cub)
{
	if (keysym == XK_w || keysym == XK_W)
		forward_backward_move(cub, 1.0);
	else if (keysym == XK_s || keysym == XK_S)
		forward_backward_move(cub, -1.0);
	else if (keysym == XK_a || keysym == XK_A)
		left_right_move(cub, -1.0);
	else if (keysym == XK_d || keysym == XK_d)
		left_right_move(cub, 1.0);
}
