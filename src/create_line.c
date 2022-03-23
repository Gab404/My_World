/*
** EPITECH PROJECT, 2022
** create_line.c
** File description:
** create_line
*/

#include "struct.h"
#include "my_world.h"
#include "macro.h"

void draw_snow_mont(sfRenderWindow *window, map_t strt, int i, int j)
{
    if (strt.d3_vector[i][j].z > 5)
        draw_snow(strt.map, window, i, j);
    else
        draw_mont(strt.map, window, i, j);

    return;
}

void draw_start(map_t strt, sfRenderWindow *window, int i, int j)
{
    draw_t draw;

    draw.a = vert;
    for (float a = 0; a < 20; a++) {
        draw.pos = a;
        color_disp(&strt.map[i][j], &strt.map[i + 1][j], window, draw);
        color_disp_y(&strt.map[i][j], &strt.map[i + 1][j], window, draw);
    }
    if (strt.d3_vector[i][j].z < 0) {
        if (strt.d3_vector[i][j].z > -0.5)
            draw_ter(strt.map, window, i, j);
        else
            draw_wat(strt.map, window, i, j);
    } else if (strt.d3_vector[i][j].z > 0)
        draw_snow_mont(window, strt, i, j);

}

void draw_2d_map(sfRenderWindow *window, sfVector2f **d2_vector, \
sfVector3f **d3_vector, map_t map)
{
    map.d3_vector = d3_vector;
    map.map = d2_vector;
    for (int i = 0; i != map.size_y - 1; i++) {
        for (int j = 0; j != map.size_x - 1; j++) {
            draw_start(map, window, i, j);
        }
    }
    draw_square(d2_vector, window);

    return;
}
