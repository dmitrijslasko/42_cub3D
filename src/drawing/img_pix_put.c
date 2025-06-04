#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int clr)
{
	char	*pixel;
	int		i;

	if (pixel_is_in_window(x, y) == 0)
		return ;
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (clr >> i) & 0xFF;
		else
			*pixel++ = (clr >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}
