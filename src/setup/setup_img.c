#include "cub3d.h"

int	setup_img(t_data *dt, t_img *img, size_t width, size_t height)
{
	printf("Image setup...");
	img->mlx_img = mlx_new_image(dt->mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	printf(" Done!\n");
	return (EXIT_SUCCESS);
}
