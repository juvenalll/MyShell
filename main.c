#include <stdio.h>
#include <stdlib.h>
#include "builtin.h"
#include "help.h"

// The Main File Strives To Be as Minimalistic and Uncluttered as Possible.
void interactive_mode(char *commands){
    printf("myshell>");
    scanf("%s", commands);
}


int main(int argc, char **argv){
    printf("%d \n", argc);
    getCLargs(argv,argc);
    help();
    /*
    while(1){
        char input[256];
        if (argc < 2 ){ interactive_mode(input);} 
        else{ getCLargs(argv, argc);}


    }   
    */ 
    return 0;
}