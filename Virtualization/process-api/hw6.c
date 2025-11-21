#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc,  char * argv[])
{
    int rc = fork();

    if(rc<0){
        perror("Fork syscall failed\n");
    }else if(rc==0){
        
        printf("Je suis le enfant\n");
        printf("%d\n",getpid());
    }else{
        int status;
        pid_t check = waitpid(getpid(),&status,WNOHANG);
        printf("Je suis le parent\n");
        printf("Parent pid: %d, status: %d, wait return: %d\n",getpid(),status,check);

    }

    return 0;
}