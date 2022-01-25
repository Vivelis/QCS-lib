/*
** EPITECH PROJECT, 2021
** queue
** File description:
** queue exemple
*/

#include <unistd.h>
#include <stdlib.h>
#include "../h_queue.h"
#include "lib/headers/my.h"

int put_on(queue_t *queue, char *str)
{
    element_t *current = NULL;
    element_t *new = NULL;

    new = malloc(sizeof(element_t));
    if (queue == NULL || new == NULL)
        return my_puterror("error:put_on: queue or new is NULL", -1);
    new->str = str;
    new->next = NULL;
    if (queue->first != NULL) {
        current = queue->first;
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    } else
        queue->first = new;
    return 0;
}

char *put_out(queue_t *queue)
{
    element_t *element = NULL;
    char *content = NULL;

    if (!queue) {
        my_puterror("error:put_out: queue is NULL", -1);
        return NULL;
    }
    if (queue->first != NULL) {
        element = queue->first;
        content = element->str;
        queue->first = element->next;
        free(element);
    }
    return content;
}

queue_t *init_queue(void)
{
    queue_t *queue = malloc(sizeof(queue_t));

    if (queue == NULL) {
        my_puterror("error:queue: can't init queue", -1);
        return NULL;
    }
    queue->first = NULL;
    return queue;
}

void free_queue(queue_t *queue)
{
    element_t *current = queue->first;
    element_t *next = NULL;

    while (current->next != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
