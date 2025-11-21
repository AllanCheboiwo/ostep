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
        // char child[] = "I am a child\n"; 
        write(fd,"I ",2);
        write(fd,"am ",3);
        write(fd,"a ",2);
        write(fd,"child\n",6);

    }else{
        //char parent[] = "I am the parent\n"; 
        write(fd,"I ",2);
        write(fd,"am ",3);
        write(fd,"a ",2);
        write(fd,"parent\n",7);
        wait(NULL);
        int c,count;
        lseek(fd,0,SEEK_SET);
        while((count = read(fd,&c,1)))
            putchar(c);
    }

    return 0;
}