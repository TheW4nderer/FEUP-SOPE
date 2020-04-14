// PROGRAMA p01.c 
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h> 
#include <string.h>
#define STDERR 2 
#define NUMITER 10000 

void * thrfunc(void * arg) {   
    int i;   
    fprintf(stderr, "Starting thread %s\n", (char *) arg);   
    for (i = 1; i <= NUMITER; i++) write(STDERR,arg,1);   
    return NULL; 
} 
    
        
int main() {    
    pthread_t ta, tb;
    //char snum[1] = "1";   
    //char num[2] = "2";
    char snum[5];
    int num = 1;
    sprintf(snum,"%d",num);
    //pthread_create(&ta, NULL, thrfunc, "1");   
    pthread_create(&ta, NULL, thrfunc, snum); 
    num = 2;
    sprintf(snum,"%d",num);
    //pthread_create(&tb, NULL, thrfunc, "2");  
    pthread_create(&tb, NULL, thrfunc, snum);  
    pthread_join(ta, NULL);   
    pthread_join(tb, NULL);   
    return 0; 
}




/*
1b) Se for usada a mesma variavel para guardar o parametro de cada uma das threads,
estas usam apenas o valor 2, porque é o que é atribuido mais tarde.


*/
