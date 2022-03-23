/*
** EPITECH PROJECT, 2022
** create_element.c
** File description:
** create_element
*/

#include "struct.h"
#include "my_world.h"
#include "macro.h"

void draw_square(sfVector2f **map, sfRenderWindow *window)
{
    for (int i = 0; i != 64; i++) {
        for (int j = 0; j != 63; j++) {
            create_line(&map[i][j], &map[i][j + 1], window);
        }
    }
    for (int i = 0; i != 63; i++) {
        for (int j = 0; j != 64; j++) {
            create_line(&map[i][j], &map[i + 1][j], window);
        }
    }

    return;
}

void draw_wat(sfVector2f **map, sfRenderWindow *window, int i, int j)
{
    draw_t draw;

    draw.a = blue;
    for (int a = 0; a < 20; a++) {
        draw.pos = a;
        color_disp(&map[i][j], &map[i + 1][j], window, draw);
        color_disp_y(&map[i][j], &map[i + 1][j], window, draw);
    }

    return;
}

void draw_mont(sfVector2f **map, sfRenderWindow *window, int i, int j)
{
    draw_t draw;

    draw.a = grey;
    for (int a = 0; a < 20; a++) {
        draw.pos = a;
        color_disp(&map[i][j], &map[i + 1][j], window, draw);
        color_disp_y(&map[i][j], &map[i + 1][j], window, draw);
    }

    return;
}

void draw_ter(sfVector2f **map, sfRenderWindow *window, int i, int j)
{
    draw_t draw;

    draw.a = brown;
    for (int a = 0; a < 20; a++) {
        draw.pos = a;
        color_disp(&map[i][j], &map[i + 1][j], window, draw);
        color_disp_y(&map[i][j], &map[i + 1][j], window, draw);
    }

    return;
}

void draw_snow(sfVector2f **map, sfRenderWindow *window, int i, int j)
{
    draw_t draw;

    draw.a = sfWhite;
    for (float a = 0; a < 5; a += 0.2) {
        draw.pos = a;
        color_disp(&map[i][j], &map[i + 1][j], window, draw);
        color_disp_y(&map[i][j], &map[i + 1][j], window, draw);
    }

    return;
}
