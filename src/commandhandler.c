#include <stdio.h>

#include "commandhandler.h"
#include "game.h"

void game_commandhandler (command_t *command) {  
	printf("%d\n", command->instr);

	switch (command->instr) {
		case CMD_END_GAME:
			(*getgamestate())->running = 0;
			return;
		default:
			return;
	}
}