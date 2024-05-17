#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dynamic_array.h"

char* get_text_input(void);
void append_text(void);
void start_new_line(void);
void save_text_to_file(void);
// void save_text_to_file(void);
// void load_from_file(void);
int first_input = 1;
dynamic_array* d_array;

int main() {
    fflush(stdin);
    d_array = create_dynamic_array(10 * sizeof(char*));
    while(1)
    {
        printf("\nChoose action \n 1 - Append text \n 2 - Start new line \n 3 - Load to file \n 4 - Load from file \n 5 - Display text to console \n 6 - Paste at index \n 7 - Search occurences of a substring\n");
        int choice;
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
            case 1:
            append_text();
            continue;
            case 2:
            start_new_line();
            continue;
            case 3:
            save_text_to_file();
            continue;
            case 4:
            continue;
            case 5:
            print_array(d_array);
            continue;
            case 6:
            case 7:
            default:
            printf("%s", "enter proper command");
        }
    }
    
    
}

char* get_text_input(void)
{
    int size = 10;
    char* text;
    text = (char*)malloc(size * sizeof(char));
    char symbol;
    symbol = getchar();
    int index = 0;
    while(symbol != '\n')
    {
        if(index > size / sizeof(char) - 1)
        {
            size = size * 2;
            text = (char*)realloc(text, size);
        }
        text[index] = symbol;
        index++;
        symbol = getchar();

    }
    text[index] = '\0';
    return text;
}


void append_text(void)
{
    printf("%s", "Enter text to append: ");
    append_to_line(d_array, get_text_input());
}


void start_new_line(void)
{
    insert_line(d_array);
}

void save_text_to_file(void)
{
    printf("Enter the file name for saving:");
    FILE * file;
    char* file_path;
    file_path = get_text_input();
    file = fopen(file_path, "a");
    if(file == NULL) 
    {
        printf("Not able to open the file.");
        return;
    }
    for(int i = 0; i < d_array -> size; i++)
    {
        fprintf(file, "%s\n", d_array->array[i]);
    }
    fclose(file);
    printf(" Text has been saved successfully");
}
/*
void load_from_file(void)
{
    printf("Enter the file name to load from:");
    FILE * file;
    char* file_path;
    file_path = get_text_input();
    file = fopen(file_path, "r");

    if(file != NULL) 
    {
        char text[100];
        while(fgets(text, 100, file)) 
        {
            append_text(text);
            text[0] = '\0';
        }
    }
     
    else 
    {
        printf("Not able to open the file.");
    }

    fclose(file); 
}
*/