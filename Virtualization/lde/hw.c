#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

double calculate_elapsed(struct timespec start, struct timespec end);

int main()
{
    double time[N], total = 0;
    struct timespec start, end;

    for (int i = 0; i < N; i++) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        getpid();
        clock_gettime(CLOCK_MONOTONIC, &end);
        
        time[i] = calculate_elapsed(start, end);
        total += time[i];
    }

    printf("The first ten samples of time in microseconds: \n");
    for(int i=0;i<10;i++)
    {
        printf(" %.3f ",time[i]*1e6);
    }

    printf("\nAverage getpid() syscall time: %.3f microseconds\n", 
           (total / N) * 1e6);

    return 0;
}

double calculate_elapsed(struct timespec start, struct timespec end)
{
    long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    
    if (nanoseconds < 0) {
        seconds--;
        nanoseconds += 1000000000L;
    }
    
    return seconds + nanoseconds * 1e-9;
}