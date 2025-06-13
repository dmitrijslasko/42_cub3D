#include "cub3d.h"

static char *texture_list[] = {
	"./textures/wall-1.xpm",
	"./textures/wall-2.xpm",
	"./textures/wall-3.xpm",
	"./textures/wall-4.xpm",
	NULL
};

int load_textures(t_data *dt)
{
	t_texture *texture;
	size_t i;

	printf("Loading textures...");

	texture = dt->textures;
	i = 0;
	while (i < 4)
	{
		texture->texture_img = mlx_xpm_file_to_image(dt->mlx_ptr, texture_list[i], &texture->width, &texture->height);
		texture->texture_data = (int *)mlx_get_data_addr(texture->texture_img, &texture->bpp, &texture->size_line, &texture->endian);
		i++;
		texture++;
	}
	printf(" Done!\n");
	return (EXIT_SUCCESS);
}
