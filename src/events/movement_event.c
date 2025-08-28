#include "cub3d.h"

static void	forward_backward_move(t_cub *cub, double direction)
{
	double	new_y;
	double	new_x;

	new_y = cub->player.pos_y + cub->player.dir_y * M_SPEED * direction;
	new_x = cub->player.pos_x + cub->player.dir_x * M_SPEED * direction;
	if (cub->map[(int)cub->player.pos_y][(int)new_x] != WALL)
		cub->player.pos_x = new_x;
	if (cub->map[(int)new_y][(int)cub->player.pos_x] != WALL)
		cub->player.pos_y = new_y;
}

void	movement_handler(int keysym, t_cub *cub)
{
	if (keysym == XK_w || keysym == XK_W)
		forward_backward_move(cub, 1.0);
	else if (keysym == XK_s || keysym == XK_S)
		forward_backward_move(cub, -1.0);
}
