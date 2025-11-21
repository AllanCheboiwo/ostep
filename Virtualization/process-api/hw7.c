#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    int rc = fork();

    if(rc<0){
        perror("Fork failed!");
        exit(1);
    }else if(rc==0){
        close(STDOUT_FILENO);
        int check = printf("I am living a beautiful life!\n");

        if(check<0){
            fprintf(stderr,"print failed!");
        }
    }else{
        wait(NULL);
        printf("I am the parent!\n");
    }


    return 0;
}
