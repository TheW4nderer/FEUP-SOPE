#include<stdio.h> 
#include<unistd.h> 
#include<sys/types.h> 
#define READ 0 
#define WRITE 1 

struct Numbers{
    int x;
    int y;
};



int main(void) { 
    int fd[2];   
    pid_t pid;   
    pipe(fd);   
    pid = fork(); 
    
    if (pid >0) //pai   
    {
        struct Numbers numbers;    
        printf("PARENT:\n");     
        printf("Numbers(x y): "); 
        scanf("%d %d",&numbers.x,&numbers.y);     
        close(fd[READ]);     
        write(fd[WRITE],&numbers,sizeof(numbers));     
        close(fd[WRITE]);  
    }     
    else//filho   
    { 
        struct Numbers numbers;     
        close(fd[WRITE]);     
        read(fd[READ],&numbers,sizeof(numbers));     
        printf("SON:\n");    
        printf("Sum: %d\n", numbers.x+numbers.y);
        printf("Difference: %d\n", numbers.x-numbers.y);
        printf("Multiplication: %d\n", numbers.x*numbers.y);  
        if (numbers.y == 0)
            printf("Division by 0: Error\n");
        else 
            printf("Division: %f\n", (float)numbers.x/ (float)numbers.y);         
        close(fd[READ]);  
    } 
    return 0; 
} 