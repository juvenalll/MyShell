#include <stdio.h>
#include <stdlib.h>
#include "help.h"
// A File Where All Custom Functions Go As To Not Make The Main File A Cluttered Mess
void getCLargs(char **CL, int arg_count){
    for(int i = 0 ; i <= arg_count-1 ;i++){ printf("%s\n", CL[i]); }   
}