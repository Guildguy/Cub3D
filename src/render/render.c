#include "cub3d.h"

void	put_pxl_in_img(t_img *img, int x, int y, int color)
{
	char	*pxl_address;

	pxl_address = img->pxl_ptr \
	+ (y * img->l_len + x * (img->bits_per_pxl / 8));
	*(unsigned int *)pxl_address = color;
}

void	draw_background(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				put_pxl_in_img(&cub->img, x, y, cub->sprite.ceilling_color);
			else
				put_pxl_in_img(&cub->img, x, y, cub->sprite.floor_color);
			x++;
		}
		y++;
	}
}

int	render(t_cub *cub)
{
	int	x;

	draw_background(cub);
	x = 0;
	while (x < WIDTH)
	{
		raycasting(cub, x);
		x++;
	}
	mlx_put_image_to_window(cub->mlx_connection, cub->mlx_window, \
							cub->img.img_ptr, 0, 0); //exibe a imagem na tela
	return (0);
}
