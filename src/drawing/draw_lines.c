#include "cub3d.h"

void	draw_vertical_line(t_data *dt, t_coor pt_1, t_coor pt_2, int color)
{
	int		curr_y;

	if (pt_1.y > pt_2.y)
		swap(&pt_1, &pt_2, sizeof(t_coor));
	curr_y = pt_1.y;
	while (curr_y < pt_2.y)
	{
		img_pix_put(dt->img, pt_1.x, curr_y, color);
		++curr_y;
	}
}

static void	draw_line_segment(t_data *dt, t_coor curr, t_coor next, int color)
{
	if (abs(curr.y - next.y) >= 1)
	{
		draw_vertical_line(dt, curr, next, color);
	}
	else
	{
		img_pix_put(dt->img, curr.x, curr.y, color);
	}
}

void	draw_line(t_data *dt, t_coor pt_1, t_coor pt_2, int color)
{
	double	slope;
	t_coor	curr;
	t_coor	next;

	if (pt_1.x == pt_2.x)
		draw_vertical_line(dt, pt_1, pt_2, color);
	if (pt_1.x > pt_2.x)
		swap(&pt_1, &pt_2, sizeof(t_coor));
	curr = pt_1;
	next = curr;
	while (curr.x < pt_2.x)
	{
		slope = (double)(pt_2.y - pt_1.y) / (pt_2.x - pt_1.x);
		curr.y = pt_1.y + (curr.x - pt_1.x) * slope;
		next.x = curr.x + 1;
		next.y = pt_1.y + (next.x - pt_1.x) * slope;
		draw_line_segment(dt, curr, next, color);
		++curr.x;
	}
}


