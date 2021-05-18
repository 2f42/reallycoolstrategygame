#include <stdio.h>
#include <stdlib.h>

#include "time.h"
#include "random.h"
#include "gamestate.h"


#define SEED (0x0213de4208353f2eUL) // my lucky number


gamestate_t *newstate (void);
int gameloop (gamestate_t *game);
void cleanup (gamestate_t *game);

int main (int argc, char **argv) {
    random_seed(SEED);

    gamestate_t *game = newstate();
    if (!game) {
        return -1;
    }

    int gamefail = gameloop(game);
    cleanup(game);

    return gamefail;
}

gamestate_t *newstate (void) {
    gamestate_t *game = malloc(sizeof(gamestate_t));

    if (!game) {
        return 0;
    }

    game->running = 1;
    game->steptime = 1000; // once per second

    return game;
}

int gameloop (gamestate_t *game) {
    long start = millis();
    long now;

    while (game->running) {
        // process inputs
        // process commands

        // if enough time has passed
            // step the game state

        now = millis();
        if (now - start >= game->steptime) {
            printf("ayy lmao, %f\n", ranf());
            start = now;
        }

        // render
    }

    return 0;
}

void cleanup (gamestate_t *game) {
    free(game);
}
