#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "builtin.h"
#include "help.h"

// The Main File Strives To Be as Minimalistic and Uncluttered as Possible.
void interactive_mode(char commands[]){
    printf("myshell> ");
    scanf(" %[^\n]", commands);
    return;
}


int main(int argc, char **argv, char **envp){
    int builtin;
    int special;
    int batch_mode = 0;
 
    
    while(1){
        char input[256];
        if (argc < 2 ){ 
            interactive_mode(input);
            } 
        else{ 
            batch_read(argv, input);
            batch_mode = 1;
            }
        // in case anything goes wrong on the way
        if(input == 0 || input == NULL || input == '\0'){
            printf("error");
        }
        builtin = predefined(input);
        special = special_characters(input);
        char input_copy[256];
        strcpy(input_copy,input);
        char **tokens= malloc(10 * sizeof(char *));
        tokenize(input_copy, tokens);
        int i = 0;
        while (i<2){
            printf( "%s \n", tokens[i]);
            i++;
        }

        // call predefined functions with no redirection
        if (builtin == 1  && special == 0){
            printf("predefined \n");
            char **input_pointer = tokens;
            int change_directory = (strncmp(tokens[0],"cd",strlen("cd")) == 0); // (tokens[0] == "cd");
            int call_echo = (strncmp(tokens[0],"echo",strlen("echo")) == 0 );
            int call_environ = (strncmp(tokens[0],"environ",strlen("environ")) == 0);
            if (change_directory){
                cd(tokens[1]);
            }if(call_echo){
                echo(input);
                strcpy(input,"");
            }if(call_environ){
                environ(envp);
            }else{
                run_builtin(tokens[0]);
            }
        }
        //simple command but not builtin
        if (builtin == 0 && special == 0){
            simple_fork(tokens[0],tokens);

        }
        //contains odd characters we must account for but also builtin
        if(special == 1 && builtin == 1 ){
            
        }
        // if you reach the end of the program and are in batch mode you finished
    if(batch_mode){
        quit();
    }

    } 
    
 return 0;
}
