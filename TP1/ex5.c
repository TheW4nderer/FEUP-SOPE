#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp)
{
    //5a
    /*
    for (char **env = envp; *env != 0; env++)
    {
        char *thisEnv = *env;
        printf("%s\n", thisEnv);    
    }
    */

    //5b
    /*
    for (char **env = envp; *env != 0; env++)
    {
        if (strncmp("USER=", *env, 5) == 0){
            *env += 5;
            printf("Hello %s !\n", *env);   
        }
         
    }
    return 0;
    */

   //5c
   char* user = getenv("USER");

   printf("Hello %s !\n",user);

   return 0;
}
