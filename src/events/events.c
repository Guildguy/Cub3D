/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:19:06 by fleite-j          #+#    #+#             */
/*   Updated: 2025/08/29 23:19:09 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_handler(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		close_handler(cub);
	else if (keysym == XK_Right)
		cub->keys.r_arrow = true;
	else if (keysym == XK_Left)
		cub->keys.l_arrow = true;
	else if (keysym == XK_s || keysym == XK_S)
		cub->keys.s = true;
	else if (keysym == XK_w || keysym == XK_W)
		cub->keys.w = true;
	else if (keysym == XK_a || keysym == XK_A)
		cub->keys.a = true;
	else if (keysym == XK_d || keysym == XK_D)
		cub->keys.d = true;
	return (0);
}

int	key_release_handler(int keysym, t_cub *cub)
{
	if (keysym == XK_Right)
		cub->keys.r_arrow = false;
	else if (keysym == XK_Left)
		cub->keys.l_arrow = false;
	else if (keysym == XK_s || keysym == XK_S)
		cub->keys.s = false;
	else if (keysym == XK_w || keysym == XK_W)
		cub->keys.w = false;
	else if (keysym == XK_a || keysym == XK_A)
		cub->keys.a = false;
	else if (keysym == XK_d || keysym == XK_D)
		cub->keys.d = false;
	return (0);
}

void	exec_key_event(t_cub *cub)
{
	if (cub->keys.r_arrow)
		rotate_player(cub, 1.0);
	if (cub->keys.l_arrow)
		rotate_player(cub, -1.0);
	if (cub->keys.s)
		forward_backward_move(cub, -1.0);
	if (cub->keys.w)
		forward_backward_move(cub, 1.0);
	if (cub->keys.a)
		left_right_move(cub, -1.0);
	if (cub->keys.d)
		left_right_move(cub, 1.0);
}
