#include "sys/time.h"

#include <sys/timeb.h>

long millis (void) {
    struct timeb timer;
    ftime(&timer);
    return timer.time * 1000 + timer.millitm;
}
