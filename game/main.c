#include <stdio.h>
#include <stdlib.h>

#include "gamestate.h"

int initialise (gamestate_t *game);
int gameloop (gamestate_t *game);
void cleanup (gamestate_t *game);

int main (int argc, char **argv) {
    gamestate_t game;

    int initfail = initialise(&game);
    if (initfail) {
        return initfail;
    }

    int gamefail = gameloop(&game);
    cleanup(&game);

    return gamefail;
}

int initialise (gamestate_t *game) {
    game = malloc(sizeof(gamestate_t));

    if (!game) {
        return 1;
    }

    game->running = 1;
    game->steptime = 1000; // once per second

    return 0;
}

int gameloop (gamestate_t *game) {
    while (game->running) {
        // process inputs
        // process commands

        // if enough time has passed
            // step the game state

        // render
    }

    return 0;
}

void cleanup (gamestate_t *game) {
    free(game);
}
