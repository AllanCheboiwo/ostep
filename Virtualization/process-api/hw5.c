#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc,  char * argv[])
{
    int rc = fork();

    if(rc<0){
        perror("Fork syscall failed\n");
    }else if(rc==0){
        pid_t check = wait(NULL);
        printf("Je suis le enfant\n");
        printf("%d,%d\n",check,getpid());
    }else{

        printf("Je suis le parent\n");
        printf("pARENT: %d\n",getpid());

    }

    return 0;
}