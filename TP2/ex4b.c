#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define MAX_LEN 50

int main(int argc, char *argv[]){

    struct termios term, oldterm;
    int fdes, i;
    char ch;

    if (argc != 2) {
        printf("Usage: %s <destination>\n", argv[0]);
        return 1;
    }

    fdes = open(argv[1], O_WRONLY | O_CREAT, 0644);

    if (fdes == -1){
        perror(argv[1]);
        return 2;
    }

    write(STDOUT_FILENO, "Nome Classificacao\n", 20);
    tcgetattr(STDIN_FILENO, &oldterm);
    term = oldterm;
    term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);

    i=0;
    while (i < MAX_LEN && read(STDIN_FILENO, &ch, 1) && ch != '\t') {
        write(STDOUT_FILENO, &ch, 1);
        write(fdes, &ch, 1);
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldterm);
    write(STDOUT_FILENO, "\nFinished\n: ", 12);

    return 0;
}
