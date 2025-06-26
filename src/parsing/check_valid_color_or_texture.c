#include "cub3d.h"

bool	check_color(char *one_color)
{
	long	r;

	if (!check_only_number(one_color))
		return (error_message("Color indefined", 0));
	r = ft_atoi(one_color);
	if (r > 255)
		return (error_message("Color indefined", 0));
	return (1);
}

bool	check_valid_color(char **color)
{
	char	**array;
	int		count;
	size_t	i;
	size_t	j;

	i = 0;
	count = 0;
	while (color[i])
	{
		j = 0;
		array = ft_split(color[i++], ',');
		while (array[j])
		{
			if (!check_color(array[j++]))
				return (free_array_return(array, 0));
			count++;
		}
		free_array(array);
	}
	if (count != 3)
		return (error_message("Color indefined", 0));
	return (1);
}

bool	check_valid_color_or_texture(char **info)
{
	int	fd_texture_file;

	// if (!check_valid_identifier_texture(info[0]))
	// 	return (error_message2("Error on identifier ", info[0], 0));
	fd_texture_file = open(info[1], O_RDONLY);
	if (fd_texture_file < 0)
	{
		if (!check_valid_color(&info[1]))
			return (error_message2("Error: invalid color or file for ", \
									info[0], 0));
		return (1);
	}
	close(fd_texture_file);
	if (info[2])
		return (error_message2("Error: invalid file for ", info[0], 0));
	return (1);
}
