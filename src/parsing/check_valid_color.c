#include "cub3d.h"

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
