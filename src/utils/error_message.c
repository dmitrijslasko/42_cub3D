#include "cub3d.h"

int	error_message(char *msg, int ret)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (ret);
}

int	error_message_close_fd(char *msg, int fd, int ret)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (fd > 0)
		close(fd);
	return (ret);
}

int	error_message2(char *msg, char*msg2, int ret)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_putstr_fd(msg2, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (ret);
}

int	free_array_return(char **array, int ret)
{
	int	i;

	i = 0;
	if (!array)
		return (ret);
	while (!array[i])
		free(array[i++]);
	free(array);
	return (ret);
}

int	error_message_free(char *msg, char **array, int ret)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (free_array_return(array, ret));
}
