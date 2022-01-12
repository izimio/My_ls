/*
** EPITECH PROJECT, 2021
** tests
** File description:
** test_my_project.c
*/

#include "../include/my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int wesh(char c, char *charset)
{
    int i = -1;

    while (charset[++i])
        if (charset[i] == c)
            return (1);
    return (0);
}

static int wcount(char *str, char *charset)
{
    int i = 0;
    int count = 0;

    while (str[i]) {
        while (str[i] && wesh(str[i], charset))
            i++;
        if (str[i] && !wesh(str[i], charset))
            count++;
        while (str[i] && !wesh(str[i], charset))
            i++;
    }
    return (count);
}

static char *wmalloc(char *str, char *charset)
{
    char *toa;
    int i = 0;

    while (str[i] && !wesh(str[i], charset))
        i++;
    toa = malloc(sizeof(char) * i + 1);
    i = -1;
    while (str[++i] && !wesh(str[i], charset))
        toa[i] = str[i];
    toa[i] = '\0';
    return (toa);
}

char **my_split(char *str, char *charset)
{
    int i = 0;
    int j = 0;
    char **arr;

    arr = malloc(sizeof(char *) * (wcount(str, charset) + 1));
    while (str[i]) {
        while (str[i] && wesh(str[i], charset))
            i++;
        if (str[i] && !wesh(str[i], charset))
            arr[j++] = wmalloc(&str[i], charset);
        while (str[i] && !wesh(str[i], charset))
            i++;
    }
    arr[j] = 0;
    return (arr);
}

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_ls_main, youhou, .init = redirect_all_std)
{
    char *av[2];
    av[0] = my_strdup(".");
    av[1] = 0;
    my_ls_main(av);
    cr_assert_stdout_neq_str("adadadaaadadasda");
}

Test(my_advanced_strcat, check_puchar, .init = redirect_all_std)
{
    cr_assert_str_eq("o/oui", my_advanced_strcat("o", "oui"));
}

Test(print_type, checkmain, .init = redirect_all_std)
{
    struct stat t_s;
    stat("oui", &t_s);
    print_type(t_s);

    cr_assert_stdout_neq_str("");
}

Test(print_flag_l_folder, checkmain, .init = redirect_all_std)
{
    t_render *tmp = init_render();
    t_folder *res = malloc(sizeof(t_folder));
    struct stat t_s;

    stat("oui", &t_s);
    res->path = my_strdup("tests/oui");
    res->next = NULL;
    res->stat = t_s;
    tmp->name = res;
    print_flag_l_folder(tmp, res);

    cr_assert_stdout_neq_str(
    "-rw-r--r--. 1 joshua joshua 0 Nov 27 12:12 tests/oui");
}

Test(get_folder_info, wooo, .init = redirect_all_std)
{
    t_render *tmp = init_render();
    t_folder *res = malloc(sizeof(t_folder));
    t_arg *ouais = NULL;
    struct stat t_s;

    stat("oui", &t_s);
    res->path = my_strdup("tests/.oui");
    res->next = NULL;
    res->stat = t_s;
    tmp->name = res;
    get_folder_info(res->path, &ouais, tmp);
}

Test(my_sort_list_alpha_arg, wooo, .init = redirect_all_std)
{
    struct stat t;
    stat("Makefile", &t);
    t_arg *oui = my_create_elem_arg(NULL, t, ".");
    my_sort_list_alpha_arg(&oui, 1);
}

Test(my_rev_list_arg, wooo, .init = redirect_all_std)
{
    struct stat t;
    stat("Makefile", &t);
    t_arg *oui = my_create_elem_arg(NULL, t, ".");
    my_rev_list_arg(&oui);
}

Test(my_sort_list_alpha_folder, wooo, .init = redirect_all_std)
{
    struct stat t;
    stat("Makefile", &t);
    t_folder *oui = my_create_elem_folder(".", t);
    my_sort_list_alpha_folder(&oui, 1);
}

Test(my_rev_list_folder, wooo, .init = redirect_all_std)
{
    struct stat t;
    stat("Makefile", &t);
    t_folder *oui = my_create_elem_folder(".", t);
    my_rev_list_folder(&oui);
}

Test(printer_right, wooo, .init = redirect_all_std)
{
    struct stat t;
    stat("Makefile", &t);
    t_arg *oui = my_create_elem_arg(NULL, t, ".");
    printer_right(oui);
}

Test(printer_right_folder, wooo, .init = redirect_all_std)
{
    struct stat t;
    stat("Makefile", &t);
    t_folder *oui = my_create_elem_folder(".", t);
    printer_right_folder(oui);
}

Test(sort_folder_flags, wooo, .init = redirect_all_std)
{
    t_render *tmp = init_render();
    t_folder *res = malloc(sizeof(t_folder));
    sort_folder_flags(tmp, &res);
}

Test(my_list_size, wooo, .init = redirect_all_std)
{
    t_arg *res = malloc(sizeof(t_arg));
    my_list_size(res);
}
