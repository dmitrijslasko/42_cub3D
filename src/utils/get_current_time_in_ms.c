#include "cub3d.h"

long	get_current_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

#define _POSIX_C_SOURCE 200112L
#include <time.h>
#include <unistd.h>

int my_sleep(void)
{
    struct timespec ts = {0, 16666666}; // ~30 FPS (33.3ms)
    nanosleep(&ts, NULL);
    return 0;
}
