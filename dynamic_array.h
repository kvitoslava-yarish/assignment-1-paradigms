#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct {
    char **array;
    int size;
    int capacity;
} dynamic_array;

dynamic_array* create_array(int initial_capacity);
void insert_line(dynamic_array *container, char *line);
void free_array(dynamic_array *container);

#endif
