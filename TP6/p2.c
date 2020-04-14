// PROGRAMA p01.c 
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h> 
#include <string.h>
#define STDERR 2 
#define NUMITER 10000 


int num = 10;

void * thrfunc(void * arg) {   
    int i;   
    int* count = (int*) malloc(sizeof(int));
    fprintf(stderr, "Starting thread %s\n", (char *) arg);   
    while (num > 1){
        write(STDERR,arg,1);
        num = num-strlen(arg);
        *count += strlen(arg);  
    }

    pthread_exit(count);
} 
    
        
int main() {    
    pthread_t ta, tb;
    void * count_a;
    void * count_b;
    pthread_create(&ta, NULL, thrfunc, "1"); 
    pthread_create(&tb, NULL, thrfunc, "2");  
    pthread_join(ta, &count_a);   
    pthread_join(tb, &count_b);   

    printf("\nTotal chars written by thread A: %d\n", *(int *) count_a);
    printf("\nTotal chars written by thread B: %d\n", *(int *) count_b);

    printf("\nTotal chars written: %d\n",*(int *) count_a + *(int *) count_b);
    return 0; 
}


/*
2. Ao imprimir os caracteres os threads nao estao sincronizados, alguns destes
sao imprimidos pelo thread 1 antes do thread 2 começar.

*/