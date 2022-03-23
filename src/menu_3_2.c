/*
** EPITECH PROJECT, 2022
** menu_3_2.c
** File description:
** menu_3_2
*/

#include "struct.h"
#include "my_world.h"

void set_pos_btn(int i, float *pos_x, float *pos_y)
{
    if (i == 3 || i == 6) {
        *pos_y += 100;
        *pos_x = 350;
    } else
        *pos_x += 200;

    return;
}

sfText **set_all_text(int nb_file)
{
    sfText **all_text;
    char *content_button;
    float pos_x = 150;
    float pos_y = 400;

    if (nb_file == 0) {
        all_text = if_no_file();
        return all_text;
    }
    all_text = malloc(sizeof(sfText *) * nb_file);
    for (int i = 0; i < nb_file && i < 9; i++) {
        set_pos_btn(i, &pos_x, &pos_y);
        content_button = concat_str_n_int("map ", i + 1);
        all_text[i] = create_text(content_button, sfWhite, 40, \
        (sfVector2f){ pos_x, pos_y });
    }
    return all_text;
}

void display_all_text(sfText **text, sfRenderWindow *window)
{
    int nb = get_nb_file("./save");

    for (int i = 0; i < nb && i < 9; i++) {
        sfRenderWindow_drawText(window, text[i], NULL);
    }

    if (nb == 0)
        sfRenderWindow_drawText(window, text[0], NULL);

    return;
}
