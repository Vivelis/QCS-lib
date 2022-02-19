/*
** EPITECH PROJECT, 2021
** my_stack
** File description:
** stack exemple
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_stack.h"
#include "my.h"

void put_on_stack(my_stack_t *stack, char *content)
{
    my_element_t *new = malloc(sizeof(*new));

    if (stack == NULL || new == NULL) {
        my_puterror("error:put_on: stack or new is NULL", -1);
    }
    new->content = content;
    new->next = stack->first;
    stack->first = new;
}

my_stack_t *init_stack(void)
{
    my_stack_t *stack = malloc(sizeof(*stack));
    my_element_t *element = malloc(sizeof(*element));

    if (stack == NULL || element == NULL) {
        my_puterror("error:init_stack: can't init stack", -1);
        return NULL;
    }
    element->content = NULL;
    element->next = NULL;
    stack->first = element;
    return stack;
}

void free_stack(my_stack_t *stack)
{
    my_element_t *last = stack->first;

    while (stack->first != NULL) {
        stack->first = last->next;
        free(last);
        last = stack->first;
    }
}
