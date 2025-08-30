#include "cub3d.h"

int	close_handler(t_cub *cub)
{	
	cleanup(cub);
	exit(EXIT_SUCCESS);
}
