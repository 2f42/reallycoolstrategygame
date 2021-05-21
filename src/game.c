#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "timing.h"
#include "random.h"
#include "command.h"


static gamestate_t *game;


gamestate_t **getgamestate (void) {
    return &game;
}

gamestate_t *newstate (void) {
    gamestate_t *newgame = malloc(sizeof(gamestate_t));

    if (!newgame) {
        return 0;
    }

    newgame->running = 1;
    newgame->steptime = 1000; // once per second

    newgame->commands = newcommandqueue();

    return newgame;
}

static void printerlmao (command_t *command) {
    printf("%d\n", command->instr);

    if (command->instr == 0) {
        game->running = 0;
    }
}

int gameloop (void) {
    long start = millis();
    long now;

    while (game->running) {
        // process inputs
        // process commands

        processcommands(game->commands, &printerlmao);

        // if enough time has passed
            // step the game state

        now = millis();
        if (now - start >= game->steptime) {
            command_t *newcommand = makecommand((int) ranl() & 7);
            enqueuecommand(game->commands, newcommand);
            start = now;
        }

        // render
    }

    return 0;
}

void freestate (void) {
    freecommandqueue(game->commands);
    free(game);
}