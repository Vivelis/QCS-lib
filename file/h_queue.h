/*
** EPITECH PROJECT, 2021
** h_queue
** File description:
** header for queue
*/

typedef struct element_s element_t;
struct element_s {
    char str;
    element_t *next;
};
typedef struct queue_s {
    element_t *first;
}queue_t;
