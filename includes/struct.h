/*
** EPITECH PROJECT, 2021
** struct.h
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <stdbool.h>
    #include <SFML/Graphics.h>

typedef struct draw_t
{
    int pos;
    sfColor a;
}draw_t;

typedef struct map_t
{
    float zoom;
    float init_pos_x;
    float init_pos_y;
    float angle_y;
    bool key_left;
    bool key_right;
    bool mouse_left;
    bool mouse_right;
    float teta;
    int size_x;
    int size_y;
    bool btn_rotate;
    int nb_click;
    bool lock_resize;
    int size_tool;
    bool already_save;
    bool modif_map;
    sfVector3f **d3_vector;
    sfVector2f **map;
}map_t;

typedef struct banner_t
{
    sfText *title;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
}banner_t;

typedef struct button_t
{
    void (*pt_fct)(map_t *, sfVector3f **);
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    bool hover;
    sfText *help;
}button_t;

struct game_object_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
    sfTime time_anim;
    float sec;
    float velocity;
};

sfVector2f **calcul_2d(sfVector3f **vector, map_t map);


#endif /* STRUCT_H_ */
