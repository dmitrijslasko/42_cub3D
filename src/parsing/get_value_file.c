/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:06:49 by fvargas           #+#    #+#             */
/*   Updated: 2025/07/02 00:06:50 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	get_value_textures(t_map *map, int fd, char **str)
{
	char	**array;
	char	*line;

	line = *str;
	while (line && (is_empty_line(line) || is_valid_line_texture(line)))
	{
		if (is_valid_line_texture(line))
		{
			array = ft_split_special(line, WHITE_SPACE);
			if (set_color_or_texture(map, array[0], &array[1]))
			{
				free_line_get_next(line, -1);
				return (free_array_return(array, 1));
			}
			free_array(array);
		}
		line = free_line_get_next(line, fd);
	}
	*str = line;
	return (0);
}

bool	get_value_file1(t_map *map, int fd)
{
	char	*line;
	bool	ret;

	line = free_line_get_next(NULL, fd);
	ret = get_value_textures(map, fd, &line);
	if (ret == Success)
		get_value_map(line, fd, map);
	return (ret);
}

bool	get_value_file(t_map *map, char *file)
{
	int	fd;
	int	ret;

	fd = ft_open(file);
	if (fd < 0)
		return (1);
	ret = get_value_file1(map, fd);
	close (fd);
	return (ret);
}
