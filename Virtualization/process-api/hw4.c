#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int rc = fork();    
    if(rc<0){
        perror("fork failed!");
    }else if(rc==0){
        char * myargs[2];
        myargs[0] = strdup("ls");
        myargs[1] = NULL;
        execvp(myargs[0],myargs);

        perror("execvp failed!\n");
        exit(1);
    }else{
        wait(NULL);
    }
    return 0;
}