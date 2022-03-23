/*
** EPITECH PROJECT, 2022
** create_line_helper1.c
** File description:
** create_line_helper1
*/

#include "struct.h"
#include "my_world.h"
#include "macro.h"

void create_line(sfVector2f *point1, sfVector2f *point2, \
sfRenderWindow *window)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = { .position = *point1 , . color = sfBlack };
    sfVertex vertex2 = { .position = *point2 , . color = sfBlack };

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);

    return;
}

sfVector2f load_pw(int pos, sfVector2f *point)
{
    sfVector2f p;

    p.x = point->x + pos;
    p.y = point->y;

    return p;
}

void color_disp(sfVector2f *point1, sfVector2f *point2, \
sfRenderWindow *window, draw_t draw)
{
    sfVector2f p = load_pw(draw.pos, point1);
    sfVector2f wp = load_pw(draw.pos, point2);
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = { .position = p , . color = draw.a };
    sfVertex vertex2 = { .position = wp , . color = draw.a };

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);

    return;
}

sfVector2f load_p(int pos, sfVector2f *point)
{
    sfVector2f p;

    p.x = point->x;
    p.y = point->y + pos;

    return p;
}

void color_disp_y(sfVector2f *point1, sfVector2f *point2, \
sfRenderWindow *window, draw_t draw)
{
    sfVector2f p = load_p(draw.pos, point1);
    sfVector2f wp = load_p(draw.pos, point2);
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = { .position = p , . color = draw.a };
    sfVertex vertex2 = { .position = wp , . color = draw.a };

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);

    return;
}
