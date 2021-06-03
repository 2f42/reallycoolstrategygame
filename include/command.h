#ifndef COMMAND_H_
#define COMMAND_H_

typedef struct command {
    int instr;
    void *data;
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

command_t *makecommand (int instr, void *data, size_t size);
void enqueuecommand (commandqueue_t *queue, command_t *command);
void makecommandinplace (commandqueue_t *queue, int instr, void *data, size_t size);

void processcommands (commandqueue_t *queue, commandhandler handler);

#endif
