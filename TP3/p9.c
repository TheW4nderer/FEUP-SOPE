// PROGRAMA p9.c 
#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 
#include <stdlib.h> 

int main(int argc, char *argv[], char *envp[]) 
{    
    pid_t pid, childpid;
    int status;    
    if (argc != 2) {      
        printf("usage: %s dirname\n",argv[0]);      
        exit(1);    
    }    
    
    pid=fork();    
    if (pid > 0){      //Processo-pai

        printf("My child is going to execute command\"ls -laR %s\"\n", argv[1]); 
        childpid = wait(&status);     //9a) 

        if (WIFEXITED(status))      //9b)
            printf("Child PID %d: Normal termination | Exit status = %d\n", childpid, WEXITSTATUS(status));

        else if (WIFSIGNALED(status))
            printf("Child PID %d: Abnormal termination | Exit status = %d | Signal number = %d\n", childpid, WEXITSTATUS(status), WTERMSIG(status));

    }
    
    else if (pid == 0){         //Processo-filho 
        
        execlp("ls","ls", "-laR", argv[1], NULL);
        printf("Command not executed !\n");      
        exit(1);    
    }    
    exit(0); 
}