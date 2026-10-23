#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    

    if(argc<2){
        return -1;
    }
    int size = atoi(argv[1]);

    if(size==0)
        return -1;
    size_t n = size*1024*1024;

    char *m= malloc(n);

    if(m==NULL)
        return -1;
    
    size_t i = 0;
    printf("pid: %d\n",getpid());
    while(i<n){
        m[i++]=0;
        if(i==n){
            i=0;
        }
    }
    
    return 0;
}