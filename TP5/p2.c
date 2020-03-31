#include<stdio.h> 
#include<unistd.h> 
#include<sys/types.h> 
#define READ 0 
#define WRITE 1 


int main(void) { 
    int fd[2];  
    int fd2[2]; 
    pid_t pid;   
    pipe(fd);
    pipe(fd2);
    pid = fork(); 
    
    if (pid >0) //pai   
    {
        //Writing to the 1st pipe
        int a[2];   
        double result[5];  
        printf("PARENT:\n");     
        printf("Numbers(x y): "); 
        scanf("%d %d",&a[0],&a[1]);     
        close(fd[READ]);     
        close(fd2[WRITE]);
        write(fd[WRITE],a,2*sizeof(int));     
        close(fd[WRITE]); 

        //Reading from the 2nd pipe and printing
        read(fd2[READ],result, 5*sizeof(double));

        printf("Sum: %d\n", (int)result[1]);
        printf("Difference: %d\n", (int)result[2]);
        printf("Multiplication: %d\n", (int)result[3]);  
        if (result[0] == 1)
            printf("Division by 0: Error\n");
        else 
            printf("Division: %f\n", (float)result[4]);  
        close(fd2[READ]);
        
    }  
    else//filho   
    { 
        int b[2];  
        double result[5];  
        close(fd[WRITE]);
        close(fd2[READ]);

        //Reading from the 1st pipe and processing 
        read(fd[READ],b,2*sizeof(int));     
        result[1] = b[0] + b[1];
        result[2] = b[0] - b[1];
        result[3] = b[0] * b[1];
        if (b[1] == 0){
            result[0] = 1;
            result[4] = 0;
        }
        else {
            result[0] = 0;
            result[4] = (float)b[0] / (float)b[1];
        }
        close(fd[READ]);  
        //Writing to the 2nd pipe
        write(fd2[WRITE],result,5*sizeof(double));
        close(fd2[WRITE]);
        

    } 
    return 0; 
} 