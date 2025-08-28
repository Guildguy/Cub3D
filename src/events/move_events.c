#include "cub3d.h"

static void	rotate_player(t_cub *cub, double direction)
{
	double	angle;
	double	old_dir_x;
	double	old_plane_x;

	angle = R_SPEED * direction;
	old_dir_x = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(angle) - cub->player.dir_y * sin(angle);
	cub->player.dir_y = old_dir_x * sin(angle) + cub->player.dir_y * cos(angle);
	old_plane_x = cub->player.cam_plane_x;
	cub->player.cam_plane_x = cub->player.cam_plane_x * cos(angle) - cub->player.cam_plane_y * sin(angle);
	cub->player.cam_plane_y = old_plane_x * sin(angle) + cub->player.cam_plane_y * cos(angle);
}

void	rotation_handler(int keysym, t_cub *cub)
{
	if (keysym == XK_Right)
		rotate_player(cub, 1.0);
	else if (keysym == XK_Left)
		rotate_player(cub, -1.0);
}