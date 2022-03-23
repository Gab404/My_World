/*
** EPITECH PROJECT, 2022
** menu_3.c
** File description:
** menu_3
*/

#include "struct.h"
#include "my_world.h"

char *concat_str_n_int(char *str, int nb)
{
    int len = my_strlen(str) + nb_dig_int(nb);
    char *final_str = malloc(sizeof(char) * (len + 1));

    my_strcpy(final_str, str, 0);
    my_strcpy(final_str, int_to_str(nb), my_strlen(str));

    final_str[len + 1] = '\0';
    return final_str;
}

sfText **if_no_file(void)
{
    sfText **all_text = malloc(sizeof(sfText *));

    all_text[0] = create_text("No map saved !", sfWhite, 50, \
    (sfVector2f){ 450, 400 });

    return all_text;
}

int click_text_menu(int nb, sfRenderWindow *window, \
bool mouse_left)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    int x = mouse.x;
    int y = mouse.y;
    int pos_x = 150;
    int pos_y = 400;

    for (int i = 0; i < nb && i < 9; i++) {
        if (i == 3 || i == 6) {
            pos_y += 100;
            pos_x = 350;
        } else
            pos_x += 200;
        if ((x <= pos_x + 80 && x >= pos_x)) {
            if (y <= pos_y + 43 && y >= pos_y && mouse_left)
                return i + 1;
        }
    }
    return 0;
}

void display_menu_3(sfRenderWindow *window, struct game_object_s **tab_bg, \
sfText *text_menu, sfText **all_btn)
{
    display_background(window, tab_bg);
    sfRenderWindow_drawText(window, text_menu, NULL);
    display_all_text(all_btn, window);
    sfRenderWindow_display(window);

    return;
}

float **saved_map_menu(sfRenderWindow *window, struct game_object_s **tab_bg)
{
    sfText *text_menu = create_text("My_World", sfWhite, 100, \
    (sfVector2f){ 360, 30 });
    int nb_file = get_nb_file("./save");
    sfText **all_btn = set_all_text(nb_file);
    int choice_map = 0;
    bool mouse_left = false;
    float **matrix;
    int delimit_click = 0;

    sfText_setFont(text_menu, sfFont_createFromFile("./assets/quantify.ttf"));
    while (sfRenderWindow_isOpen(window) && choice_map == 0) {
        sfRenderWindow_clear(window, sfBlack);
        start_interaction(&delimit_click, &mouse_left, 30, window);
        choice_map = click_text_menu(nb_file, window, mouse_left);
        display_menu_3(window, tab_bg, text_menu, all_btn);
    }
    if (sfRenderWindow_isOpen(window))
        matrix = load_map(concat_nb_n_path("../save/map", choice_map, \
        ".legend"));
    return matrix;
}
