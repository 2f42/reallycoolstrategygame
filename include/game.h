#ifndef __GAME_H_
#define __GAME_H_

#include "command.h"

typedef struct gamestate {
    int running;
    int steptime;

    commandqueue_t *commands;
} gamestate_t;

gamestate_t **getgamestate (void);

gamestate_t *newstate (void);
int gameloop (void);
void freestate (void);

#endif
