#include <time.h>
#include <stdio.h>

int main() {
    struct timespec ts = {0, 500000000}; // 0.5 seconds
    nanosleep(&ts, NULL);
    printf("Slept 0.5s\n");
    return 0;
}
