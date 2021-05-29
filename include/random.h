#ifndef __RANDOM_H_
#define __RANDOM_H_

#include <stdint.h>

void random_seed (uint64_t seed);
uint64_t ranl (void);
double ranf (void);

#endif
