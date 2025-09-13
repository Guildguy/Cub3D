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
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= cub->map_set.map_height)
		return (true);
	if (map_x < 0 || map_x >= (int)ft_strlen(cub->map[map_y]))
		return (true);
	if (cub->map[map_y][map_x] == ' ')
		return (true);
	if (cub->map[map_y][map_x] == WALL)
		return (true);
	return (false);
}

void	forward_backward_move(t_cub *cub, double direction)
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

void	left_right_move(t_cub *cub, double direction)
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
