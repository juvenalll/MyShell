
#include <stdio.h>
#include <stdlib.h>
#include "builtin.h"
// C File Where I Define All Prebuilt Functions 
void clr(){
    int clear_count = 0;
    while(clear_count< 25){
        printf("\n");
        clear_count+=1;
    }
}
void quit(){
    printf(" ~Thank You For Using MyShell ~ \n");
    exit(1);
}