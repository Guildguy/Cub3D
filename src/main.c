/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:59:25 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/30 14:48:20 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(t_cub));
	cub.map_set.floor_color = -1;
	cub.map_set.ceiling_color = -1;
	if (argc != 2 || !valid_format(argv[1]))
		error_handler(&cub, "Error: Invalid arguments\n");
	if (main_parser(argv[1], &cub) == 0)
		error_handler(&cub, "Error: Failed to parse map file\n");
	if (!is_map_valid(&cub))
		error_handler(&cub, "Error: Invalid map\n");
	init_player(&cub);
	cub_init(&cub);
	mlx_loop_hook(cub.mlx_connection, render, &cub);
	mlx_loop(cub.mlx_connection);
	return (0);
}
 