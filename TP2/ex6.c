#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{
 DIR *dirp;
 struct dirent *direntp;
 struct stat stat_buf;
 char *str;

 if (argc != 2)
 {
  fprintf( stderr, "Usage: %s dir_name\n", argv[0]);
  exit(1);
 }

 if ((dirp = opendir( argv[1])) == NULL)
 {
  perror(argv[1]);
  exit(2);
 }

 while ((direntp = readdir( dirp)) != NULL)
 {
  if (stat(direntp->d_name, &stat_buf)==-1)   // testar com stat()
  {
   perror("lstat ERROR");
   exit(3);
  }
  if (S_ISREG(stat_buf.st_mode)) str = "regular";
  else if (S_ISDIR(stat_buf.st_mode)) str = "directory";
  else str = "other";
  printf("%-25s - %s\n", direntp->d_name, str);
  printf("File's i-node: %ld\n", stat_buf.st_ino);
  printf("File Size: %ld\n", stat_buf.st_size);
  printf("-------------------------------------\n");
 }

 closedir(dirp);
 exit(0);
}


/*

6c) i-nodes:
    temp.txt:   932190
    temp1.txt:  932190
    temp2.txt:  932189

    Size:
    temp.txt:   6
    temp1.txt:  6
    temp2.txt:  8

    temp.txt e temp1.txt têm o mesmo tamanho e i-node devido ao facto de temp1.txt ser um hard link para o ficheiro original,
    que é uma cópia deste.

    temp2.txt tem i-node e tamanho diferente dos restantes por ser um symbolic link, este não contem o conteúdo do ficheiro
    original mas sim um pointer para este.

6d) Ao modificar lstat() para stat(), obtemos um tamanho diferente para temp2.txt. Como lstat() retorna, para symbolic links,
    informação acerca do prórpio link e não do ficheiro, esta chamada resulta num tamanho diferente para temp2.txt. A chamada
    stat(), para symbolic links, retorna informações do ficheiro, daí este ter o mesmo tamanho que o ficheiro original (6);
    

*/

