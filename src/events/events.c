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

int	key_handler(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		close_handler(cub);
	else if (keysym == XK_Right || keysym == XK_Left)
		rotation_handler(keysym, cub);
	else if (keysym == XK_s || keysym == XK_S || \
			keysym == XK_w || keysym == XK_W || \
			keysym == XK_a || keysym == XK_A || \
			keysym == XK_d || keysym == XK_D)
		movement_handler(keysym, cub);
	return (0);
}
