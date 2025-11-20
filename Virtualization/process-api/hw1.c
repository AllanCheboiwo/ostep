#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(int argc,char *argv[])
{   
    int x = 100;

    int rc = fork();

    if(rc<0){
        fprintf(stderr,"fork failed");
        exit(1);
    }else if(rc==0){
        x = 105;

    }else{
        wait(NULL);
        x = 110;
    }

    printf("Value of x is: %d\n",x);
    return 0;
}