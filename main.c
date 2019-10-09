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
    
    char *words[6]= {"Yachty"};
    char test[] = "get off me in the club";
    printf("%s\n", test);
    tokenize(test, words);
    for( int i = 0; i < 6; i++){
        printf("%s \n",words[i]);
        }
   /*
    while(1){
        char input[256];
        if (argc < 2 ){ interactive_mode(input);} 
        else{ getCLargs(argv, argc);}
        builtin = predefined(input);
        special = special_characters(input);
       // char *tokens[16] = tokenize(input);
        
        

        // call predefined functions with no redirection
        if (builtin && !(special_characters)){
            if (tokens[0] == "cd"){
              //  token = strtok(NULL, ' ');
                cd(tokens[1]);
            }else{
                run_builtin(tokens[0]);
            }
        }
        //simple command but not builtin
        if (!(builtin) && !(special_characters)){

        }


    }  */ 
    
    return 0;
}