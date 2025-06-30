#include "cub3d.h"

void	free_img(t_img *img, void *mlx_ptr)
{
	if (!img)
		return ;
	if (img->mlx_img && mlx_ptr)
		mlx_destroy_image(mlx_ptr, img->mlx_img);
	img->mlx_img = NULL;
}
