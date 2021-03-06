#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "timing.h"
#include "random.h"
#include "command.h"
#include "commandhandler.h"


struct gamestate {
    int running;
    int steptime;
    int paused;

    commandqueue_t *commands;
};


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

    newgame->commands = commandqueue_new();

    return newgame;
}

int gameloop (void) {
    int counter = 10;

    long start = millis();
    long now;

    while (game->running) {
        // process inputs
        // process commands

        commandqueue_process(game->commands, &game_commandhandler);

        // if the game is unpaused and enough time has passed
            // step the game state

        if (!game->paused) {
            now = millis();
            if (now - start >= game->steptime) {
                char str[256] = "mmmm";
                command_t *newcommand = command_new(CMD_DEBUG, str, sizeof(str));
                commandqueue_enqueue(game->commands, newcommand);
                start = now;

                if (!counter--) {
                    command_t *newcommand = command_new(CMD_DEBUG, "BYE!", 5);
                    commandqueue_enqueue(game->commands, newcommand);
                    commandqueue_makeinplace(game->commands, CMD_END_GAME, NULL, 0);
                }
            }
        } else {
            start = millis();
        }

        // render
    }

    return 0;
}

void freestate (void) {
    commandqueue_free(game->commands);
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
