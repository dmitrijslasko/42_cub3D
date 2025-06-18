#include "cub3d.h"

bool	check_valid_color(char *color)
{
	char	**array;
	long	r;
	long	g;
	long	b;

	array = ft_split(color, ',');
	if (!array || !array[0] || !array[1] || !array[2] || array[3])
		return (free_array_return(array, 0));
	if (!check_only_number(array[0]) || !check_only_number(array[1]) \
									|| !check_only_number(array[2]))
		return (error_message_free("Color indefined", array, 0));
	r = ft_atoi(array[0]);
	g = ft_atoi(array[1]);
	b = ft_atoi(array[2]);
	if (r > 255 || g > 255 || b > 255)
		return (error_message_free("Color indefined", array, 0));
	return (free_array_return(array, 1));
}

bool	check_valid_color_or_texture(char **info)
{
	int	fd_texture_file;

	if (!check_valid_identifier_texture(info[0]))
		return (error_message2("Error on identifier ", info[0], 0));
	// remove_new_line(info[1]);
	fd_texture_file = open(info[1], O_RDONLY);
	if (fd_texture_file < 0)
	{
		if (!check_valid_color(info[1]))
			return (error_message2("Error: invalid color or file for ", info[0], 0));
	}
	close(fd_texture_file);
	return (1);
}
