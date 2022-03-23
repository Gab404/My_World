/*
** EPITECH PROJECT, 2022
** menu_2.c
** File description:
** menu_2
*/

#include "struct.h"
#include "my_world.h"

float **choice_preset(int choice_map)
{
    float **matrix;

    if (choice_map == 1)
        matrix = load_map("./preset/mountain.legend");
    else if (choice_map == 2)
        matrix = load_map("./preset/island.legend");
    else
        matrix = load_map("./preset/ocean.legend");

    return matrix;
}

button_t *set_btn_menu_2(void)
{
    button_t *array_btn = malloc(sizeof(button_t) * 3);

    array_btn[0] = fill_button(&reset_map, (sfVector2f){450, 250}, \
    "./assets/mountain.png", ".");
    array_btn[1] = fill_button(&lock_resize, (sfVector2f){450, 400}, \
    "./assets/island.png", ".");
    array_btn[2] = fill_button(&save, (sfVector2f){450, 530}, \
    "./assets/ocean.png", ".");

    for (int i = 0; i < 3; i++)
        array_btn[i].rect = (sfIntRect){ .left = 0, .top = 0, .width = 300, \
        .height = 135 };

    return array_btn;
}

void start_interaction(int *delimit_click, bool *mouse_left, int time, \
sfRenderWindow *window)
{
    if (*delimit_click == time)
        *mouse_left = handle_event_menu(window);
    else
        *delimit_click += 1;

    return;
}

void display_menu_2(sfRenderWindow *window, struct game_object_s **tab_bg, \
sfText *text_menu, button_t *array_btn)
{
    display_background(window, tab_bg);
    sfRenderWindow_drawText(window, text_menu, NULL);
    display_btn_menu(array_btn, 3, window);
    sfRenderWindow_display(window);

    return;
}

float **already_set_menu(sfRenderWindow *window, struct game_object_s **tab_bg)
{
    sfText *text_menu = create_text("My_World", sfWhite, 100, \
    (sfVector2f){360, 30});
    int choice_map = 0;
    button_t *array_btn = set_btn_menu_2();
    bool mouse_left = false;
    float **matrix;
    int delimit_click = 0;

    sfText_setFont(text_menu, sfFont_createFromFile("./assets/quantify.ttf"));
    while (sfRenderWindow_isOpen(window) && choice_map == 0) {
        sfRenderWindow_clear(window, sfBlack);
        start_interaction(&delimit_click, &mouse_left, 30, window);
        hover_btn_menu(array_btn, window, 3, 60);
        choice_map = click_btn_menu(array_btn, 3, window, mouse_left);
        display_menu_2(window, tab_bg, text_menu, array_btn);
    }
    matrix = choice_preset(choice_map);
    return matrix;
}
