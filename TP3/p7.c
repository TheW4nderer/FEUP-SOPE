#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h> 


int main(int argc, char *argv[]) 
{    
    char prog[20];    
    sprintf(prog,"%s.c",argv[1]);    
    execlp("gcc","gcc",prog,"-Wall","-o",argv[1],NULL);    
    printf("Can't execute gcc!\n");    
    exit(1); 
}



/*

7. O programa substitui o processo atual por uma chamada gcc, que cria um
executavel para o ficheiro passado em argv[1]. Se execlp for executado com sucesso
a chamada printf não chega a ser executada, porque o processo é substituído anteriormente.

*/