#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"
#include "builtin.h"


// A File Where All Custom Functions Go As To Not Make The Main File A Cluttered Mess
//reads from one batch file

void batch_read(char **command_line_args, char *output){
    FILE *file_pointer = fopen(command_line_args[1],"r");
    if (file_pointer == NULL){
        printf("not a valid file ! \n");
        return;
        }
    fgets(output, sizeof(output), file_pointer);
}

//  turns string of input into seperate words 
void tokenize (char *line, char **words){
    int i = 0;
    char *s = malloc(10 * sizeof(char*));
    strcpy(s,line);
    char* token = strtok(s, " ");
    while( token ){
        words[i] = token;
        //printf("%s toke\n",token);
        i++;
        token = strtok(NULL, " ");
    }
    words[i] = NULL;
    return;
    
  
}

// codeblock for figuring out if we can just run smoothly without worrying about pesky >,&,|
// 1 = contains  0= does not contain
int special_characters(char unprocessed_argument[]){
    char* search = strpbrk(unprocessed_argument, "><|&");
    if(search == NULL){
        return 0;
    }else{
        return 1;
    }
}

//determines whether or not the function is a builtin one or not
//1 = builtin        0 = not 
int predefined (char unprocessed_argument[]){ 
    char predefined[8][16];
    strcpy(predefined[0], "cd");
    strcpy(predefined[1], "clr");
    strcpy(predefined[2], "dir");
    strcpy(predefined[3], "echo");
    strcpy(predefined[4], "environ");
    strcpy(predefined[5], "help");
    strcpy(predefined[6], "pause");
    strcpy(predefined[7], "quit");
    int i = 0 ;
    while(i < 8){
        char *char_point = strstr(unprocessed_argument,predefined[i]);
        //printf("%d  %s \n ",i,char_point);
        if(char_point != NULL){ return 1;}
        i+=1;
    }

    return 0;
}

// runs a predefined function by getting the ascii value of the command except for cd
void run_builtin(char *single_command){
    int ascii_val = 0;
    char command[24];
    strcpy(command,single_command);
    int i= 0;
    while (i < strlen(command)){
        ascii_val += (int) command[i];
        i+=1;
    }
    printf("ASCII : %d \n",ascii_val);
    
    switch(ascii_val){
        case 321:
            clr();
            break;
        case 319:
            dir();
            break;
        case 415:
            echo();
            break;
        case 779:
            environ();
            break;
        case 425:
            help();
            break;
        case 542:
            pause();
            break;
        case 451:
            quit();
            break;
        default:
            printf("Error... call help for commands... \n");
            break;
    }
    
    
}
// check if any pipe business is occurring
/*
int pipe_check(char input[]){
    int pipes = 0;
    int i;
    int length = strlen(string);
    for (i = 0; i < length; i++){
        if (string[i] == '|'){pipes++; }
     }
    return pipes;
}

*/
