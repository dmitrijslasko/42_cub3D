//NOTE DL: I don't remember why it's here
//int blend_colors(int fg, int bg, float alpha)
//{
//	int r;
//	int g;
//	int b;

//	r = (int)(((fg >> 16) & 0xFF) * alpha + ((bg >> 16) & 0xFF) * (1 - alpha));
//	g = (int)(((fg >> 8) & 0xFF) * alpha + ((bg >> 8) & 0xFF) * (1 - alpha));
//	b = (int)((fg & 0xFF) * alpha + (bg & 0xFF) * (1 - alpha));
//	return ((r << 16) | (g << 8) | b);
//}

// NOTE DL: I don't remember why it's here
//int	get_pixel_color(t_img *img, int x, int y)
//{
//	char	*pixel;
//	int		color;

//	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
//	if (img->endian == 0)
//		color = *(unsigned int *)pixel;
//	else
//		color = ((unsigned char)pixel[0] << 16) |
//				((unsigned char)pixel[1] << 8) |
//				(unsigned char)pixel[2];
//	return (color);
//}
