/*
** EPITECH PROJECT, 2021
** stack
** File description:
** stack exemple
*/

#include <unistd.h>
#include <stdlib.h>
#include "../h_stack.h"
#include "lib/headers/my.h"

void put_on(stack_t *stack, char *str)
{
    element_t *new = malloc(sizeof(element_t));

    if (stack == NULL || new == NULL) {
        my_puterror("error:put_on: stack or new is NULL", -1);
    }
    new->str = str;
    new->next = stack->first;
    stack->first = new;
}

stack_t *init_stack(void)
{
    stack_t *stack = malloc(sizeof(stack_t));
    element_t *element = malloc(sizeof(*element));

    if (stack == NULL || element == NULL) {
        my_puterror("error:init_stack: can't init stack", -1);
        return NULL;
    }
    element->str = NULL;
    element->next = NULL;
    stack->first = element;
    return stack;
}

void free_stack(stack_t *stack)
{
    element_t *last = stack->first;

    while (stack->first != NULL) {
        stack->first = last->next;
        free(last);
        last = stack->first;
    }
}
