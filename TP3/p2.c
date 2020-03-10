// PROGRAMA p2.c 
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {  
    
    //write(STDOUT_FILENO,"1",1);  
    
    //2c)
    //printf("1");

    //2d)
    printf("1\n");
    if(fork() > 0) {     //Processo pai  
        /*
        write(STDOUT_FILENO,"2",1);    
        write(STDOUT_FILENO,"3",1);  

       //2c)
       printf("2");
       printf("3");
        */
       //2d)
       printf("2\n");
       printf("3\n");
       

    }   else {   //Processo filho 
        /*
        write(STDOUT_FILENO,"4",1);    
        write(STDOUT_FILENO,"5",1);  

       //2c)
       printf("4");
       printf("5");
       */
       //2d)
       printf("4\n");
       printf("5\n");
    }  
    write(STDOUT_FILENO,"\n",1);  
    return 0; 
} 

/*

2a) Os números que podem ser escritos no ecrã são 1 (escrito antes do fork()),
2 e 3 (pelo processo-pai), e 4 e 5 (pelo processo-filho)

2c) Ao utilizar chamadas printf(), o programa imprime "123" e "145", o
1 é imprimido 2 vezes porque fica no buffer tanto para o processo-pai
como para o processo-filho

2d) Ao fazer esta substituição o programa imprime agora os outputs
dos dois processos com 2 "\n", isto é porque o \n fica no buffer
devido ao printf("1\n") e também devido ao printf("3\n") do processo-
pai

*/