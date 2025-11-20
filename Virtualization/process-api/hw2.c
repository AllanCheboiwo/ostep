#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if(argc!=2){
        fprintf(stderr,"FORMAT: ./hw2.o filename\n");
        exit(1);
    }
    int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);

    if(fd<0){
        fprintf(stderr,"Failed to open ");
        exit(1);
    }

    int rc = fork();

    if(rc<0){
        fprintf(stderr,"fork failed\n");
        exit(1);
    }else if(rc==0){
        char child[] = "I am a child\n"; 
        int count = write(fd,child,strlen(child));
        if(count<0){
            fprintf(stderr,"write to %s failed!\n",argv[1]);
            exit(1);
        }
    }else{
        char parent[] = "I am the parent\n"; 
        int count = write(fd,parent,strlen(parent));
        if(count<0){
            fprintf(stderr,"write to %s failed!\n",argv[1]);
            exit(1);
        }
        wait(NULL);
        int c;
        lseek(fd,0,SEEK_SET);
        while((count = read(fd,&c,1)))
            putchar(c);
    }

    return 0;
}