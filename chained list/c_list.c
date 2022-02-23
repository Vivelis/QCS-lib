/*
** EPITECH PROJECT, 2021
** pile-file
** File description:
** c_list.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_list.h"
#include "my.h"

/* add a new element on the top of the list. */
int put_on_list(c_list_t *list, void *content)
{
    list_element_t *current = NULL;
    list_element_t *new = NULL;

    new = malloc(sizeof(element_t));
    if (list == NULL || new == NULL)
        return my_puterror("error:put_on: list or new is NULL", -1);
    new->content = content;
    new->next = NULL;
    if (list->first != NULL) {
        current = list->first;
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    } else
        list->first = new;
    return 0;
}

/* remove the last element of a list and return it's value. */
void *put_out_list(c_list_t *list)
{
    list_element_t *element = NULL;
    void *content = NULL;

    if (!list) {
        my_puterror("error:put_out: list is NULL", -1);
        return NULL;
    }
    if (list->first != NULL) {
        element = list->first;
        content = element->content;
        list->first = element->next;
        free(element);
    }
    return content;
}

/* allocate memory for a list and return a pointer to it. */
c_list_t *init_list(void)
{
    c_list_t *list = malloc(sizeof(list_t));

    if (list == NULL) {
        my_puterror("error:list: can't init list", -1);
        return NULL;
    }
    list->first = NULL;
    return list;
}

/* free alocated space for a list. */
void free_list(c_list_t *list)
{
    list_element_t *current = list->first;
    list_element_t *next = NULL;

    while (current->next != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
