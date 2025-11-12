#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    printf("Hello (pid: %d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0 ){
        fprintf(stderr,"fork failed\n");
        exit(1);
    }else if(rc==0){
        //child process
        printf("Child (pid: %d)\n", (int) getpid());
    }else{
        printf("parent of %d (pid: %d)\n",rc,(int) getpid());
    }
    return 0;
}