#include "cub3d.h"

void	print_separator(size_t count, char *c)
{
	int		i;
	size_t	j;

	j = 0;
	while (j < count)
	{
		i = 0;
		while (i++ < DEF_SEPARATOR_WIDTH)
			ft_putstr_fd(c, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		j++;
	}
}
