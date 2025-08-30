/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:20:38 by fleite-j          #+#    #+#             */
/*   Updated: 2025/08/29 23:20:40 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_direction(t_cub *cub, char direction)
{
	if (direction == 'N')
	{
		cub->player.dir_y = -1;
		cub->player.cam_plane_x = 0.666;
	}
	else if (direction == 'S')
	{
		cub->player.dir_y = 1;
		cub->player.cam_plane_x = -0.666;
	}
	else if (direction == 'E')
	{
		cub->player.dir_x = 1;
		cub->player.cam_plane_y = 0.666;
	}
	else if (direction == 'W')
	{
		cub->player.dir_x = -1;
		cub->player.cam_plane_y = -0.666;
	}
}

void	init_player(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (ft_strchr("NSEW", cub->map[y][x]))
			{
				cub->player.pos_x = x + 0.5;
				cub->player.pos_y = y + 0.5;
				set_player_direction(cub, cub->map[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
}
