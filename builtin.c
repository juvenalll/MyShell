
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

void pause(){
    printf("User Paused MyShell press Enter key to resume!\n");
    char Enter;
    while(Enter != '\n'){
        scanf("%c",&Enter);
    }
    printf("Welcome Back Brother! \n");
    

}
void quit(){
    printf(" ~ Thank You For Using MyShell ~ \n");
    exit(1);
}