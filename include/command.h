#ifndef COMMAND_H_
#define COMMAND_H_

#include <stddef.h>

typedef struct command command_t;

typedef struct commandqueue commandqueue_t;

typedef void (*commandhandler)(command_t *);

commandqueue_t *newcommandqueue (void);
void clearcommandqueue (commandqueue_t *queue);
void freecommandqueue (commandqueue_t *queue);

command_t *makecommand (int instr, void *data, size_t size);
void enqueuecommand (commandqueue_t *queue, command_t *command);
void makecommandinplace (commandqueue_t *queue, int instr, void *data, size_t size);

int getcommandtype (command_t *command);
void *getcommanddata (command_t *command);

void processcommands (commandqueue_t *queue, commandhandler handler);

#endif
