#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"


// A File Where All Custom Functions Go As To Not Make The Main File A Cluttered Mess
void getCLargs(char **CL, int arg_count){
    for(int i = 0 ; i <= arg_count-1 ;i++){ printf("%s\n", CL[i]); }   
}

// codeblock for figuring out if we can just run smoothly without worrying about pesky >,&,|
int special_characters(char *unprocessed_argument){
    char* search = strpbrk(unprocessed_argument, "><|&");
    if(search == NULL){
        return 0;
    }else{
        return 1;
    }
}

//determines whether or not the function is a builtin one or not
int predefined (char *unprocessed_argument){ 
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
    while(i < 9){
        char *char_point = strstr(unprocessed_argument,predefined[i]);
        if(char_point != NULL){
            return 1;
        }
        i+=1;
    }
    return 0;
}

