#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {   

    if(fork() > 0) {   //Processo pai  
        write(STDOUT_FILENO,"Hello ",6);    
           
    }   else {        //Processo filho 
            
            if (fork() >0){
                write(STDOUT_FILENO,"my ",3);  
            }   else{
                write(STDOUT_FILENO,"friends!", 9);  
            }        
    } 
    return 0;
}