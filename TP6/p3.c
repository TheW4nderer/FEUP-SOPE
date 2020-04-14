// PROGRAMA p03.c 

#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#define NUM_THREADS 10 


void *PrintHello(void *threadnum) {    
    printf("Hello from thread no. %d!\n", *(int *) threadnum);    
    pthread_exit(NULL); 
} 
    
    
int main() {    
    pthread_t threads[NUM_THREADS];    
    int t;    
    for(t=0; t< NUM_THREADS; t++){       
        printf("Creating thread %d\n", t);       
        pthread_create(&threads[t], NULL, PrintHello, (void *)&t);
        //pthread_join(threads[t], NULL);  //3b)
    }    
    //pthread_exit(0);
    exit(0); 
}


/*
3a) Os threads nao estao sincronizados, desta maneira, a ordem dos prints varia de
execucao para execucao.

3c) O ultimo print, para o thread 10, não é executado, uma vez que o exit para todos os
threads.
*/