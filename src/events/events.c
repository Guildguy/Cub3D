#include "cub3d.h"

int	key_handler(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		close_handler(cub);
	else if (keysym == XK_Right || keysym == XK_Left)
		rotation_handler(keysym, cub);
	return (0);
}
