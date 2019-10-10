#include <stdio.h>
#include <stdlib.h>
#include "builtin.h"
#include "help.h"

// The Main File Strives To Be as Minimalistic and Uncluttered as Possible.
void interactive_mode(char commands[]){
    printf("myshell> ");
    scanf("%s", commands);
}


int main(int argc, char **argv){
    int builtin;
    int special;
    while(1){
        char input[256];
        if (argc < 2 ){ interactive_mode(input);} 
        else{ getCLargs(argv, argc);}
        builtin = predefined(input);
        special = special_characters(input);
        char *tokens[16];
        tokenize(input, tokens );
        printf("%s \n %d \n   %d \n", input,builtin,special);
        

        // call predefined functions with no redirection
        if (builtin == 1  && special== 0){
            if (tokens[0] == "cd"){
              //  token = strtok(NULL, ' ');
                cd(tokens[1]);
            }else{
                run_builtin(tokens[0]);
            }
        }
        //simple command but not builtin
        if (builtin == 0 && special == 0){
            printf("not builtin\n");

        }


    }  
    
    return 0;
}