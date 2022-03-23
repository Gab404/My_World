/*
** EPITECH PROJECT, 2022
** help.c
** File description:
** help
*/

#include "struct.h"
#include "my_world.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int  decompteur = 0;

    while (str[decompteur] != '\0') {
        my_putchar(str[decompteur]);
        decompteur = decompteur + 1;
    }
    return (0);
}

void help(void)
{
    my_putstr("\nUSAGE\n");
    my_putstr("./my_world\n\n");
    my_putstr("DESCRIPION\n");
    my_putstr("  + to zoom in\n");
    my_putstr("  - to zoom back\n");
    my_putstr("  S to save map\n");
    my_putstr("  R to reset map\n");
    my_putstr("  T to resize tool\n");
    my_putstr("  D to move map right\n");
    my_putstr("  Q to move map left\n");
    my_putstr("  Z to move map up\n");
    my_putstr("  W to move map down\n");
    my_putstr("  KEY_UP to up view\n");
    my_putstr("  KEY_DOWN to down view\n");
    my_putstr("  KEY_RIGHT to turn right view\n");
    my_putstr("  KEY_LEFT to turn left view\n\n");
}
