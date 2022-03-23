/*
** EPITECH PROJECT, 2022
** menu.c
** File description:
** menu
*/

#include "struct.h"
#include "my_world.h"

void hover_btn_menu(button_t *btn, sfRenderWindow *window, int nb, \
int hover_height)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    int x = mouse.x;
    int y = mouse.y;

    for (int i = 0; i < nb; i++) {
        if ((x <= btn[i].pos.x + btn[i].rect.width && x >= btn[i].pos.x) && \
        (y <= btn[i].pos.y + hover_height && y >= btn[i].pos.y)) {
            sfSprite_setScale(btn[i].sprite, (sfVector2f) { 0.62, 0.62 });
            btn[i].hover = true;
            sfRenderWindow_drawText(window, btn[i].help, NULL);
        } else
            btn[i].hover = false;
    }
}

int click_btn_menu(button_t *btn, int nb, sfRenderWindow *window, \
bool mouse_left)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    int x = mouse.x;
    int y = mouse.y;

    for (int i = 0; i < nb; i++) {
        if ((x <= btn[i].pos.x + btn[i].rect.width && x >= btn[i].pos.x) && \
        (y <= btn[i].pos.y + btn[i].rect.height && y >= btn[i].pos.y && \
        mouse_left))
            return i + 1;
    }

    return 0;
}

button_t *set_all_btn_menu(void)
{
    button_t *array_btn = malloc(sizeof(button_t) * 3);

    array_btn[0] = fill_button(&reset_map, (sfVector2f) { 450, 250 }, \
    "./assets/new_map.png", ".");
    array_btn[1] = fill_button(&lock_resize, (sfVector2f) { 450, 400 }, \
    "./assets/saved_map.png", ".");
    array_btn[2] = fill_button(&save, (sfVector2f) { 410, 530 }, \
    "./assets/already_set.png", ".");

    for (int i = 0; i < 3; i++) {
        array_btn[i].rect = (sfIntRect){ .left = 0, .top = 0, \
        .width = 215, .height = 115 };
    }
    return array_btn;
}

void display_btn_menu(button_t *btn, int nb, sfRenderWindow *window)
{
    for (int i = 0; i < nb; i++) {
        if (btn[i].hover == false)
            sfSprite_setScale(btn[i].sprite, (sfVector2f) { 0.6, 0.6 });
        sfRenderWindow_drawSprite(window, btn[i].sprite, NULL);
    }
}

int start_menu(sfRenderWindow *window, struct game_object_s **tab_bg)
{
    sfText *text_menu = create_text("My_World", sfWhite, 100, \
    (sfVector2f) { 360, 30 });
    int choice_map = 0;
    button_t *array_btn = set_all_btn_menu();
    bool mouse_left = false;

    sfText_setFont(text_menu, sfFont_createFromFile("./assets/quantify.ttf"));
    while (sfRenderWindow_isOpen(window) && choice_map == 0) {
        sfRenderWindow_clear(window, sfBlack);
        mouse_left = handle_event_menu(window);
        hover_btn_menu(array_btn, window, 3, 60);
        choice_map = click_btn_menu(array_btn, 3, window, mouse_left);
        display_background(window, tab_bg);
        sfRenderWindow_drawText(window, text_menu, NULL);
        display_btn_menu(array_btn, 3, window);
        sfRenderWindow_display(window);
    }
    if (sfRenderWindow_isOpen(window) == false)
        return -1;
    return choice_map;
}
