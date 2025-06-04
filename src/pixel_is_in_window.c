#include "cub3d.h"

int	pixel_is_in_window(int x, int y)
{
	if (x >= 0 && x < WINDOW_W && y >= 0 && y < WINDOW_H)
		return (1);
	return (0);
}
