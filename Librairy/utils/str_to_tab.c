/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** str_to_tab.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

bool is_a_sep(char c, char const *sep)
{
    for (int ctr = 0; sep[ctr] != '\0'; ctr += 1)
        if (c == sep[ctr])
            return (true);
    return (false);
}

int count_height(char const *str, char const *sep)
{
    int tab_height = 1;
    int ctr = 0;

    if (str == NULL)
        return (0);
    while (is_a_sep(str[ctr], sep) == true)
        ctr += 1;
    while (str[ctr] != '\0') {
        if (is_a_sep(str[ctr], sep) == true) {
            tab_height += 1;
            while (is_a_sep(str[ctr], sep) == true)
                ctr += 1;
            if (str[ctr] == '\0')
                tab_height -= 1;
            ctr -= 1;
        }
        ctr += 1;
    }
    return (tab_height);
}

char *take_line(char const *str, char const *sep)
{
    int len = 0;
    char *line = NULL;

    if (str == NULL)
        return (NULL);
    while (is_a_sep(str[len], sep) == false && str[len] != '\0')
        len += 1;
    line = malloc(sizeof(char) * (len + 1));
    if (line == NULL)
        return (NULL);
    for (int ctr = 0; ctr < len; ctr += 1)
        line[ctr] = str[ctr];
    line[len] = '\0';
    return (line);
}

char **str_to_tab(char const *str, char const *sep)
{
    int tab_height = count_height(str, sep);
    int ctr = 0;
    char **tab = malloc(sizeof(char *) * (tab_height + 1));

    if (tab == NULL)
        return (NULL);
    for (int tab_ctr = 0; tab_ctr < tab_height; tab_ctr += 1) {
        while (is_a_sep(str[ctr], sep) == true)
            ctr += 1;
        tab[tab_ctr] = take_line(&(str[ctr]), sep);
        while (is_a_sep(str[ctr], sep) == false && str[ctr] != '\0')
            ctr += 1;
        if (str[ctr] == '\0')
            break;
    }
    tab[tab_height] = NULL;
    return (tab);
}