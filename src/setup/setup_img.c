#include "cub3d.h"

int	setup_img(t_data *dt)
{
	printf("Image setup...");
	dt->img->mlx_img = mlx_new_image(dt->mlx_ptr, WINDOW_W, WINDOW_H);
	dt->img->addr = mlx_get_data_addr(dt->img->mlx_img, &dt->img->bpp,
			&dt->img->line_len, &dt->img->endian);
	printf(" Done!\n");
	return (EXIT_SUCCESS);
}
