/*
** EPITECH PROJECT, 2021
** my_world.h
** File description:
** my_world
*/

#ifndef MY_WORLD_H_
    #define MY_WORLD_H_

    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <SFML/Audio.h>
    #include <SFML/Window/Export.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Graphics.h>
    #include <unistd.h>
    #include <math.h>
    #include <stdio.h>

float **choice_menu(float **matrix, int choice_map, sfRenderWindow *window, \
struct game_object_s **tab_bg);
void check_interaction(button_t *array_btn, sfRenderWindow *window, \
map_t *map, sfVector3f **d3_vector);
sfSound *set_my_sound(sfSoundBuffer **buffer);
void music_destroy(sfSound *music, sfSoundBuffer **buffer);
void play_saving_song(sfSound *sound, map_t map, bool *already_played);
sfMusic *set_music_back(void);
void handle_all_menu(sfRenderWindow *window, struct game_object_s **tab_bg, \
float **matrix, sfVector3f **d3_vector);
void my_world(sfRenderWindow *window, sfVector3f **d3_vector, \
struct game_object_s **tab_bg);
char *concat_str_n_int(char *str, int nb);
sfText **if_no_file(void);
void start_interaction(int *delimit_click, bool *mouse_left, int time, \
sfRenderWindow *window);
float my_getnbr(char *str);
float **already_set_menu(sfRenderWindow *window, \
struct game_object_s **tab_bg);
void draw_ter(sfVector2f **map, sfRenderWindow *window, int i, int j);
void draw_snow(sfVector2f **map, sfRenderWindow *window, int i, int j);
void draw_square(sfVector2f **map, sfRenderWindow *window);
void draw_wat(sfVector2f **map, sfRenderWindow *window, int i, int j);
void draw_mont(sfVector2f **map, sfRenderWindow *window, int i, int j);
void create_line(sfVector2f *point1, sfVector2f *point2, \
sfRenderWindow *window);
sfVector2f load_pw(int pos, sfVector2f *point);
void color_disp(sfVector2f *point1, sfVector2f *point2, \
sfRenderWindow *window, draw_t draw);
sfVector2f load_p(int pos, sfVector2f *point);
void color_disp_y(sfVector2f *point1, sfVector2f *point2, \
sfRenderWindow *window, draw_t draw);
float **saved_map_menu(sfRenderWindow *window, struct game_object_s **tab_bg);
void hover_btn_menu(button_t *btn, sfRenderWindow *window, int nb, \
int hover_height);
void display_btn_menu(button_t *btn, int nb, sfRenderWindow *window);
int click_btn_menu(button_t *btn, int nb, sfRenderWindow *window, \
bool mouse_left);
button_t fill_button(void (*pt_fct)(map_t *, sfVector3f **), sfVector2f pos, \
char *filepath, char *content_text);
bool handle_event_menu(sfRenderWindow *window);
int start_menu(sfRenderWindow *window, struct game_object_s **tab_bg);
void short_cut_btn(map_t *map, sfVector3f **d3_vector);
void display_background(sfRenderWindow *window, struct game_object_s **tab_bg);
struct game_object_s **all_struct_bg(void);
sfText *create_text(char *str, sfColor color, int scale, sfVector2f pos);
void is_already_save(map_t map, sfVector3f **d3_vector);
float **fill_map_3D(int raw, int col);
char *get_content_file(char *filepath);
float **load_map(char *filepath);
char **str_to_word_array(char *str, char separator);
void display_size(map_t map, sfRenderWindow *window);
void resize_tool(map_t *map);
void lock_resize(map_t *map, sfVector3f **d3_vector);
int get_nb_file(char *filepath);
char *concat_nb_n_path(char *path_1, int nb, char *path_2);
char *my_revstr(char *str);
char *int_to_str(int nb);
char *my_strcpy(char *dest, char *src, int j);
int nb_dig_int(int nb);
char *get_content_file(char *filepath);
void hover_btn(button_t *btn, sfRenderWindow *window, int nb, \
int hover_height);
char *float_to_str(float nb);
int my_strlen(char *str);
void display_error(char *str);
void click_btn(button_t *btn, sfRenderWindow *window, map_t *map, \
sfVector3f **d3_vector);
void display_btn(button_t *btn, int nb, sfRenderWindow *window);
button_t *set_all_btn(void);
void save(map_t *map, sfVector3f **d3_vector);
void reset_map(map_t *map, sfVector3f **d3_vector);
banner_t fill_banner(void);
void create_lake(sfVector3f **d3_vector, map_t *map, sfRenderWindow *window);
void create_mount(sfVector3f **d3_vector, map_t *map, sfRenderWindow *window);
void handle_event(map_t *map, sfRenderWindow *window);
void key_pressed(map_t *map);
void rotate_x(sfVector3f **d3_vector, float teta);
sfVector2f **calcul_2d(sfVector3f **vector, map_t map);
sfVector3f ***init(sfVector3f ***d3_vector, float **matrix);
void draw_2d_map(sfRenderWindow *window, sfVector2f **d2_vector, \
sfVector3f **d3_vector, map_t map);
void close_window(sfRenderWindow *window, sfEvent event);
sfRenderWindow *handle_window(void);
void project_iso_point(sfVector3f vector, sfVector2f *d2_point, map_t map);
void help(void);
float my_getnbr_float(char *str);
void set_pos_btn(int i, float *pos_x, float *pos_y);
sfText **set_all_text(int nb_file);
void display_all_text(sfText **text, sfRenderWindow *window);
void main_display(sfRenderWindow *window, banner_t banner, \
map_t map, button_t *array_btn);
void starting(sfRenderWindow *window, struct game_object_s **tab_bg, \
float **matrix, sfVector3f **d3_vector);
void key_pressed_move_y(map_t *map);
void key_zoom(map_t *map);

#endif /* MY_WORLD_H_ */
