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
	int sleep_time;

	sleep_time = 1e9 / FPS;
    struct timespec ts = {0, sleep_time};
    nanosleep(&ts, NULL);
    return (0);
}
