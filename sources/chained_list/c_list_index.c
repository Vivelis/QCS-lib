/*
** EPITECH PROJECT, 2021
** pile-file
** File description:
** c_list_index.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "c_list.h"
#include "qcs_utility.h"

/* allocate memory for an element and return it */
static list_element_t *allocate_elem(void *content)
{
    list_element_t *new = NULL;

    new = malloc(sizeof(list_element_t));
    if (new == NULL) {
        qcs_puterror("error:put_on: list or new is NULL", -1);
        return NULL;
    }
    new->content = content;
    new->next = NULL;
    return new;
}

/* add a new element at the given index to the list. */
int insert_listi(c_list_t *list, unsigned int index, void *content)
{
    list_element_t *current = NULL;

    if (list->first == NULL) {
        list->first = allocate_elem(content);
        return 0;
    }
    current = list->first;
    for (; index > 0; index--) {
        current = current->next;
        if (current->next == NULL && index == 1) {
            current->next = allocate_elem(content);
            list->len = list->len + 1;
            return 0;
        } else if (current->next == NULL && index == 1 ) {
            return qcs_puterror("insert_listi: index out of range.\n", 84);
        }
    }
    current->content = content;
    return 0;
}

/* remove the element at the given index of the list. */
int delete_listi(c_list_t *list, unsigned int index)
{
    list_element_t *current = NULL;

    if (list->first == NULL)
        return qcs_puterror("delete_listi: can't delete, list is empty.\n", 84);
    current = list->first;
    for (; index > 1; index--) {
        current = current->next;
        if (current->next == NULL) {
            return qcs_puterror("delete_listi: index out of range.\n", 84);
        }
    }
    if (current->next->next == NULL)
        current->next = NULL;
    else
        current->next = current->next->next;
    return 0;
}

/* return the element at the given index of the list */
void *get_listi(c_list_t *list, unsigned int index)
{
    list_element_t *current = NULL;

    if (list->first == NULL) {
        qcs_puterror("get_listi: can't access, list is empty.\n", 84);
        return NULL;
    }
    current = list->first;
    for (; index > 0; index--) {
        current = current->next;
        if (current->next == NULL) {
            qcs_puterror("get_listi: index out of range.\n", 84);
            return NULL;
        }
    }
    return current->next->content;
}
