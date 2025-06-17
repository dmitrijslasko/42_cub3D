#include "cub3d.h"

void	print_separator_default(void)
{
	int		i;
	size_t	j;

	j = 0;
	while (j < DEF_SEPARATOR_COUNT)
	{
		i = 0;
		while (i++ < DEF_SEPARATOR_WIDTH)
			ft_putstr_fd(DEF_SEPARATOR_CHAR, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		j++;
	}
}


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
