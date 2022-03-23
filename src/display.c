/*
** EPITECH PROJECT, 2022
** display.c
** File description:
** display
*/

#include "struct.h"
#include "my_world.h"

void key_pressed_move_y(map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        map->init_pos_y -= 7;
        map->modif_map = true;
    } else if (sfKeyboard_isKeyPressed(sfKeyW)) {
        map->init_pos_y += 7;
        map->modif_map = true;
    }
}

void key_zoom(map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyDash)) {
        map->zoom -= 0.1;
        map->modif_map = true;
    } else if (sfKeyboard_isKeyPressed(sfKeyEqual)) {
        map->zoom += 0.1;
        map->modif_map = true;
    }
}

void rotate_x(sfVector3f **d3_vector, float teta)
{
    float x;
    float y;

    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            x = d3_vector[i][j].x;
            y = d3_vector[i][j].y;
            d3_vector[i][j].x = x * cos(teta) + y * sin(teta) - teta * 32;
            d3_vector[i][j].y = -x * sin(teta) + y * cos(teta) + teta * 32;
        }
    }
    return;
}

void starting(sfRenderWindow *window, struct game_object_s **tab_bg, \
              float **matrix, sfVector3f **d3_vector)
{
    if (sfRenderWindow_isOpen(window)) {
        init(&d3_vector, matrix);
        my_world(window, d3_vector, tab_bg);
    }

    return;
}

void main_display(sfRenderWindow *window, banner_t banner, \
                  map_t map, button_t *array_btn)
{

    sfRenderWindow_drawSprite(window, banner.sprite, NULL);
    sfRenderWindow_drawText(window, banner.title, NULL);
    hover_btn(array_btn, window, 3, 56);
    display_btn(array_btn, 3, window);
    display_size(map, window);
    sfRenderWindow_display(window);

    return;
}
