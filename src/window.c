/*
** EPITECH PROJECT, 2022
** window.c
** File description:
** window.c
*/

#include "struct.h"
#include "my_world.h"

void handle_all_menu(sfRenderWindow *window, struct game_object_s **tab_bg, \
float **matrix, sfVector3f **d3_vector)
{
    int choice_map;

    window = handle_window();
    choice_map = start_menu(window, tab_bg);
    if (choice_map == -1)
        return;
    matrix = choice_menu(matrix, choice_map, window, tab_bg);
    starting(window, tab_bg, matrix, d3_vector);

    return;
}

void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);

    return;
}

sfRenderWindow *handle_window(void)
{
    sfVideoMode mode = { 1200, 800, 32 };
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "My World", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 70);

    return window;
}
