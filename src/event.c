/*
** EPITECH PROJECT, 2022
** event.c
** File description:
** event
*/

#include "struct.h"
#include "my_world.h"

void detect_mouse(map_t *map, sfEvent event)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) || \
    sfMouse_isButtonPressed(sfMouseRight)) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            map->mouse_left = true;
        else
            map->mouse_right = true;
    } else if (event.type == sfEvtMouseButtonReleased) {
        map->mouse_left = false;
        map->mouse_right = false;
        map->nb_click = 0;
    }

    return;
}

bool handle_event_menu(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        close_window(window, event);

    if (sfMouse_isButtonPressed(sfMouseLeft))
        return true;
    else
        return false;
}

void handle_event(map_t *map, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        detect_mouse(map, event);
        close_window(window, event);
    }
    if (map->mouse_left)
        map->nb_click++;

    return;
}
