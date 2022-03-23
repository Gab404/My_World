/*
** EPITECH PROJECT, 2022
** deform_map.c
** File description:
** deform_map
*/

#include "struct.h"
#include "my_world.h"

void detect_collide_mouse(sfVector2i mouse, sfVector3f *vector_3d, \
map_t *map, float nb_z)
{
    sfVector2f tmp_vector;
    float point_x;
    float point_y;

    project_iso_point(*vector_3d, &tmp_vector, *map);
    point_y = tmp_vector.y;
    point_x = tmp_vector.x;
    if (point_x < mouse.x + map->size_tool && \
    point_x > mouse.x - map->size_tool) {
        if (point_y < mouse.y + map->size_tool && \
        point_y > mouse.y - map->size_tool) {
            vector_3d->z += nb_z;
            map->already_save = false;
        }
    }
}

void check_all_point_2d(sfVector3f **d3_vector, sfVector2i mouse, \
map_t *map, float nb_z)
{
    int raw = map->size_y;
    int col = map->size_x;

    for (int i = 0; i < raw; i++) {
        for (int j = 0; j < col; j++) {
            map->modif_map = true;
            detect_collide_mouse(mouse, &d3_vector[i][j], map, nb_z);
        }
    }
}

void create_mount(sfVector3f **d3_vector, map_t *map, sfRenderWindow *window)
{
    sfVector2i mouse;

    if (map->mouse_left) {
        mouse = sfMouse_getPosition(window);
        check_all_point_2d(d3_vector, mouse, map, 0.3);
    }

    return;
}

void create_lake(sfVector3f **d3_vector, map_t *map, sfRenderWindow *window)
{
    sfVector2i mouse;

    if (map->mouse_right) {
        mouse = sfMouse_getPosition(window);
        check_all_point_2d(d3_vector, mouse, map, -0.3);
    }

    return;
}
