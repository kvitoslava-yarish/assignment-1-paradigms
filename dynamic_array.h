#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **array;
    int size;
    int capacity;
} dynamic_array;

dynamic_array* create_dynamic_array(int initial_capacity);
void insert_line(dynamic_array *d_array);
void append_to_line(dynamic_array *d_array, char *text);
void print_array(dynamic_array *d_array);

#endif