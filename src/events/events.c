#include "cub3d.h"

int	key_handler(int keysym, t_cub *cub)
{
	if (keysym == ESC)
		close_handler(cub);
	else if (keysym == RIGHT || keysym == LEFT)
		rotation_handler(keysym, cub);
	return (0);
}
