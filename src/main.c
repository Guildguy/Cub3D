/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:59:25 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/30 13:51:01 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int c, char **v)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(t_cub));
	cub.map_set.floor_color = -1;
	cub.map_set.ceiling_color = -1;
	if (c != 2 || !valid_format(v[1]))
		error_handler(&cub, "Error\nInvalid arguments\n");
	if (main_parser(v[1], &cub) == 0)
		error_handler(&cub, "Error\nFailed to parse map file\n");
	if (!has_only_valid_characters(cub.map))
		error_handler(&cub, "Error\ninvalid characters\n");
	if (!is_map_closed(&cub))
		error_handler(&cub, "Error\nMap is not enclosed by walls\n");
	init_player(&cub);
	cub_init(&cub);
	mlx_loop_hook(cub.mlx_connection, render, &cub);
	mlx_loop(cub.mlx_connection);
	return (0);
}
