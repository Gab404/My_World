/*
** EPITECH PROJECT, 2022
** coord_map.c
** File description:
** coord_map
*/

#include "struct.h"
#include "my_world.h"
#include "macro.h"

void project_iso_point(sfVector3f vector, sfVector2f *d2_point, map_t map)
{
    float pos_x = map.init_pos_x;
    float pos_y = map.init_pos_y;
    float angle_x = nb_PI * 20 / 180;
    float angle_y = nb_PI * map.angle_y / 180;

    d2_point->x = cos(angle_x) * vector.x - cos(angle_x) * vector.y;
    d2_point->y = sin(angle_y) * vector.y + sin(angle_y) * vector.x - vector.z;
    d2_point->x *= map.zoom;
    d2_point->y *= map.zoom;
    d2_point->x += pos_x;
    d2_point->y += pos_y;
}

void get_3d_vector(sfVector3f ***vector, float **map, int raw, int col)
{
    *vector = malloc(sizeof(sfVector3f *) * raw);

    for (int i = 0; i < raw; i++) {
        (*vector)[i] = malloc(sizeof(sfVector3f) * col);
        for (int j = 0; j < col; j++) {
            (*vector)[i][j].x = j;
            (*vector)[i][j].y = i;
            (*vector)[i][j].z = map[i][j];
        }
    }
    return;
}

float **fill_map_3D(int raw, int col)
{
    float **map = malloc(sizeof(int *) * raw);

    for (int i = 0; i < raw; i++) {
        map[i] = malloc(sizeof(int) * col);
    }
    for (int i = 0; i < raw; i++) {
        for (int j = 0; j < col; j++) {
            map[i][j] = 0;
        }
    }

    return map;
};

sfVector2f **calcul_2d(sfVector3f **vector, map_t map)
{
    sfVector2f **coord_iso_point = malloc(sizeof(sfVector2f *) * 64);

    for (int i = 0; i < 64; i++) {
        coord_iso_point[i] = malloc(sizeof(sfVector2f) * 64);
        for (int j = 0; j < 64; j++) {
            project_iso_point(vector[i][j], &(coord_iso_point[i][j]), map);
        }
    }

    return coord_iso_point;
}

sfVector3f ***init(sfVector3f ***d3_vector, float **map)
{
    get_3d_vector(d3_vector, map, 64, 64);

    return d3_vector;
}
