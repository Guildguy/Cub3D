/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:19:37 by fleite-j          #+#    #+#             */
/*   Updated: 2025/08/29 23:19:40 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_cub *cub, double direction)
{
	double	angle;
	double	old_dir_x;
	double	old_plane_x;

	angle = R_SPEED * direction;
	old_dir_x = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(angle) \
	- cub->player.dir_y * sin(angle);
	cub->player.dir_y = old_dir_x * sin(angle) \
	+ cub->player.dir_y * cos(angle);
	old_plane_x = cub->player.cam_plane_x;
	cub->player.cam_plane_x = cub->player.cam_plane_x \
	* cos(angle) - cub->player.cam_plane_y * sin(angle);
	cub->player.cam_plane_y = old_plane_x * sin(angle) \
	+ cub->player.cam_plane_y * cos(angle);
}
