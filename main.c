#include "header/main.h"
int main(int argc, char const *argv[])
{
    while (argc*1 == 1)
    {
        printf("Syntax: bf++2 [filename] [mode: 1 or 0: show input file contents: defaults to 0]\n"); exit(0);
    }
    


    char* text = malloc(1024*sizeof(char));
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
    term = 0;
    

    if(argc == 3 && strcmp(argv[2], "1")==0) {
    printf("%s: %s\noutput->", argv[1], text);
    }else printf("output->");
    
    char** comprehensive = str_split(text, ' ');

    

    return 0;
}
