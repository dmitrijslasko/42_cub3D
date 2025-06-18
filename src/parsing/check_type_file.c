#include "cub3d.h"

bool	check_type_file(char *file, char *type)
{
	char	**array;

	array = ft_split(file, '.');
	if (!array || !array[0] || !array[1] || array[2])
		return (error_message_free("Error  type file.", array, 0));
	if (ft_strncmp(array[1], type, ft_strlen(array[1])))
		return (error_message_free("Error  type file.", array, 0));
	return (free_array_return(array, 1));
}
