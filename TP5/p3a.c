#include<stdio.h> 
#include<stdlib.h>  
#define MAXLINE 1000  



int main(int argc, char *argv[]) {
    char line[MAXLINE];   
    
    FILE *fpin, *fpout; 
    
    if (argc != 2) { 
        printf("Usage: %s filename\n",argv[0]); 
        exit(1); 
    }   
    fpin = fopen(argv[1], "r");   
    fpout = popen("sort", "w"); 
    
    while (fgets(line, MAXLINE, fpin) != NULL)     
        fputs(line, fpout) == EOF;   
        
    pclose(fpout);   
    exit(0); 

}    