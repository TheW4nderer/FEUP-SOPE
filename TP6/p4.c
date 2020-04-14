// PROGRAMA p01.c 
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h> 
#include <string.h>
#define NUM_THREADS 10 

void * thrfunc(void * arg) {   
    sleep(1);
    printf("Thread no. %d with TID: %lu\n",*(int *) arg, pthread_self());     //4a)
    pthread_exit(arg);
} 
    
        
int main() {    
    pthread_t threads[NUM_THREADS];    
    int t;    
    for(t=0; t< NUM_THREADS; t++){
        void * ret;
        pthread_create(&threads[t], NULL, thrfunc, (void *)&t);
        pthread_join(threads[t], &ret);
        //printf("Thread no. %d just ended\n", *(int*)ret);
    }
    exit(0);
}

/*
    4b) Se a thread principal nao esperar pelo fim das outras threads, o
    programa nao imprime nada, porque o programa termina antes de chegar
    à chamada printf() (devido ao sleep)
*/

