#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


#define BUFFER_SIZE 512

int main(int argc, char *argv[]){
    int fdes, nbytesr, nbytesw;
    unsigned char buffer[BUFFER_SIZE];


    if (argc != 2) {
        printf("Usage: %s <destination>\n", argv[0]);
        return 1;
    }

    fdes = open(argv[1], O_WRONLY | O_CREAT, 0644);

    if (fdes == -1){
        perror(argv[1]);
        return 2;
    }

    while ((nbytesr = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0){  //Read src
        if ((nbytesw = write(fdes, buffer, nbytesr)) <= 0 || nbytesw != nbytesr){      //Write in dst and verification
            perror(argv[1]);
            close(fdes);
            return 4;
        }
    
    }
    return 0;
}
