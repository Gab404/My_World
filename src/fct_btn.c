/*
** EPITECH PROJECT, 2022
** fct_btn.c
** File description:
** fct_btn
*/

#include "struct.h"
#include "my_world.h"

void short_cut_btn(map_t *map, sfVector3f **d3_vector)
{
    if (sfKeyboard_isKeyPressed(sfKeyS))
        save(map, d3_vector);
    else if (sfKeyboard_isKeyPressed(sfKeyR))
        reset_map(map, d3_vector);
    if (sfKeyboard_isKeyPressed(sfKeyT))
        lock_resize(map, d3_vector);


    return;
}

void reset_map(map_t *map, sfVector3f **d3_vector)
{
    for (int i = 0; i < map->size_y; i++) {
        for (int j = 0; j < map->size_x; j++)
            d3_vector[i][j].z = 0;
    }

    map->modif_map = true;
    return;
}

void save(map_t *map, sfVector3f **d3_vector)
{
    int nb_file = get_nb_file("./save");
    char *filepath = concat_nb_n_path("../save/map", nb_file + 1, ".legend");
    int fd = open(filepath, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
    char *coord_z;

    for (int i = 0; i < map->size_y && fd != -1; i++) {
        for (int j = 0; j < map->size_x; j++) {
            coord_z = malloc(sizeof(char) * \
                             my_strlen(float_to_str(d3_vector[i][j].z)));
            coord_z = float_to_str(d3_vector[i][j].z);
            write(fd, coord_z, my_strlen(coord_z));
            write(fd, " ", 1);
        }
        write(fd, "\n", 1);
    }
    close(fd);
    map->already_save = true;
}

void lock_resize(map_t *map, sfVector3f **d3_vector)
{
    if (map->lock_resize)
        map->lock_resize = false;
    else
        map->lock_resize = true;
}
