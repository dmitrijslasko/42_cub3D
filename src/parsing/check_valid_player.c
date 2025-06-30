#include "cub3d.h"

bool	check_valid_player(t_map *map)
{
	int		count;

	count = count_elements_in_the_map(map, "NSWE");
	if (count == 0)
		return (error_message("Error: Player not found.", 0));
	else if (count > 1)
		return (error_message("Error: Multi player.", 0));
	return (1);
}
