// PROGRAMA p1.c 
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int global=1; 

int main(void) {   
    int local = 2;   
    if(fork() > 0) {   //Processo pai  
        printf("PID = %d; PPID = %d\n", getpid(), getppid());     
        global++;     
        local--;
    }   else {          //Processo filho    
        printf("PID = %d; PPID = %d\n", getpid(), getppid());     
        global--;     
        local++;   
    }   
    printf("PID = %d - global = %d ; local = %d\n", getpid(), global, local);   
    return 0; 
}


/*

1a) O PPID do processo-filho, é igual ao PID do processo original (processo-pai)

1b) Ao correr o programa várias vezes verifica-se que o PID dos
    processos altera-se.
*/