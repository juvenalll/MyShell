#import "pipe_fork.h"
#include <unistd.h>
#include <stdio.h>
#define READ 0
#define WRITE 1 

// not built in but no special commands
void simple_fork(char *command, char **line){
    printf("entered simple fork \n");
    int pid = fork();
    if (pid == -1){
        printf("Forking Failure");
        return;
        }
        //child
    if (pid == 0 ){  
        printf("child  + command %s \n", command);
        execvp(command, line);}
    //waits for child to finish ... child should not reach this point
    wait (3);
}
/*
void piping_required(){
    int file_transfer[2];
    pid_t child1, child2;
    int status = pipe(file_transfer);
    if(status < 0){
        printf("Error \n");
    }

}
void redirection(){

}*/