#include <stdio.h>
#include <stdlib.h>
#include "builtin.h"
#include "help.h"

// The Main File Strives To Be as Minimalistic and Uncluttered as Possible.
void interactive_mode(char *commands){
    printf("myshell> ");
    scanf("%s", commands);
}


int main(int argc, char **argv){
    /*
    printf("%d \n", argc);
    getCLargs(argv,argc);
    help();  */
    int p = special_characters("pizz|pie");
    printf("%d",p);
    /*
    while(1){
        char input[256];
        if (argc < 2 ){ interactive_mode(input);} 
        else{ getCLargs(argv, argc);}


    }   
    */ 
    dir();
    return 0;
}