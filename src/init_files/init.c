/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleite-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:20:23 by fleite-j          #+#    #+#             */
/*   Updated: 2025/08/29 23:20:25 by fleite-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	err_exit(t_cub *cub)
{
	ft_putstr_fd("ERROR: failed to init MLX", STDERR_FILENO);
	if (cub->img.img_ptr)
		mlx_destroy_image(cub->mlx_connection, cub->img.img_ptr);
	if (cub->mlx_window)
		mlx_destroy_window(cub->mlx_connection, cub->mlx_window);
	if (cub->mlx_connection)
	{
		mlx_destroy_display(cub->mlx_connection);
		free(cub->mlx_connection);
	}
	exit(EXIT_FAILURE);
}

static void	events_init(t_cub *cub)
{
	mlx_hook(cub->mlx_window,
		KeyPress,
		KeyPressMask,
		key_handler,
		cub);
	mlx_hook(cub->mlx_window,
		DestroyNotify,
		StructureNotifyMask,
		close_handler,
		cub);
}

void	cub_init(t_cub *cub)
{
	cub->mlx_connection = mlx_init();
	if (!cub->mlx_connection)
		err_exit(cub);
	cub->mlx_window = mlx_new_window(cub->mlx_connection, \
		WIDTH, HEIGHT, "cub3D");
	if (!cub->mlx_window)
		err_exit(cub);
	cub->img.img_ptr = mlx_new_image(cub->mlx_connection, WIDTH, HEIGHT);
	if (!cub->img.img_ptr)
		err_exit(cub);
	cub->img.pxl_ptr = mlx_get_data_addr(cub->img.img_ptr, \
	&cub->img.bits_per_pxl, \
	&cub->img.l_len, \
	&cub->img.endian);
	if (!cub->img.pxl_ptr)
		err_exit(cub);
	events_init(cub);
}
