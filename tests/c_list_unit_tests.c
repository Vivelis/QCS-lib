/*
** EPITECH PROJECT, 2021
** pile-file
** File description:
** c_list_unit_tests.c
*/

#include <criterion/criterion.h>
#include "c_list.h"

Test(c_listi, initialise)
{
    c_list_t *list = NULL;

    list = init_list();
    cr_assert_neq(list, NULL);
    free_list(list);
}
