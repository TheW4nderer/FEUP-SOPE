// PROGRAMA p10.c 
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <fcntl.h>

int main(int argc, char *argv[], char *envp[]) 
{    
    pid_t pid;    
    int fdes;
    if (argc != 2 && argc != 3) {      
        printf("usage: %s dirname filename(optional)\n",argv[0]);      
        exit(1);    
    }    
    
    pid=fork();    

    if (pid > 0)      //Processo-pai
        printf("My child is going to execute command\"ls -laR %s\"\n", argv[1]);    
    
    else if (pid == 0){         //Processo-filho 
        if (argc ==3){
            fdes = open(argv[2], O_WRONLY | O_CREAT, 0644);
            dup2(fdes, STDOUT_FILENO);  //Redirecting the output
            close(fdes);
        }
        execlp("ls","ls", "-laR", argv[1], NULL);

        printf("Command not executed !\n");      
        exit(1);    
    }    
    exit(0); 
}