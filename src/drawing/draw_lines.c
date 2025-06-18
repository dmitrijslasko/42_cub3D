#include "cub3d.h"

void	draw_vertical_line(t_data *dt, t_coor pt_1, t_coor pt_2, int color)
{
	size_t	curr_y;

	if (pt_1.y > pt_2.y)
		swap(&pt_1, &pt_2, sizeof(t_coor));
	//printf("Drawing vertical line... (%d %d) to (%d %d)\n", pt_1.x, pt_1.y, pt_2.x, pt_2.y);
	curr_y = pt_1.y;
	while (curr_y < pt_2.y)
	{
		img_pix_put(dt->img, pt_1.x, curr_y, color);
		++curr_y;
	}
}

/**
 * @brief Draw a line using the Bresenhamn algorithm.
 *
 * @param dt
 * @param pt1
 * @param pt2
 * @param color
 */
// TODO DL: refactor to fit the norm. The currect implementation is kindly provided by ChatGPT. :)
void draw_line(t_data *dt, t_coor pt1, t_coor pt2, int color)
{
	int dx = abs((int)pt2.x - (int)pt1.x);
	int dy = abs((int)pt2.y - (int)pt1.y);
	int sx = (pt1.x < pt2.x) ? 1 : -1;
	int sy = (pt1.y < pt2.y) ? 1 : -1;
	int err = dx - dy;
	int e2;

	while (1)
	{
		img_pix_put(dt->img, pt1.x, pt1.y, color);
		if (pt1.x == pt2.x && pt1.y == pt2.y)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			pt1.x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			pt1.y += sy;
		}
	}
}

/* DEPRECATED: old implementation of the draw_line function without Bresenham.

//static void	draw_line_segment(t_data *dt, t_coor curr, t_coor next, int color)
//{
//	if (abs(curr.y - next.y) >= 1)
//	{
//		draw_vertical_line(dt, curr, next, color);
//	}
//	else
//	{
//		img_pix_put(dt->img, curr.x, curr.y, color);
//	}
//}


It fails to draw continous line at specific diagonal slopes.
*/
//void	draw_line(t_data *dt, t_coor pt_1, t_coor pt_2, int color)
//{
//	float	slope;
//	t_coor	curr;
//	t_coor	next;

//	if (pt_1.x == pt_2.x)
//		draw_vertical_line(dt, pt_1, pt_2, color);
//	if (pt_1.x > pt_2.x)
//		swap(&pt_1, &pt_2, sizeof(t_coor));
//	curr = pt_1;
//	next = curr;
//	while (curr.x < pt_2.x)
//	{
//		slope = (float)(pt_2.y - pt_1.y) / (pt_2.x - pt_1.x);
//		curr.y = pt_1.y + (curr.x - pt_1.x) * slope;
//		next.x = curr.x + 1;
//		next.y = pt_1.y + (next.x - pt_1.x) * slope;
//		draw_line_segment(dt, curr, next, color);
//		++curr.x;
//	}
//}
