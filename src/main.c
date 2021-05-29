#include <stdio.h>

#include "timing.h"
#include "random.h"
#include "game.h"
#include "command.h"


#define SEED (0x0213de4208353f2eULL) // my lucky number


int main (int argc, char **argv) {

    if (argc > 1) {
        printf("run with %d args:\n", argc-1);
        for (int i=1;i<argc;i++) {
            printf("\t%s\n", argv[i]);
        }
        printf("\n");
    }

    random_seed(SEED);

    gamestate_t **game;
    game = getgamestate();
    *game = newstate();
    if (!*game) {
        return -1;
    }

    int gamefail = gameloop();
    freestate();

    return gamefail;
}
