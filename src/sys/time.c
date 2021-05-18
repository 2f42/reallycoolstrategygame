#include "sys/time.h"

#ifdef __linux__

#include <time.h>

long millis (void) {
    struct timespec timer;
    clock_gettime(CLOCK_MONOTONIC, &timer);
    return timer.tv_sec * 1000 + timer.tv_nsec / 1000000;
}

#endif
