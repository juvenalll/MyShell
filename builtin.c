
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
//#include <unistd.h>
#include "builtin.h"
// C File Where I Define All Prebuilt 

extern char **environment_pointer;
void cd(char *location){
 //If given no argument cd takes you to the root else it takes you to the desired subfolder
    if (location == NULL){
        chdir("~");
        return;
    }
    char current[256];
    getcwd(current,256);
    char subFolder[1024];
    snprintf(subFolder, sizeof(subFolder), "%s: %s: %s", current , "/", location);
    chdir(subFolder);
    if(chdir(subFolder)== -1){printf("This folder may not exist! \n");}
}

void clr(){
    int clear_count = 0;
    while(clear_count< 50){
        printf("\n");
        clear_count+=1;
    }
}

void dir(){
    char current[1024];
    getcwd(current,1024);
    DIR * directory_path = opendir(current);
    if (directory_path == NULL){
        printf("Something went Wrong!");
        return;
        }
    struct dirent *current_entry;
    
    while((current_entry = readdir(directory_path)) != NULL){
            if(strcmp(current_entry->d_name,".") != 0  && strcmp(current_entry->d_name,"..") != 0 ){
                printf("%s \n",current_entry->d_name);
            }
    }
    closedir(directory_path);
    return;
}
void echo(char *screen_text){
    for (int i = 4 ; screen_text[i] != '\0' ; i++){
         printf("%c",screen_text[i]);
    }
    printf("\n");
    return;
}
void environ(char **environment_pointer){
    int i = 0;
    while(environment_pointer[i]){
        printf("%s \n", environment_pointer[i]);
        i++;
    }
    return;
}

void help(){
    printf(" MyShell \n Information to help you get on your way... \n \n Builtin Functions : \n \n cd \tclr \tdir \techo \tenviron \thelp \tpause \tquit \n ");
}

void pause(){
    printf("User Paused MyShell press any letter followed by Enter key to resume!\n");
    char Enter;
    scanf(" %[\n]", &Enter);
    printf("Welcome Back Brother! \n");
    

}
void quit(){
    printf(" ~ Thank You For Using MyShell ~ \n");
    exit(1);
}
