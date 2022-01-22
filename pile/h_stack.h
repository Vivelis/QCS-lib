/*
** EPITECH PROJECT, 2021
** stack
** File description:
** stack exemple
*/

#ifndef _H_STACK_H_
    #define _H_STACK_H_

typedef struct element_s element_t;
struct element_s {
    char *str;
    element_t *next;
};
typedef struct stack_s {
    element_t *first;
}stack_t;

// stack.c
void put_on(stack_t *stack, char *str);
stack_t *init_stack(void);
void free_stack(stack_t *stack);
#endif