/*
** EPITECH PROJECT, 2021
** stack
** File description:
** stack exemple
*/

#include <unistd.h>
#include "h_stack.h"

void insert(stack_t *stack, char str)
{
    element_t *new = malloc(sizeof(*new));

    if (stack == NULL || new == NULL) {
        exit(84);
    }
    new->str = str;
    new->next = stack->first;
    stack->first = new;
}

stack_t *initialisation(void)
{
    stack_t *stack = malloc(sizeof(*stack));
    element_t *element = malloc(sizeof(*element));

    if (stack == NULL || element == NULL) {
        exit(84);
    }
    element->str = NULL;
    element->next = NULL;
    stack->first = element;
    return stack;
}

void free_fct_array(stack_t *stack)
{
    element_t *last = stack->first;

    while (stack->first != NULL) {
        stack->first = last->next;
        free(last);
        last = stack->first;
    }
}
