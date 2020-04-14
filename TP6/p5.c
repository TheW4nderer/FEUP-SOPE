// PROGRAMA p01.c 
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h> 
#include <string.h>
#define NUM_THREADS 3





void * thrSum(void * arg) {   
    int op1, op2;
    int* result = (int*) malloc(sizeof(int));
    op1 = ((int*) arg)[0];
    op2 = ((int*) arg)[1];
    *result = op1 + op2;
    //printf("Sum: %d + %d = %d\n",op1, op2, result);
    pthread_exit(result);
} 

void * thrMul(void * arg) {   
    int op1, op2;
    int* result = (int*) malloc(sizeof(int));
    op1 = ((int*) arg)[0];
    op2 = ((int*) arg)[1];
    *result = op1 * op2;
    //printf("Multiplication: %d * %d = %d\n",op1, op2, result);
    pthread_exit(result);
} 

void * thrDiv(void * arg) {   
    int op1, op2;
    int* result = (int*) malloc(sizeof(int));
    op1 = ((int*) arg)[0];
    op2 = ((int*) arg)[1];
    *result = op1 / op2;
    //printf("Division: %d / %d = %d\n",op1, op2, result);
    pthread_exit(result);
} 

void * thrSub(void * arg) {   
    int op1, op2;
    int* result = (int*) malloc(sizeof(int));
    op1 = ((int*) arg)[0];
    op2 = ((int*) arg)[1];
    *result = op1 - op2;
    //printf("Subtraction: %d - %d = %d\n",op1, op2, result);
    pthread_exit(result);
} 
    
        
int main() {    
    pthread_t tSum, tDiv, tMul, tSub;    
    int t;
    int numbers[2];
    void* sum;
    void* sub; 
    void* mul; 
    void* div;
    printf("Insert the first number: ");
    scanf("%d",&numbers[0]); 
    printf("Insert the second number: ");
    scanf("%d",&numbers[1]);

    pthread_create(&tSum, NULL, thrSum, numbers);
    pthread_join(tSum, &sum);
    printf("Sum: %d\n",*(int*)sum); //5b)
    
    pthread_create(&tSub, NULL, thrSub, numbers);
    pthread_join(tSub, &sub);
    printf("Subtraction: %d\n",*(int*)sub); //5b)
    
    pthread_create(&tMul, NULL, thrMul, numbers);
    pthread_join(tMul, &mul);
    printf("Multiplication: %d\n",*(int*)mul);  //5b)
    
    pthread_create(&tDiv, NULL, thrDiv, numbers);
    pthread_join(tDiv, &div);
    printf("Division: %d\n",*(int*)div);    //5b)

   

    exit(0);
}

