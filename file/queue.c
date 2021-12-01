/*
** EPITECH PROJECT, 2021
** queue
** File description:
** queue exemple
*/

#include <unistd.h>
#include "h_queue.h"

void put_on(queue_t *queue, char str)
{
    element_t *current = NULL;
    element_t *new = NULL;

    new = malloc(sizeof(*new));
    if (queue == NULL || new == NULL) {
        exit(84);
    }
    new->str = str;
    new->next = NULL;
    if (queue->first != NULL) {
        current = queue->first;
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    } else
        queue->first = new;
}

char *put_out(queue_t *queue)
{
    element_t *element = NULL;
    char *content = NULL;

    if (!queue)
        exit(84);
    if (queue->first != NULL) {
        element = queue->first;
        content = element->str;
        queue->first = element->next;
        free(element);
    }
    return content;
}

queue_t *initialisation(void)
{
    queue_t *queue = malloc(sizeof(*queue));
    element_t *element = malloc(sizeof(*element));

    if (queue == NULL || element == NULL) {
        exit(84);
    }
    element->str = NULL;
    element->next = NULL;
    queue->first = element;
    return queue;
}

void free_fct_array(queue_t *queue)
{
    element_t *last = queue->first;

    while (queue->first != NULL) {
        queue->first = last->next;
        free(last);
        last = queue->first;
    }
}
