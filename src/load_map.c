/*
** EPITECH PROJECT, 2022
** load_map.c
** File description:
** load_map
*/

#include "struct.h"
#include "my_world.h"

int get_nb_point(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        i++;
    }

    return i - 1;
}

int get_max_col(char *buffer)
{
    int i = 0;
    int col = 0;

    while (buffer[i] != '\n') {
        if (buffer[i] == ' ')
            col++;
        i++;
    }

    return col;
}

float my_getnbr(char *str)
{
    float neg = 1;
    int value_0 = 48;
    float result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' || str[i] == '+') {
            neg = neg * -1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10;
            result += (str[i] - value_0);
        } else {
            return neg * result;
        }
    }
    return neg * result;
}

void fill_matrix(float **matrix, char **all_point, int max_col, int nb_raw)
{
    int col = 0;
    int matrix_raw = 0;

    for (int i = 0; matrix_raw < nb_raw; i++) {
        if (col == max_col) {
            col = 0;
            matrix_raw++;
            matrix[matrix_raw] = malloc(sizeof(float) * max_col);
        }
        if (all_point[i][0] == '0') {
            matrix[matrix_raw][col] = 0.0;
            matrix[matrix_raw][col] = my_getnbr(all_point[i]);
            col++;
        } else {
            matrix[matrix_raw][col] = my_getnbr(all_point[i]);
            matrix[matrix_raw][col] /= 100;
            col++;
        }
    }
}

float **load_map(char *filepath)
{
    char *buffer = get_content_file(filepath);
    char **all_point = str_to_word_array(buffer, ' ');
    int max_col = get_max_col(buffer);
    int nb_raw = get_nb_point(all_point) / max_col;
    float **matrix = malloc(sizeof(float *) * (nb_raw + 1));

    matrix[nb_raw] = NULL;
    matrix[0] = malloc(sizeof(float) * max_col);
    fill_matrix(matrix, all_point, max_col, nb_raw);
    return matrix;
}