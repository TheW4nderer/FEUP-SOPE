// PROGRAMA p01a.c 
#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 

void sigint_handler(int signo) {   
    printf("In SIGINT handler ...\n"); 
} 

void sigusr_handler(int signo) {   
    printf("In SIGUSR1 handler ...\n"); 
}
    
int main(void) {   
    if (signal(SIGUSR1,SIG_IGN) < 0)   {
        fprintf(stderr,"Unable to install SIGUSR handler\n");     
        exit(1);
    }

    if (signal(SIGINT, SIG_IGN) < 0){
        fprintf(stderr, "Unable to install SIGINT handler\n");
        exit(2);
    }

    if ((signal(SIGTERM, sigint_handler) == SIG_ERR) || 
        (signal(SIGUSR1, SIG_IGN) == SIG_ERR) ||
        (signal(SIGUSR2, SIG_IGN) == SIG_ERR)) {
        
        fprintf(stderr,"Unable to ignore the specified signals.\n");
    }
    
    printf("Sleeping for 30 seconds ...\n"); 
    
    int sleep_return = sleep(30);
    
    while (sleep_return != 0) {
        sleep_return = sleep(sleep_return);
    }  

    printf("Waking up ...\n");   
    
    exit(0); 
}