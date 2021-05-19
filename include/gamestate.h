#ifndef __GAMESTATE_H_
#define __GAMESTATE_H_

#include "command.h"

typedef struct gamestate {
    int running;
    int steptime;

    commandqueue_t *commands;
} gamestate_t;

gamestate_t *getgamestate (void);

#endif
