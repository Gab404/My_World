/*
** EPITECH PROJECT, 2022
** music.c
** File description:
** music
*/

#include "struct.h"
#include "my_world.h"

sfSound *set_music(sfSoundBuffer *buffer, float volume)
{
    sfSound *music = sfSound_create();

    sfSound_setBuffer(music, buffer);
    sfSound_setVolume(music, volume);

    return music;
}

sfSound *set_my_sound(sfSoundBuffer **buffer)
{
    sfSound *music;

    buffer[0] = sfSoundBuffer_createFromFile("./assets/saving.ogg");
    music = set_music(buffer[0], 50);

    return music;
}

void music_destroy(sfSound *music, sfSoundBuffer **buffer)
{
    sfSound_destroy(music);
    sfSoundBuffer_destroy(buffer[0]);

    return;
}

void play_saving_song(sfSound *sound, map_t map, bool *already_played)
{
    if (map.already_save && *already_played == false) {
        sfSound_play(sound);
        *already_played = true;
    } else if (map.already_save == false)
        *already_played = false;

    return;
}

sfMusic *set_music_back(void)
{
    sfMusic *music = sfMusic_createFromFile("./assets/background.ogg");
    sfMusic_setVolume(music, 50);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);

    return music;
}
