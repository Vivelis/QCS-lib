/*
** EPITECH PROJECT, 2021
** stack
** File description:
** stack exemple
*/

#ifndef _H_STACK_H_
    #define _H_STACK_H_

typedef struct my_element_s my_element_t;
struct my_element_s {
    char *content;
    my_element_t *next;
};
typedef struct my_stack_s {
    my_element_t *first;
}my_stack_t;

// my_stack.c
void put_on_stack(my_stack_t *stack, char *content);
my_stack_t *init_stack(void);
void free_stack(my_stack_t *stack);
#endif