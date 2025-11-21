#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int pipefd[2];
    pid_t child1, child2;

    if(pipe(pipefd)==-1)
    {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    if((child1=fork())<0){
        perror("fork failed");
        exit(EXIT_FAILURE);
    }else if(child1==0){
        close(pipefd[0]);
        char *s = "My name is Pumba!!!!!\n";
        write(pipefd[1],s,strlen(s));
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    }

    if((child2=fork())<0){
        perror("fork failed");
        exit(EXIT_FAILURE);
    }else if(child2==0){
        close(pipefd[1]);
        int count,c;
        while((count=read(pipefd[0],&c,1))>0)
            write(STDOUT_FILENO,&c,1);
        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    }

    close(pipefd[0]);
    close(pipefd[1]);
    
    wait(NULL);
    wait(NULL);
    return 0;
}