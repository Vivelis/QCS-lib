/*
** EPITECH PROJECT, 2021
** my_queue
** File description:
** queue exemple
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_queue.h"
#include "my.h"

int put_on_queue(my_queue_t *queue, void *content)
{
    my_element_t *current = NULL;
    my_element_t *new = NULL;

    new = malloc(sizeof(element_t));
    if (queue == NULL || new == NULL)
        return my_puterror("error:put_on: queue or new is NULL", -1);
    new->content = content;
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

char *put_out_queue(my_queue_t *queue)
{
    my_element_t *element = NULL;
    char *content = NULL;

    if (!queue) {
        my_puterror("error:put_out: queue is NULL", -1);
        return NULL;
    }
    if (queue->first != NULL) {
        element = queue->first;
        content = element->content;
        queue->first = element->next;
        free(element);
    }
    return content;
}

my_queue_t *init_queue(void)
{
    my_queue_t *queue = malloc(sizeof(queue_t));

    if (queue == NULL) {
        my_puterror("error:queue: can't init queue", -1);
        return NULL;
    }
    queue->first = NULL;
    return queue;
}

void free_queue(my_queue_t *queue)
{
    my_element_t *current = queue->first;
    my_element_t *next = NULL;

    while (current->next != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
