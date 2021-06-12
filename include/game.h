#ifndef GAME_H_
#define GAME_H_

#include "command.h"


typedef struct gamestate gamestate_t;

gamestate_t **getgamestate (void);

gamestate_t *newstate (void);
int gameloop (void);
void freestate (void);


void game_stop (void);

void game_pause (void);
void game_unpause (void);

void game_setstep (int steptime);


#endif
