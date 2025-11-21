#include <stdio.h>
#include <unistd.h>



int main(int argc, char* argv[])
{
    int rc = fork();

    if(rc<0){
        printf("Fork failed!\n");
    }else if(rc==0){
        printf("Hello\n");
    }else{
        wait(NULL);
        printf("goodbye!\n");
    }

    return 0;
}