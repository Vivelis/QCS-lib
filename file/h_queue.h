/*
** EPITECH PROJECT, 2021
** h_queue
** File description:
** header for queue
*/

#ifndef _H_QUEUE_H_
    #define _H_QUEUE_H_

typedef struct element_s element_t;
struct element_s {
    char *str;
    element_t *next;
};
typedef struct queue_s {
    element_t *first;
}queue_t;

// queue.c
int put_on(queue_t *queue, char *str);
char *put_out(queue_t *queue);
queue_t *init_queue(void);
void free_queue(queue_t *queue);
#endif
