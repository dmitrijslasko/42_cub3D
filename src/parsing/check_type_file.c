#include "cub3d.h"

bool	check_type_file(char *file, char *type)
{
	size_t	len_file;
	size_t	len_type;

	len_file = ft_strlen(file);
	len_type = ft_strlen(type);
	if (len_file < len_type || \
		ft_strncmp(file + len_file - len_type, type, len_type))
		return (error_msg("Error type file.", 0));
	return (1);
}
