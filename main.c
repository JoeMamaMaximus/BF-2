#include "main.h"
int main(int argc, char const *argv[])
{
    char * text = malloc(1024*sizeof(char));
        FILE* ptr;
    char ch;
    ptr = fopen(argv[1], "r");

    int term = 0;
    do {
        ch = fgetc(ptr);
        text[term] = ch;
        term++;
    } while (ch != EOF);
    text[term-1] = '\0';
    
    printf("%s\n", text);
    return 0;
}
