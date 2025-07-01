#include "cub3d.h"

bool	check_color(char *one_color)
{
	long	r;

	if (!check_only_number(one_color))
		return (error_msg("Color indefined", 0));
	r = ft_atoi(one_color);
	if (r > 255)
		return (error_msg("Color indefined", 0));
	return (1);
}
