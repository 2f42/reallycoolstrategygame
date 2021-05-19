#include <stdio.h>
#include <stdlib.h>

#include "timing.h"
#include "random.h"
#include "gamestate.h"
#include "command.h"


#define SEED (0x0213de4208353f2eUL) // my lucky number


gamestate_t *newstate (void);
int gameloop ();
void cleanup ();


static gamestate_t *game;


int main (int argc, char **argv) {
    random_seed(SEED);

    game = newstate();
    if (!game) {
        return -1;
    }

    int gamefail = gameloop(game);
    cleanup(game);

    return gamefail;
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

int gameloop () {
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

void cleanup () {
    freecommandqueue(game->commands);
    free(game);
}
