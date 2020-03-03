#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define BUF_LENGTH 256

int main(int argc, char* argv[]){
    FILE *src, *dst;
    char buf[BUF_LENGTH];
    
    if(argc!=3){
        printf("usage: %s file1 file2\n", argv[0]);
        exit(1);
    }

    src = fopen(argv[1], "r");
    if (src == NULL){
        perror(argv[1]);
        exit(1);
    }

    dst = fopen(argv[2], "w");
    if (dst == NULL){
        perror(argv[2]);
        exit(2);
    }

    while (fread(&buf, 1, 1, src) > 0){  //Read src
        fwrite(&buf,1,1, dst);      //Write in dst
    }

    fclose(src);
    fclose(dst);
    return 0;

}