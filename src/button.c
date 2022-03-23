/*
** EPITECH PROJECT, 2022
** button.c
** File description:
** button
*/

#include "struct.h"
#include "my_world.h"

void hover_btn(button_t *btn, sfRenderWindow *window, int nb, int hover_height)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    int x = mouse.x;
    int y = mouse.y;

    for (int i = 0; i < nb; i++) {
        if ((x <= btn[i].pos.x + btn[i].rect.width && x >= btn[i].pos.x) && \
        (y <= btn[i].pos.y + hover_height && y >= btn[i].pos.y)) {
            sfSprite_setScale(btn[i].sprite, (sfVector2f) { 0.46, 0.46 });
            btn[i].hover = true;
            sfRenderWindow_drawText(window, btn[i].help, NULL);
        } else
            btn[i].hover = false;
    }
}

void click_btn(button_t *btn, sfRenderWindow *window, map_t *map, \
sfVector3f **d3_vector)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    int x = mouse.x;
    int y = mouse.y;

    for (int i = 0; i < 3; i++) {
        if ((x <= btn[i].pos.x + 182 && x >= btn[i].pos.x) && \
        map->nb_click == 1 && (y <= btn[i].pos.y + 52 && \
        y >= btn[i].pos.y))
            btn[i].pt_fct(map, d3_vector);
    }
}

void display_btn(button_t *btn, int nb, sfRenderWindow *window)
{
    for (int i = 0; i < nb; i++) {
        if (btn[i].hover == false)
            sfSprite_setScale(btn[i].sprite, (sfVector2f) { 0.45, 0.45 });
        sfRenderWindow_drawSprite(window, btn[i].sprite, NULL);
    }

    return;
}

button_t fill_button(void (*pt_fct)(map_t *, sfVector3f **), sfVector2f pos, \
char *filepath, char *content_text)
{
    button_t btn;

    btn.hover = false;
    btn.pt_fct = pt_fct;
    btn.sprite = sfSprite_create();
    btn.texture = sfTexture_createFromFile(filepath, NULL);
    btn.pos = pos;
    btn.rect = (sfIntRect){ .left = 0, .top = 0, .width = 474, .height = 139 };
    btn.help = create_text(content_text, sfBlack, 20, (sfVector2f)\
    { 1020, 550 });
    sfSprite_setPosition(btn.sprite, btn.pos);
    sfSprite_setTexture(btn.sprite, btn.texture, sfTrue);
    sfSprite_setTextureRect(btn.sprite, btn.rect);

    return btn;
}

button_t *set_all_btn(void)
{
    button_t *array_btn = malloc(sizeof(button_t) * 3);

    array_btn[0] = fill_button(&reset_map, (sfVector2f) { 1000, 200 }, \
    "./assets/reset.png", "Reset map (R)");
    array_btn[1] = fill_button(&lock_resize, (sfVector2f) { 1000, 300 }, \
    "./assets/resize.png", "Press and repress to \nchange tool size (T)");
    array_btn[2] = fill_button(&save, (sfVector2f) { 1000, 400 }, \
    "./assets/save.png", "Save map in '.legend' (S)");

    return array_btn;
}
