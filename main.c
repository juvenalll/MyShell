#include <stdio.h>
#include <stdlib.h>
#include "builtin.h"

void interactive_mode(char *commands){
    printf("myshell>");
    scanf("%s", commands);
}


int main(int argc, char **argv){
    printf("%d \n", argc);
    while(1){
        char interactive_input[256];
        if (argc < 2 ){ interactive_mode(interactive_input);} 
    
    }    
    return 0;
}