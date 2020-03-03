#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


#define BUFFER_SIZE 512

int main(int argc, char *argv[]){
    int fdes1, fdes2, nbytesr, nbytesw;
    unsigned char buffer[BUFFER_SIZE];


    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    fdes1 = open(argv[1], O_RDONLY);

    if (fdes1 == -1){
        perror(argv[1]);
        return 2;
    }

    fdes2 = open(argv[2], O_WRONLY | O_CREAT, 0644);

    if (fdes2 == -1){
        perror(argv[2]);
        close(fdes1);
        return 3;
    }

     while ((nbytesr = read(fdes1, buffer, BUFFER_SIZE)) > 0){  //Read src
        if ((nbytesw = write(fdes2, buffer, nbytesr)) <= 0 || nbytesw != nbytesr){      //Write in dst and verification
            perror(argv[2]);
            close(fdes1);
            close(fdes2);
            return 4;
        }
    
    }
    close(fdes1);
    close(fdes2);
    return 0;

}
