#include "header/main.h"
int main(int argc, char const *argv[])
{
    while (argc*1 == 1)
    {
        printf("Syntax: bf++2 [filename] [mode: 1 or 0: show input file contents: defaults to 0]\n"); exit(0);
    }
    
    int memory[4096];
    
    char* text = malloc(4096*sizeof(char));
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
    }
    
    char** comprehensive = str_split(text, ' ');
    int* memoryPtr = memory;
    char buf[5];

    for (int i = 0; i < 1024; i++) {
        strcpy(buf, comprehensive[i]);
        if (isdigit(buf[0])){
            *memoryPtr = atoi(buf);
        }else if (strcmp(buf, "exit") == 0) exit(0);
        else if (strcmp(buf, "print") == 0) printf("%c", *memoryPtr);
        else if (strcmp(buf, "display") == 0) printf("%i", *memoryPtr);
        else if (strcmp(buf, "next") == 0) memoryPtr++;
        else if (strcmp(buf, "back") == 0) memoryPtr--;
        else if (strcmp(buf, "add") == 0) {
            memoryPtr--;
            int temp = *memoryPtr;
            memoryPtr++;
            temp += *memoryPtr;
            memoryPtr--;
            *memoryPtr = temp;
        }else if (strcmp(buf, "sub") == 0) {
            memoryPtr--;
            int temp = *memoryPtr;
            memoryPtr++;
            temp -= *memoryPtr;
            memoryPtr--;
            *memoryPtr = temp;
        }
        else continue;
    }

    return 0;
}
