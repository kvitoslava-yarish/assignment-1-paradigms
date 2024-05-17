#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"

dynamic_array* create_dynamic_array(int initial_capacity)
{
    dynamic_array *d_array; 
    d_array = (dynamic_array*)malloc(sizeof(dynamic_array)); 
    if(!d_array) 
    { 
        printf("Memory Allocation Failed\n"); 
        exit(0); 
    } 
  
    d_array->size = 0; 
    d_array->capacity = initial_capacity; 
    d_array->array = (char**)malloc(initial_capacity * sizeof(char));
    if (!d_array->array)
    { 
        printf("Memory Allocation Failed\n"); 
        exit(0); 
    } 
    return d_array;
}

void insert_line(dynamic_array *d_array)
{
    int initial_line_size = 10;
    if(d_array->size == d_array -> capacity)
    {
        d_array -> capacity  = d_array -> capacity * 2;
        d_array ->array = (char **)realloc(d_array ->array, d_array -> capacity * sizeof(char *));
    }

    d_array->array[d_array->size] = (char *)malloc(initial_line_size * sizeof(char));
    if (!d_array->array[d_array->size]) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    d_array->size++;
}

void append_to_line(dynamic_array *d_array, char *text)
{
    d_array ->array[d_array ->size] = (char *) realloc(d_array ->array[d_array ->size],sizeof(d_array ->array[d_array ->size]) + sizeof(text));
    strcat(d_array->array[d_array ->size],text);
}

void print_array(dynamic_array *d_array)
{ 
    for(int i = 0; i < d_array -> size; i++)
    {
        printf("%s\n", d_array -> array[i]);
    }

}