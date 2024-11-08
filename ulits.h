#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <time.h>

#define PROCESS_LIMIT 18

static inline int generate_random_interval(int upper_bound) {
    return rand() % upper_bound;
}

#endif
