#ifndef __COMMAND_H_
#define __COMMAND_H_

typedef struct command {
    int instr;
    struct command *next;
} command_t;

typedef struct commandqueue {
    command_t *head;
    command_t *tail;
} commandqueue_t;

typedef void (*commandhandler)(command_t *);

commandqueue_t *newcommandqueue (void);
void clearcommandqueue (commandqueue_t *queue);
void freecommandqueue (commandqueue_t *queue);

void enqueuecommand (commandqueue_t *queue, command_t *command);

void processcommands (commandqueue_t *queue, commandhandler handler);

#endif
