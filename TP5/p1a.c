#include<stdio.h> 
#include<unistd.h> 
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
        int a[2];     
        printf("PARENT:\n");     
        printf("Numbers(x y): "); 
        scanf("%d %d",&a[0],&a[1]);     
        close(fd[READ]);     
        write(fd[WRITE],a,2*sizeof(int));     
        close(fd[WRITE]);   } 
        
    else//filho   
    { 
        int b[2];    
        close(fd[WRITE]);     
        read(fd[READ],b,2*sizeof(int));     
        printf("SON:\n");  
        printf("Sum: %d\n", b[0]+b[1]);
        printf("Difference: %d\n", b[0]-b[1]);
        printf("Multiplication: %d\n", b[0]*b[1]);  
        if (b[1] == 0)
            printf("Division by 0: Error\n");
        else 
            printf("Division: %f\n", (float)b[0]/ (float)b[1]);         
        close(fd[READ]);  
    } 
    return 0; 
} 