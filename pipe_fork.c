#import "pipe_fork.h"
#include <unistd.h>
#include <stdio.h>

// not built in but no special commands
void simple_fork(char **commands){
    int pid = fork();
    if (pid == -1){
        printf("Forking Failure");
        return;
        }
        //child
    if (pid == 0 ){  execvp(commands[0], commands);}
    //waits for child to finish ... child should not reach this point
    wait (3);
}

void piping_required(){

}
void redirection(){

}