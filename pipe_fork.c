#import "pipe_fork.h"
#include <sys⁄wait.h>
#include <unistd.h>
#include <stdio.h>

// not built in but no special commands
void simple_fork(char **commands){
    int pid = fork();
    if (pid == -1){
        printf("Forking Failure");
        return;
        }
    if (pid == 0 ){ //child
        execvp(commands[0], commands);
        }
    //waits for child to finish
    wait (3);
}

void pipe(){

}
void redirection(){

}