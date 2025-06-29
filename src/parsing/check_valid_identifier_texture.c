#include "cub3d.h"

typedef struct s_texture_match
{
	const char				*str_with_space;
	const char				*str;
	const size_t			length;
	const int				wall_type;
}							t_texture_match;

static const t_texture_match g_textures_lookup[] = {
{"SO ", "SO", 2, SOUTH},
{"NO ", "NO", 2, NORTH},
{"WE ", "WE", 2, WEST},
{"EA ", "EA", 2, EAST},
{"F ", "F", 1, FLOOR},
{"C ", "C", 1, CEILING},
{"D ", "D", 1, DOOR},
{NULL, NULL, -1, -1}
};

bool	is_valid_line_texture(char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[j] && ft_strchr(WHITE_SPACE, line[j]))
		j++;
	while (g_textures_lookup[i].str)
	{
		if (!ft_strncmp(&line[j], g_textures_lookup[i].str, g_textures_lookup[i].length) && ft_strchr(WHITE_SPACE, line[j + g_textures_lookup[i].length]))
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
