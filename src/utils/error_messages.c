#include "cub3d.h"

int	free_array_return(char **array, int ret)
{
	free_array(array);
	return (ret);
}

int	error_free_char_return(char *msg, char *str, int ret)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	free(str);
	return (ret);
}

int	error_message_free(char *msg, char **array, int ret)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (free_array_return(array, ret));
}
