#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {  

    pid_t pid;   
    int i, n, status;   
    for (i=1; i<=3; i++) {     
        pid=fork(); 
        if (pid == 0){       
            printf("CHILD no. %d (PID=%d) working ... \n",i,getpid());       
            sleep(i*7); // child working ...       
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
        while ( (pid = waitpid(-1,&status,WNOHANG)) > 0) //4b)
            printf("PARENT: child with PID=%d terminated with exit code %d\n",pid,WEXITSTATUS(status));   
    }   
    
    exit(0); 
}


/*
4a) A cada chamada wait() é libertado 1 processo-filho zombie, no entanto, esta so acontece
a cada 20s, o que causa a existência de vários processos zombie que não são libertados
imediatamente.

4c) CTRL-C -> Todos os processos param
    SIGINT no processo pai -> Apenas o processo pai para, os processos filho
continuam a sua execução até saírem. Estes não criam processos zombie porque o
processo pai já terminou

*/