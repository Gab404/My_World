/*
** EPITECH PROJECT, 2022
** size_tool.c
** File description:
** size_tool
*/

#include "struct.h"
#include "my_world.h"

sfText *create_text(char *str, sfColor color, int scale, sfVector2f pos)
{
    sfText *text = sfText_create();

    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, scale);
    sfText_setColor(text, color);
    sfText_setFont(text, sfFont_createFromFile("./assets/bebas.ttf"));

    return text;
}

void display_size(map_t map, sfRenderWindow *window)
{
    sfText *size = create_text("size:", sfBlack, 33, \
    (sfVector2f) { 1020, 730 });
    sfText *nb = create_text(int_to_str(map.size_tool), sfBlack, 33, \
    (sfVector2f) { 1100, 730 });

    sfRenderWindow_drawText(window, size, NULL);
    sfRenderWindow_drawText(window, nb, NULL);
}

void resize_tool(map_t *map)
{
    if (map->lock_resize && sfKeyboard_isKeyPressed(sfKeyLeft) && \
    map->size_tool > 0)
        map->size_tool--;
    else if (map->lock_resize && sfKeyboard_isKeyPressed(sfKeyRight) && \
    map->size_tool < 50)
        map->size_tool++;

    return;
}
