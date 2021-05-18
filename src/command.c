#include "command.h"

#include <stdio.h>
#include <stdlib.h>

commandqueue_t *newcommandqueue (void) {
    commandqueue_t *queue = malloc(sizeof(commandqueue_t));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

static void _dequecommand (command_t *command) {

}

void clearcommandqueue (commandqueue_t *queue) {
    processcommands(queue, &_dequecommand);
}

void freecommandqueue (commandqueue_t *queue) {
    clearcommandqueue(queue);
    free(queue);
}


void enqueuecommand (commandqueue_t *queue, command_t *command) {
    command->next = NULL;
    if (queue->head) {
        queue->tail->next = command;
        queue->tail = command;
    } else {
        queue->head = command;
        queue->tail = command;
    }
}


void processcommands (commandqueue_t *queue, commandhandler handler) {
    while (queue->head != NULL) {
        handler(queue->head);
        command_t *old = queue->head;
        queue->head = old->next;
        free(old);
    }
    queue->head = NULL;
    queue->tail = NULL;
}
