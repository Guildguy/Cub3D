/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:12:14 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/29 11:27:55 by sdavi-al         ###   ########.fr       */
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
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"

# include "libft.h"
# include "macros.h"
# include "parser.h"
# include "raycasting.h"

/* Struct */
typedef struct s_cub
{
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
	t_map		map_set;
	char		**map;
	t_player	player;
	t_img		north_texture;
	t_img		south_texture;
	t_img		west_texture;
	t_img		east_texture;
}				t_cub;

/* Functions */

// src/cleanup/
// src/cleanup/cleanup.c
void	free_array(char **array);
void	cleanup(t_cub *cub);
int		error_handler(t_cub *cub, char *error_message);

// src/events/
// src/events/close_event.c
int		close_handler(t_cub *cub);
// src/events/rotate_event.c
void	rotation_handler(int keysym, t_cub *cub);
// src/events/movement_event.c
void	movement_handler(int keysym, t_cub *cub);
// src/events/events.c
int		key_handler(int keysym, t_cub *cub);

// src/init_files/
// src/init_files/init_player.c
void	init_player(t_cub *cub);
// src/init_files/init.c
void	cub_init(t_cub *cub);

#endif
