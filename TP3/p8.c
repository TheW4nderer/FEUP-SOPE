// PROGRAMA p8.c 
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 

int main(int argc, char *argv[], char *envp[]) 
{    
    pid_t pid;    
    if (argc != 2) {      
        printf("usage: %s dirname\n",argv[0]);      
        exit(1);    
    }    
    
    pid=fork();    
    if (pid > 0)      //Processo-pai
        printf("My child is going to execute command\"ls -laR %s\"\n", argv[1]);    
    
    else if (pid == 0){         //Processo-filho 
        
        //execlp("ls","ls", "-laR", argv[1], NULL);
        
        //execl("/bin/ls","/bin/ls", "-laR", argv[1], NULL); //8b)
        
        char* args[4];      
        args[0] = "ls";
        args[1] = "-laR";
        args[2] = argv[1];
        args[3] = NULL;
        
        //execvp("ls", args);           //8c)
        
        //execv("/bin/ls",args);        //8d)

        //execve("/bin/ls",args, envp);   //8e)


        printf("Command not executed !\n");      
        exit(1);    
    }    
    exit(0); 
}