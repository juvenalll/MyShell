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
    int builtin;
    int special;
    char *cd= "cd";
    run_builtin(cd);
   
    while(1){
        char input[256];
        if (argc < 2 ){ interactive_mode(input);} 
        else{ getCLargs(argv, argc);}
        builtin = predefined(input);
        special = special_characters(input);
        char* token = strtok(input, " ");

        if (builtin && !(special_characters)){
            // call predefined functions
        }


    }  
    
    return 0;
}