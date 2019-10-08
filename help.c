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

