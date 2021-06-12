#ifndef COMMAND_H_
#define COMMAND_H_

#include <stddef.h>

typedef struct command command_t;

typedef struct commandqueue commandqueue_t;

typedef void (*commandhandler)(command_t *);

commandqueue_t *commandqueue_new (void);
void commandqueue_clear (commandqueue_t *queue);
void commandqueue_free (commandqueue_t *queue);

command_t *command_new (int instr, void *data, size_t size);
void commandqueue_enqueue (commandqueue_t *queue, command_t *command);
void commandqueue_makeinplace (commandqueue_t *queue, int instr, void *data, size_t size);

int command_gettype (command_t *command);
void *command_getdata (command_t *command);

void commandqueue_process (commandqueue_t *queue, commandhandler handler);

#endif
