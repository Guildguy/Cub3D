#include "cub3d.h"

int	key_handler(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		close_handler(cub);
	return (0);
}

