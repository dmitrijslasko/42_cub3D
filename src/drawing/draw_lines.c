#include "cub3d.h"

void	draw_vert_line(t_data *data, t_coor pt_1, t_coor pt_2)
{
	int		curr_y;
	double	dist;

	if (pt_1.y > pt_2.y)
		swap(&pt_1, &pt_2, sizeof(t_coor));
	curr_y = pt_1.y;
	while (curr_y < pt_2.y)
	{
		dist = ((double)curr_y - pt_1.y) / (pt_2.y - pt_1.y);
		img_pix_put(data->img, pt_1.x, curr_y, RED);
		++curr_y;
	}
}

static void	draw_line(t_data *data, t_coor curr, t_coor next)
{
	if (abs(curr.y - next.y) >= 1)
		draw_vert_line(data, curr, next);
	else
		img_pix_put(data->img, curr.x, curr.y, RED);
}

void	draw_sloped_line(t_data *dt, t_coor pt_1, t_coor pt_2)
{
	double	slope;
	double	dist;
	t_coor	curr;
	t_coor	next;

	curr = pt_1;
	next = curr;
	while (curr.x < pt_2.x)
	{
		slope = (double)(pt_2.y - pt_1.y) / (pt_2.x - pt_1.x);
		curr.y = pt_1.y + (curr.x - pt_1.x) * slope;
		dist = ((double)curr.x - pt_1.x) / (pt_2.x - pt_1.x);
		next.x = curr.x + 1;
		next.y = pt_1.y + (next.x - pt_1.x) * slope;
		dist = ((double)next.x - curr.x) / (pt_2.x - curr.x);
		draw_line(dt, curr, next);
		++curr.x;
	}
}

