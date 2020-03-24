#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


void sigchld_handler(int signo) {   //5b)
    printf("Entering SIGCHLD handler ...\n");   
    pid_t pid;
    int status;
    while ( (pid = waitpid(-1,&status,WNOHANG)) > 0)
        printf("PARENT: child with PID=%d terminated with exit code %d\n",pid,WEXITSTATUS(status));   
    printf("Exiting SIGCHLD handler ...\n");  
}



int main(void) {  
    pid_t pid;   
    int i, n, status;
    
    struct sigaction chld_action;
    //chld_action.sa_handler = SIG_IGN; //5a)       
    chld_action.sa_handler = sigchld_handler;
    chld_action.sa_flags = 0;
    sigemptyset( &(chld_action.sa_mask) );
        
    if (sigaction(SIGCHLD, &chld_action,0) < 0){
        fprintf(stderr,"Unable to install SIGCHLD handler\n");     
        exit(1); 
    }

    for (i=1; i<=10; i++) {     
        pid=fork(); 
        if (pid == 0){       
            printf("CHILD no. %d (PID=%d) working ... \n",i,getpid());       
            sleep(15); // child working ...       
            printf("CHILD no. %d (PID=%d) exiting ... \n",i,getpid());        
            exit(0);     
        }   
    }   
    
    for (i=1 ;i<=4; i++ ) {  
        printf("PID = %d\n",getpid());    
        printf("PARENT: working hard (task no. %d) ...\n",i);      
        n=20; while((n=sleep(n))!=0);     
        printf("PARENT: end of task no. %d\n",i);     
        printf("PARENT: waiting for child no. %d ...\n",i);     
        //pid=wait(&status); 
        if (pid != -1)       
            printf("PARENT: child with PID=%d terminated with exit code %d\n",pid,WEXITSTATUS(status)); 
    }   
    
    exit(0); 
}