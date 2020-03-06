// PROGRAMA p5b.c
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{
  int fd;
  char *text1="CCCCC";
  char *text2="DDDDD";

  fd = open("f1.txt", O_WRONLY|O_SYNC|O_APPEND,0600);

  if (fd == -1){
    perror("Error opening file");
    return 1;
  }


  if (write(fd,text1,5) != 5){
    perror("Error writing to file\n");
    return 2;
  }
  if (write(fd,text2,5) != 5){
    perror("Error writing to file\n");
    return 3;
  }
  close(fd);
  return 0;
}

