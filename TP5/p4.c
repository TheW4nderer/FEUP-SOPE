#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
#include<sys/types.h> 
#define MAXLINE 1000  



int main(int argc, char *argv[]) {
    
    if (argc != 3) {
        printf("Usage: %s dir arg\n",argv[0]); 
        exit(1); 
    }

    int fd[2];
    pipe(fd);
    
    pid_t pid;
    pid = fork();

    if (pid > 0){   //pai - ls Execution
        close(fd[0]);
        dup2(fd[1],STDOUT_FILENO);
        execlp("ls", "ls", argv[1],"-laR",NULL);
    }
    else if (pid == 0){  //filho - Cria o novo fork
        close(fd[1]);
        int fd2[2];
        pipe(fd2);

        pid_t pid2;
        pid2 = fork();

        if (pid2 > 0){  //grep Execution
            close(fd2[0]);
            dup2(fd[0],STDIN_FILENO);
            dup2(fd[1],STDOUT_FILENO);
            execlp("grep","grep",argv[2],NULL);
        }
        else if (pid2 == 0){    //sort Execution
            close(fd2[1]);
            dup2(fd2[0],STDIN_FILENO);
            execlp("sort","sort",NULL);
        }
    }
    
    return 0;
}