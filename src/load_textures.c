#include "cub3d.h"

// static char *texture_list[] = {
// 	"./textures/wall1-1.xpm",
// 	"./textures/wall1-2.xpm",
// 	"./textures/wall1-3.xpm",
// 	"./textures/wall1-4.xpm",
// 	NULL
// };

int	load_textures(t_data *dt)
{
	t_texture	*texture;
	size_t 		i;

	print_separator_default();
	printf(TXT_YELLOW ">>> TEXTURES\n" TXT_RESET);

	i = 0;
	while (i < NUMBER_TEXTURES)
	{
		if (dt->map.wall_tile[i].is_color)
		{
			i++;
			continue ;
		}
		texture = &dt->map.wall_tile[i].texture;
		texture->texture_img = mlx_xpm_file_to_image(dt->mlx_ptr,
													texture->file,
													&texture->width,
													&texture->height);
		texture->texture_data = (int *)mlx_get_data_addr(texture->texture_img,
													&texture->bpp,
													&texture->size_line,
													&texture->endian);
		printf("Texture [%zu]: %s loaded!\n", i, texture->file);
		i++;
	}
	printf(TXT_GREEN "Done!\n" TXT_RESET);
	return (EXIT_SUCCESS);
}
