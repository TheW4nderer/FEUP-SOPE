#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {   

    if(fork() > 0) {   //Processo pai  
        write(STDOUT_FILENO,"Hello",6);    
           
    }   else {          //Processo filho    
        write(STDOUT_FILENO," world!",8);         
    } 

}