#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {   

    if(fork() > 0) {   //Processo pai  
        printf(" world!");  //A chamada printf demora mais tempo logo o processo filho vai acabar primeiro  
           
    }   else {          //Processo filho    
        write(STDOUT_FILENO,"Hello",6);         
    } 
    
    return 0;

}