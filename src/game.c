#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "timing.h"
#include "random.h"
#include "command.h"
#include "commandhandler.h"


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
    newgame->paused = 0;

    newgame->commands = newcommandqueue();

    return newgame;
}

int gameloop (void) {
    long start = millis();
    long now;

    while (game->running) {
        // process inputs
        // process commands

        processcommands(game->commands, &game_commandhandler);

        // if the game is unpaused and enough time has passed
            // step the game state

        if (!game->paused) {
            now = millis();
            if (now - start >= game->steptime) {
                command_t *newcommand = makecommand((int) ranl() & 7, NULL);
                enqueuecommand(game->commands, newcommand);
                start = now;
            }
        } else {
            start = millis();
        }

        // render
    }

    return 0;
}

void freestate (void) {
    freecommandqueue(game->commands);
    free(game);
}


void game_stop (void) {
    game->running = 0;
}

void game_pause (void) {
    game->paused = 1;
}

void game_unpause (void) {
    game->paused = 0;
}

void game_setstep (int steptime) {
    game->steptime = steptime;
}
