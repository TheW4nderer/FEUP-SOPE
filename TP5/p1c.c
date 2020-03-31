#include<stdio.h> 
#include<unistd.h> 
#include<stdlib.h>
#include<sys/types.h> 
#define READ 0 
#define WRITE 1 


int main(void) { 
    int fd[2];   
    pid_t pid;   
    pipe(fd);   
    pid = fork(); 
    
    if (pid >0) //pai   
    {
        char a[2][10];     
        printf("PARENT:\n");     
        printf("Numbers(x y): "); 
        scanf("%s %s",a[0],a[1]);     
        close(fd[READ]);     
        write(fd[WRITE],a,2*sizeof(char*));     
        close(fd[WRITE]);   } 
        
    else //filho   
    { 
        char b[2][10];    
        int x,y;
        close(fd[WRITE]);     
        read(fd[READ],b,2*sizeof(char*)); 
        x = atoi(b[0]);
        y = atoi(b[1]);    
        printf("SON:\n");  
        printf("Sum: %d\n", x+y);
        printf("Difference: %d\n", x-y);
        printf("Multiplication: %d\n", x*y);  
        if (b[1] == 0)
            printf("Division by 0: Error\n");
        else 
            printf("Division: %f\n", (float)x/ (float)y);         
        close(fd[READ]);  
    } 
    return 0; 
} 