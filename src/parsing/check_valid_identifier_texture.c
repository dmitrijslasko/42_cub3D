#include "cub3d.h"

bool	is_valid_line_texture(char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[j] && ft_strchr(WHITE_SPACE, line[j]))
		j++;
	while (g_txt_lookup[i].str)
	{
		if (!ft_strncmp(&line[j], g_txt_lookup[i].str, g_txt_lookup[i].length) \
			&& ft_strchr(WHITE_SPACE, line[j + g_txt_lookup[i].length]))
			return (1);
		i++;
	}
	return (0);
}

t_wall_type	check_valid_identifier_texture_wall(char *identifier)
{
	size_t	i;

	i = 0;
	while (g_txt_lookup[i].str)
	{
		if (!ft_strncmp(identifier, g_txt_lookup[i].str, ft_strlen(identifier)))
			return (g_txt_lookup[i].wall_type);
		i++;
	}
	return (DEFAULT_WALL);
}
