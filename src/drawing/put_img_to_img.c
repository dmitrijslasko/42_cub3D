#include "cub3d.h"

static unsigned int	get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)(img->addr + \
		(y * img->line_len + x * (img->bpp / 8))));
}

static void	put_pixel(t_img *img, int x, int y, unsigned int color)
{
	*(unsigned int *)(img->addr + (y * img->line_len + \
		x * (img->bpp / 8))) = color;
}

void	put_img_to_img(t_img *dest, t_img *src, int dx, int dy)
{
	size_t			x;
	size_t			y;
	int				src_x;
	int				src_y;
	unsigned int	color;

	y = 0;
	while ((int)y < dest->height)
	{
		x = 0;
		while ((int)x < dest->width)
		{
			src_x = x - dx;
			src_y = y - dy;
			if (src_x >= 0 && src_y >= 0 && src_x <= \
				(int)src->width && src_y <= (int)src->height)
			{
				color = get_pixel(src, src_x, src_y);
				put_pixel(dest, x, y, color);
			}
			x++;
		}
		y++;
	}
}
