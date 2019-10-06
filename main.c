#include <stdio.h>
#include "builtin.h"

void interactive_mode(char *commands){
    printf("myshell>");
    scanf("%s", commands);
}


int main(int argc, char **argv){
    /*
    while(1){
        if (argc == 0){
            char future_input[256];
            interactive_mode(future_input);
            }
    
    return 0;
    }
    */
    poop();
}