#include "timing.h"
#include "random.h"
#include "game.h"
#include "command.h"


#define SEED (0x0213de4208353f2eUL) // my lucky number


int main (int argc, char **argv) {
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
