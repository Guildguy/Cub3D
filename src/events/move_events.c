#include "cub3d.h"

static void	rotate_player(t_cub *cub, double direction)
{
	double	angle;
	double	old_dirX;
	double	old_planeX;

	angle = R_SPEED * direction;
	old_dirX = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(angle) - cub->player.dir_y * sin(angle);
	cub->player.dir_y = old_dirX * sin(angle) + cub->player.dir_y * cos(angle);
	old_planeX = cub->player.cam_plane_x;
	cub->player.cam_plane_x = cub->player.cam_plane_x * cos(angle) - cub->player.cam_plane_y * sin(angle);
	cub->player.cam_plane_y = old_planeX * sin(angle) + cub->player.cam_plane_y * cos(angle);
}