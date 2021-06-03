#ifndef COMMANDHANDLER_H_
#define COMMANDHANDLER_H_

#include "command.h"

typedef enum command_type {
	CMD_END_GAME,
	CMD_PAUSE_GAME, CMD_UNPAUSE_GAME,

	CMD_DEBUG,

	CMD_TOTAL
} command_type;


void game_commandhandler (command_t *command);


#endif
