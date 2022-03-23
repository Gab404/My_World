/*
** EPITECH PROJECT, 2022
** save.c
** File description:
** save
*/

#include "struct.h"
#include "my_world.h"

void check_interaction(button_t *array_btn, sfRenderWindow *window, \
                       map_t *map, sfVector3f **d3_vector)
{
    click_btn(array_btn, window, map, d3_vector);
    resize_tool(map);
    short_cut_btn(map, d3_vector);
    handle_event(map, window);
    create_mount(d3_vector, map, window);
    create_lake(d3_vector, map, window);

    return;
}

void is_already_save(map_t map, sfVector3f **d3_vector)
{
    if (map.already_save == false)
        save(&map, d3_vector);

    return;
}

int get_nb_file(char *filepath)
{
    DIR *dir = opendir(filepath);
    struct dirent *dp;
    int file_count = 0;

    if (dir == NULL)
        return 0;
    dp = readdir(dir);
    while (dp != NULL) {
        if (dp->d_type == DT_REG)
            file_count++;
        dp = readdir(dir);
    }
    closedir(dir);
    return file_count;
}

char *concat_nb_n_path(char *path_1, int nb, char *path_2)
{
    int len = my_strlen(path_1) + my_strlen(path_2) + nb_dig_int(nb);
    char *final_str = malloc(sizeof(char) * (len + 1));

    my_strcpy(final_str, path_1, 0);
    my_strcpy(final_str, int_to_str(nb), my_strlen(path_1));
    my_strcpy(final_str, path_2, len - my_strlen(path_2));

    final_str[len] = '\0';
    return final_str + 1;
}
