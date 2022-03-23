/*
** EPITECH PROJECT, 2022
** my_world.c
** File description:
** my_world
*/

#include "struct.h"
#include "my_world.h"

map_t fill_map(void)
{
    map_t map;

    map.zoom = 10;
    map.init_pos_x = 550.0;
    map.init_pos_y = 250.0;
    map.angle_y = 25.0;
    map.key_left = false;
    map.key_right = false;
    map.teta = 0;
    map.size_x = 64;
    map.size_y = 64;
    map.mouse_left = false;
    map.mouse_right = false;
    map.btn_rotate = true;
    map.nb_click = 0;
    map.lock_resize = false;
    map.size_tool = 10;
    map.already_save = false;
    map.modif_map = false;
    return map;
}

sfVector2f **move_map(sfVector2f **d2_vector, sfVector3f **d3_vector, \
sfRenderWindow *window, map_t *map)
{
    rotate_x(d3_vector, map->teta);
    key_pressed(map);
    if (map->modif_map) {
        d2_vector = calcul_2d(d3_vector, *map);
        map->modif_map = false;
    }
    draw_2d_map(window, d2_vector, d3_vector, *map);

    return d2_vector;
}

void my_world(sfRenderWindow *window, sfVector3f **d3_vector, \
struct game_object_s **tab_bg)
{
    map_t map = fill_map();
    sfVector2f **d2_vector = calcul_2d(d3_vector, map);
    banner_t banner = fill_banner();
    button_t *array_btn = set_all_btn();
    sfSoundBuffer **buffer_sound = malloc(sizeof(sfSoundBuffer *));
    sfSound *sound = set_my_sound(buffer_sound);
    bool already_played = false;

    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        display_background(window, tab_bg);
        check_interaction(array_btn, window, &map, d3_vector);
        d2_vector = move_map(d2_vector, d3_vector, window, &map);
        main_display(window, banner, map, array_btn);
        play_saving_song(sound, map, &already_played);
    }
    is_already_save(map, d3_vector);
    music_destroy(sound, buffer_sound);
}


float **choice_menu(float **matrix, int choice_map, sfRenderWindow *window, \
struct game_object_s **tab_bg)
{
    if (choice_map == 1)
        matrix = fill_map_3D(64, 64);
    else if (choice_map == 2)
        matrix = saved_map_menu(window, tab_bg);
    else
        matrix = already_set_menu(window, tab_bg);

    return matrix;
}

int main(int argc, char **argv)
{
    sfVector3f **d3_vector;
    sfRenderWindow *window;
    float **matrix;
    struct game_object_s **tab_bg = all_struct_bg();
    sfMusic *background_music = set_music_back();

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        help();
        return 0;
    } else if (argc == 2) {
        window = handle_window();
        matrix = load_map(argv[1]);
        starting(window, tab_bg, matrix, d3_vector);
        return 0;
    }
    handle_all_menu(window, tab_bg, matrix, d3_vector);
    sfMusic_destroy(background_music);
    return 0;
}
