/*
** EPITECH PROJECT, 2022
** lib.c
** File description:
** lib
*/

#include "struct.h"
#include "my_world.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    int i = 0;
    char tmp;
    int end = len + 1;

    while (i < len) {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        i++;
        len--;
    }
    str[end] = '\0';
    return (str);
}

int nb_dig_int(int nb)
{
    int i = 0;

    if (nb == 10)
        return 2;
    else if (nb == 0)
        return 1;
    while (nb > 1) {
        nb = nb / 10;
        i++;
    }
    return i;
}

char *fill_str(int nb_int, char *str, int len, int i)
{
    for (; i <= len; i++) {
        str[i] = (nb_int % 10) + 48;
        nb_int = nb_int / 10;
    }
    str[len + 1] = '\0';
    str = my_revstr(str);
    if (str[0] == '0')
        str++;

    return str;
}

char *float_to_str(float nb)
{
    int len;
    char *str;
    int i = 0;
    int nb_int = nb * 100;

    if (nb == 0.00)
        return "0";
    else if (nb < 0.00) {
        nb_int *= -1;
        i++;
        len = nb_dig_int(nb_int) + 1;
        str = malloc(sizeof(char) * len + 2);
        str[0] = '-';
    } else {
        len = nb_dig_int(nb_int);
        str = malloc(sizeof(char) * len + 2);
    }
    str = fill_str(nb_int, str, len, i);
    return str;
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;

    return i;
}