#include "command.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

commandqueue_t *newcommandqueue (void) {
    commandqueue_t *queue = malloc(sizeof(commandqueue_t));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

static void _dequecommand (__attribute__((unused)) command_t *command) {

}

void clearcommandqueue (commandqueue_t *queue) {
    processcommands(queue, &_dequecommand);
}

void freecommandqueue (commandqueue_t *queue) {
    clearcommandqueue(queue);
    free(queue);
}


command_t *makecommand (int instr, void *data, size_t size) {
    command_t *newcommand = malloc(sizeof(command_t));
    newcommand->instr = instr;
    if (data) {
        newcommand->data = malloc(size);
        memcpy(newcommand->data, data, size);
    }
    return newcommand;
}

void enqueuecommand (commandqueue_t *queue, command_t *command) {
    command->next = NULL;
    if (queue->head) {
        queue->tail->next = command;
    } else {
        queue->head = command;
    }
    queue->tail = command;
}

void makecommandinplace (commandqueue_t *queue, int instr, void *data, size_t size) {
    command_t *newcommand = makecommand(instr, data, size);
    enqueuecommand(queue, newcommand);
}


void processcommands (commandqueue_t *queue, commandhandler handler) {
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
