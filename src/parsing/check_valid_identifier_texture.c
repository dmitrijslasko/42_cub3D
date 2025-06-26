#include "cub3d.h"

typedef struct s_texture_match
{
	const char				*str_with_space;
	const char				*str;
	const size_t			length;
	const int				wall_type;
}							t_texture_match;

static const t_texture_match g_textures_lookup[] = {
{"SO ", "SO", 3, SOUTH},
{"NO ", "NO", 3, NORTH},
{"WE ", "WE", 3, WEST},
{"EA ", "EA", 3, EAST},
{"F ", "F", 2, FLOOR},
{"C ", "C", 2, CEILING},
{"D ", "D", 2, DOOR},
{NULL, NULL, -1, -1}
};

bool	is_valid_line_texture(char *line)
{
	size_t i;

	i = 0;
	while (line[i] && ft_strchr(WHITE_SPACE, line[i]))
		i++;
	while (g_textures_lookup[i].str_with_space)
	{
		if (!ft_strncmp(line, g_textures_lookup[i].str_with_space, g_textures_lookup[i].length))
			return (1);
		i++;
	}
	return (0);
}



t_wall_type	check_valid_identifier_texture_wall(char *identifier)
{
	size_t	i;

 	i = 0;
	while (g_textures_lookup[i].str_with_space)
	{
		if (!ft_strncmp(identifier, g_textures_lookup[i].str, ft_strlen(identifier)))
			return (g_textures_lookup[i].wall_type);
		i++;
	}
	return (DEFAULT_WALL);
}
