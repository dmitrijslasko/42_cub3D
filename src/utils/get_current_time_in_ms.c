#include "cub3d.h"

long	get_current_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

// #define _POSIX_C_SOURCE 200112L
#include <unistd.h>
#include <time.h>

int my_sleep(void) 
{
    struct timespec ts = {0, 20000000}; // 0.5 seconds
    nanosleep(&ts, NULL);
    // printf("Slept 0.5s\n");
    return 0;
}