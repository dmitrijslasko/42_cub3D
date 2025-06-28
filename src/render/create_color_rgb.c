#include "cub3d.h"

int	create_color_rgba(int r, int g, int b, int a)
{
	return (a << 24) | (r << 16) | (g << 8) | b;
}

// RGB version (alpha = 255)
int	create_color_rgb(int r, int g, int b)
{
	return create_color_rgba(r, g, b, 255);
}
