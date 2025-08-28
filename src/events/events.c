#include "cub3d.h"

int	key_handler(int keysym, t_cub *cub)
{
	if (keysym == ESC)
		close_handler(cub);
	return (0);
}

