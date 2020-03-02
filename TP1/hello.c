#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char* argv[]){ 
    for (unsigned k = 0; k < atoi(argv[1]); k++){
        printf("Hello ");
        for (int i = 2; i < argc; i++){
            printf("%s ", argv[i]);   
        }
        printf("!\n");
    }
    return 1; 
}