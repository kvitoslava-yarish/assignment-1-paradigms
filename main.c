#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* get_text_input(void);
void resize_text(int lenght);
void append_text(char *);
void start_new_line(void);
void save_text_to_file(void);
void load_from_file(void);
int text_size;
int storage_left;
char* text;
int first_input = 1;

int main() {
    text_size = 100;
    storage_left = 100;
    while(1)
    {
        printf("\nChoose action \n 1 - Append text \n 2 - Start new line \n 3 - Load to file \n 4 - Load from file \n 5 - Display text to console \n 6 - Paste at index \n 7 - Search occurences of a substring\n");
        int choice;
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
            case 1:
            printf("%s", "Enter text to append: ");
            append_text(get_text_input());
            continue;
            case 2:
            start_new_line();
            continue;
            case 3:
            save_text_to_file();
            continue;
            case 4:
            load_from_file();
            continue;
            case 5:
            printf("%s", text);
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

void resize_text_storage(int lenght)
{
    while(lenght * sizeof(char) > storage_left)
    {
        storage_left = storage_left + text_size;
        text_size = text_size * 2;
        text = (char*)realloc(text, text_size);
    }
    storage_left -= lenght * sizeof(char);
}

void append_text(char* entered_text)
{
    if (first_input) {
        text_size = strlen(entered_text) + 1;
        text = (char *)malloc(text_size * sizeof(char));
        if (text == NULL) {
            perror("Unable to allocate memory");
            exit(EXIT_FAILURE);
        }
        strcpy(text, entered_text);
        first_input = 0;
    } 
    else 
    {
        resize_text_storage(strlen(entered_text) + 1);
        strcat(text, entered_text);
    }
}

void start_new_line(void)
{
    resize_text_storage(strlen("\n"));
    strcat(text, "\n");
    printf("%s", "New line added");
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
    fprintf(file, text);
    fclose(file);
    printf(" Text has been saved successfully");
}

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