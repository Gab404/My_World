/*
** EPITECH PROJECT, 2022
** handle_background.c
** File description:
** handle_background
*/

#include "struct.h"
#include "my_world.h"

struct game_object_s *create_object(const char *path_to_sprite_sheet, \
sfVector2f pos, sfIntRect rect)
{
    struct game_object_s *create_object = malloc(sizeof(struct game_object_s));

    create_object->texture = sfTexture_createFromFile(path_to_sprite_sheet, \
    NULL);
    create_object->sprite = sfSprite_create();
    create_object->rect = rect;
    create_object->pos = pos;
    sfSprite_setPosition(create_object->sprite, create_object->pos);
    sfSprite_setTexture(create_object->sprite, create_object->texture, sfTrue);
    sfSprite_setTextureRect(create_object->sprite, create_object->rect);

    return create_object;
}

struct game_object_s **all_struct_bg(void)
{
    struct game_object_s **tab_bg = malloc(sizeof(struct game_object_s *) * 4);

    tab_bg[0] = create_object("./assets/stars.png", \
    (sfVector2f){0, 0}, (sfIntRect) { .left = 0, .top = 0, \
    .width = 1200, .height = 850});
    tab_bg[1] = create_object("./assets/stars.png", \
    (sfVector2f){1200, 0}, (sfIntRect) { .left = 0, .top = 0, \
    .width = 1200, .height = 800});
    tab_bg[2] = create_object("./assets/stars.png", \
    (sfVector2f){0, 200}, (sfIntRect) { .left = 0, .top = 0, \
    .width = 1200, .height = 600});
    tab_bg[3] = create_object("./assets/stars.png", \
    (sfVector2f){1200, 200}, (sfIntRect) { .left = 0, .top = 0, \
    .width = 1200, .height = 600});
    return tab_bg;
}

void parallax_stars(struct game_object_s **tab_bg)
{
    if (tab_bg[0]->pos.x == 0)
        tab_bg[1]->pos.x = 1200;
    else if (tab_bg[1]->pos.x == 0)
        tab_bg[0]->pos.x = 1200;
    tab_bg[0]->pos.x -= 1;
    tab_bg[1]->pos.x -= 1;
    sfSprite_setPosition(tab_bg[0]->sprite, tab_bg[0]->pos);
    sfSprite_setPosition(tab_bg[1]->sprite, tab_bg[1]->pos);
}

void parallax_stars_2(struct game_object_s **tab_bg)
{
    if (tab_bg[2]->pos.x == 0)
        tab_bg[3]->pos.x = 1200;
    else if (tab_bg[3]->pos.x == 0)
        tab_bg[2]->pos.x = 1200;
    tab_bg[2]->pos.x -= 2;
    tab_bg[3]->pos.x -= 2;
    sfSprite_setPosition(tab_bg[2]->sprite, tab_bg[2]->pos);
    sfSprite_setPosition(tab_bg[3]->sprite, tab_bg[3]->pos);
}

void display_background(sfRenderWindow *window, struct game_object_s **tab_bg)
{
    sfRenderWindow_drawSprite(window, tab_bg[0]->sprite, NULL);
    sfRenderWindow_drawSprite(window, tab_bg[1]->sprite, NULL);
    sfRenderWindow_drawSprite(window, tab_bg[2]->sprite, NULL);
    sfRenderWindow_drawSprite(window, tab_bg[3]->sprite, NULL);
    parallax_stars(tab_bg);
    parallax_stars_2(tab_bg);
}
