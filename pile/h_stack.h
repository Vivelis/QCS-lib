/*
** EPITECH PROJECT, 2021
** stack
** File description:
** stack exemple
*/

typedef struct element_s element_t;
struct element_s {
    char str;
    element_t *next;
};
typedef struct stack_s {
    element_t *first;
}stack_t;