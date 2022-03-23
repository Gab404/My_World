/*
** EPITECH PROJECT, 2022
** banner.c
** File description:
** banner
*/

#include "struct.h"
#include "my_world.h"

sfText *set_text_banner(void)
{
    sfText *title = sfText_create();
    char *tools = "Tools";

    sfText_setString(title, tools);
    sfText_setPosition(title, (sfVector2f) { 1020, 30 });
    sfText_setCharacterSize(title, 40);
    sfText_setColor(title, sfBlack);
    sfText_setFont(title, \
    sfFont_createFromFile("./assets/cubic.ttf"));
    return title;
}

banner_t fill_banner(void)
{
    banner_t banner;

    banner.title = set_text_banner();
    banner.pos = (sfVector2f){ 1000, 0 };
    banner.sprite = sfSprite_create();
    banner.rect = (sfIntRect){ .left = 0, .top = 0, .width = 200, \
    .height = 800 };
    banner.texture = sfTexture_createFromFile("./assets/white.png", NULL);
    sfSprite_setPosition(banner.sprite, banner.pos);
    sfSprite_setTexture(banner.sprite, banner.texture, sfTrue);
    sfSprite_setTextureRect(banner.sprite, banner.rect);

    return banner;
}
