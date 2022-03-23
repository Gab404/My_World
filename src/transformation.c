/*
** EPITECH PROJECT, 2022
** rotation.c
** File description:
** rotation
*/

#include "struct.h"
#include "my_world.h"

void key_pressed_move_x(map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        map->init_pos_x -= 7;
        map->modif_map = true;
    } else if (sfKeyboard_isKeyPressed(sfKeyD)) {
        map->init_pos_x += 7;
        map->modif_map = true;
    }
}

void reset_teta_x(map_t *map)
{
    if (map->key_left) {
        map->teta += 0.09;
        map->key_left = false;
        map->modif_map = true;
    } else if (map->key_right) {
        map->teta -= 0.09;
        map->key_right = false;
        map->modif_map = true;
    }

    return;
}

void key_pressed_x(map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        map->teta -= 0.09;
        map->key_left = true;
        map->modif_map = true;
    } else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        map->teta += 0.09;
        map->key_right = true;
        map->modif_map = true;
    }

    return;
}

void key_pressed_y(map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        map->angle_y += 0.9;
        map->modif_map = true;
    } else if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        map->angle_y -= 0.9;
        map->modif_map = true;
    }

    return;
}

void key_pressed(map_t *map)
{
    if (map->lock_resize == false) {
        reset_teta_x(map);
        key_pressed_x(map);
        key_pressed_y(map);
        key_pressed_move_x(map);
        key_pressed_move_y(map);
    }
    key_zoom(map);

    return;
}
