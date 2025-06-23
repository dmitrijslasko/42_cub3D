#include "cub3d.h"

char	*remove_space_beginner(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (str);
	while (ft_strchr(WHITE_SPACE, str[i]))
		i++;
	return (&str[i]);
}
