/*
** EPITECH PROJECT, 2022
** lib_2.c
** File description:
** lib_2
*/

#include "struct.h"
#include "my_world.h"

char *int_to_str(int nb)
{
    int len = nb_dig_int(nb);
    char *str = malloc(sizeof(char) * len);
    int i = 0;

    for (; i <= len; i++) {
        str[i] = (nb % 10) + 48;
        nb = nb / 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    if (str[0] == '0')
        str++;
    return str;
}

char *my_strcpy(char *dest, char *src, int j)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[j] = src[i];
        i++;
        j++;
    }
    return dest;
}

void display_error(char *str)
{
    write(2, str, my_strlen(str));
    return;
}

float my_getnbr_float(char *str)
{
    float nb = my_getnbr(str);

    return nb / 100;
}