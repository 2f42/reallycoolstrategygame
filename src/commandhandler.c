#include <stdio.h>

#include "commandhandler.h"
#include "game.h"



void game_commandhandler (command_t *command) {

	/*
	PREPARE FOR A THICC SWITCH STATEMENT
	*/

	switch (command->instr) {
		case CMD_END_GAME:
			game_stop();
			return;
		case CMD_PAUSE_GAME:
			game_pause();
			return;
		case CMD_UNPAUSE_GAME:
			game_unpause();
			return;
		case CMD_DEBUG:
			printf("%s\n", (char *)command->data);
		default:
			return;
	}

}
