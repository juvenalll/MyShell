#import "pipe_fork.h"
#include <unistd.h>
#include <stdio.h>

// not built in but no special commands
void simple_fork(char *command, char **line){
    int pid = fork();
    if (pid == -1){
        printf("Forking Failure");
        return;
        }
        //child
    if (pid == 0 ){ execvp(command, line);}
    //waits for child to finish an arbitrary amount ... child should not reach this point
    wait (3);
}
