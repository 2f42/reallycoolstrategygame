#include "command.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct command {
    int instr;
    void *data;
    struct command *next;
};

struct commandqueue {
    command_t *head;
    command_t *tail;
};

commandqueue_t *commandqueue_new (void) {
    commandqueue_t *queue = malloc(sizeof(commandqueue_t));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

static void _dequecommand (__attribute__((unused)) command_t *command) {

}

void commandqueue_clear (commandqueue_t *queue) {
    commandqueue_process(queue, &_dequecommand);
}

void commandqueue_free (commandqueue_t *queue) {
    commandqueue_clear(queue);
    free(queue);
}


command_t *command_new (int instr, void *data, size_t size) {
    command_t *newcommand = malloc(sizeof(command_t));
    newcommand->instr = instr;
    if (data) {
        newcommand->data = malloc(size);
        memcpy(newcommand->data, data, size);
    }
    return newcommand;
}

void commandqueue_enqueue (commandqueue_t *queue, command_t *command) {
    command->next = NULL;
    if (queue->head) {
        queue->tail->next = command;
    } else {
        queue->head = command;
    }
    queue->tail = command;
}

void commandqueue_makeinplace (commandqueue_t *queue, int instr, void *data, size_t size) {
    command_t *newcommand = command_new(instr, data, size);
    commandqueue_enqueue(queue, newcommand);
}


int command_gettype (command_t *command) {
    return command->instr;
}

void *command_getdata (command_t *command) {
    return command->data;
}


void commandqueue_process (commandqueue_t *queue, commandhandler handler) {
    while (queue->head != NULL) {
        handler(queue->head);
        command_t *old = queue->head;
        queue->head = old->next;
        if (old->data) {
            free(old->data);
        }
        free(old);
    }
    queue->head = NULL;
    queue->tail = NULL;
}
