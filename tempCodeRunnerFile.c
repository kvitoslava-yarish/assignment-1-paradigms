#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* get_text_input(void);
void resize_text(int lenght);
void append_text(void);
int text_size;
int storage_left;
char* text;

int main() {
    text_size = 100;
    storage_left = 100;
    text = (char*)malloc(text_size);

    printf("Choose action \n 1 - Append text \n 2 - Start new line \n 3 - Load from file \n 4 - Load to file \n 5 - Display text to console \n 6 - Paste at index \n 7 - Search occurences of a substring\n");
    int choice;
    scanf("%d", &choice);
    getchar();
    switch(choice)
    {
        case 1:
        append_text();
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        default:
        return -1;
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
    getchar();
    text[index] = '\0';
    return text;
}
void resize_text_storage(int lenght)
{
    if(lenght * sizeof(char) > storage_left)
    {
        storage_left = storage_left + text_size;
        text_size = text_size * 2;
        text = (char*)realloc(text, text_size);
    }
    storage_left -= lenght * sizeof(char);
}
void append_text(void)
{
    printf("%s", "Enter text to append");
    char* entered_text = get_text_input();
    resize_text_storage(strlen(entered_text));
    strcat(text, entered_text);
    printf("%s", text);
}