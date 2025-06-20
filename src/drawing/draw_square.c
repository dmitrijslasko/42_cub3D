#include "cub3d.h"

// TODO DL: turn x, y into t_coor
void	draw_square_from_center(t_img *img, int x, int y, int size, int clr)
{
	int	curr_x;
	int	curr_y;

	curr_x = x - size / 2;
	while (curr_x <= x + size / 2)
	{
		curr_y = y - size / 2;
		while (curr_y <= y + size / 2)
		{
			if (pixel_is_in_window(curr_x, curr_y))
				img_pix_put(img, curr_x, curr_y, clr);
			++curr_y;
		}
		++curr_x;
	}
}

void	draw_square_from_top_left(t_img *img, int x, int y, int size, int clr)
{
	int	curr_x;
	int	curr_y;

	curr_x = x;
	while (curr_x <= x + size)
	{
		curr_y = y;
		while (curr_y <= y + size)
		{
			if (pixel_is_in_window(curr_x, curr_y))
				img_pix_put(img, curr_x, curr_y, clr);
			curr_y++;
		}
		curr_x++;
	}
}

int blend_colors(int fg, int bg, float alpha)
{
	int r = (int)(((fg >> 16) & 0xFF) * alpha + ((bg >> 16) & 0xFF) * (1 - alpha));
	int g = (int)(((fg >> 8) & 0xFF) * alpha + ((bg >> 8) & 0xFF) * (1 - alpha));
	int b = (int)((fg & 0xFF) * alpha + (bg & 0xFF) * (1 - alpha));
	return (r << 16) | (g << 8) | b;
}

int	get_pixel_color(t_img *img, int x, int y)
{
	char	*pixel;
	int		color;

	// Move pointer to pixel at (x, y)
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));

	// Read the color value depending on endian
	if (img->endian == 0) // little endian: B G R
		color = *(unsigned int *)pixel;
	else // big endian: R G B
		color = ((unsigned char)pixel[0] << 16) | ((unsigned char)pixel[1] << 8) | (unsigned char)pixel[2];

	return color;
}





