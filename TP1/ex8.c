#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX
#include <sys/times.h>
#include <unistd.h>

int main(int argc, char **argv){
    clock_t start, end;   
    struct tms t;   
    long ticks;
    start = times(&t);  /* início da medição de tempo */   
    ticks = sysconf(_SC_CLK_TCK); 
    
    char *p;
    int n1, n2;

    errno = 0;
    long conv1 = strtol(argv[1], &p, 10);
    long conv2 = strtol(argv[2], &p, 10);

    // Check for errors: e.g., the string does not represent an integer
    // or the integer is larger than int
    if (errno != 0 || *p != '\0' || conv1 > INT_MAX || conv2 > INT_MAX) {
        printf("Argument given was not an integer!");
    } else {
        // No error
        n1 = conv1;
        n2 = conv2;  
    }

    srand(time(0));
    int num = -1;
    while (num != n2){
        num = (rand() % (n1 + 1)); 
        printf("%i\n",num);
    }
    
    printf("\nClock ticks per second: %ld\n", ticks); 

    end = times(&t);     /* fim da medição de tempo */   
    printf("Clock:                %4.2f s\n", (double)(end-start)/ticks);   
    printf("User time:            %4.2f s\n", (double)t.tms_utime/ticks);   
    printf("System time:          %4.2f s\n", (double)t.tms_stime/ticks);   
    
    return 0;


}