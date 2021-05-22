#ifndef __COMMANDHANDLER_H_
#define __COMMANDHANDLER_H_

#include "command.h"

typedef enum command_type {
	CMD_END_GAME,
	CMD_PAUSE_GAME,

	CMD_TOTAL
} command_type;


void game_commandhandler (command_t *command);


#endif