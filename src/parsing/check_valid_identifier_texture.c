#include "cub3d.h"

bool	is_valid_line_texture(char *line)
{
	line = remove_space_beginner(line);
	if (!ft_strncmp(line, "SO ", 3))
		return (1);
	else if (!ft_strncmp(line, "NO ", 3))
		return (1);
	else if (!ft_strncmp(line, "WE ", 3))
		return (1);
	else if (!ft_strncmp(line, "EA ", 3))
		return (1);
	else if (!ft_strncmp(line, "F ", 2))
		return (1);
	else if (!ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

bool	check_valid_identifier_texture(char *identifier)
{
	if (!ft_strncmp(identifier, "SO", ft_strlen(identifier)))
		return (1);
	else if (!ft_strncmp(identifier, "NO", ft_strlen(identifier)))
		return (1);
	else if (!ft_strncmp(identifier, "WE", ft_strlen(identifier)))
		return (1);
	else if (!ft_strncmp(identifier, "EA", ft_strlen(identifier)))
		return (1);
	else if (!ft_strncmp(identifier, "F", ft_strlen(identifier)))
		return (1);
	else if (!ft_strncmp(identifier, "C", ft_strlen(identifier)))
		return (1);
	return (0);
}

t_wall_type	check_valid_identifier_texture_wall(char *identifier)
{
	if (!ft_strncmp(identifier, "SO", ft_strlen(identifier)))
		return (SOUTH);
	else if (!ft_strncmp(identifier, "NO", ft_strlen(identifier)))
		return (NORTH);
	else if (!ft_strncmp(identifier, "WE", ft_strlen(identifier)))
		return (WEST);
	else if (!ft_strncmp(identifier, "EA", ft_strlen(identifier)))
		return (EAST);
	else if (!ft_strncmp(identifier, "F", ft_strlen(identifier)))
		return (FLOOR);
	else if (!ft_strncmp(identifier, "C", ft_strlen(identifier)))
		return (CEILING);
	else
		return (DEFAULT);
}
