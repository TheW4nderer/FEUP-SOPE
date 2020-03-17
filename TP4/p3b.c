#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>


int var = 0;

void sigusr_handler(int signo){
    if (signo == SIGUSR1){
        var++;
    }

    else if (signo == SIGUSR2){
        var--;
    }

    printf("Var: %d\n",var);
}



int main(void){

    srand(time(NULL));

    pid_t pid = fork();

    if (pid > 0){   //Processo-pai
        int i;
        printf("Sending signals\n");
        for (i=0 ; i<50 ; i++){
            if (rand()%2 == 0){
                printf("%d: Child received SIGUSR1 signal\n", i);
                kill(pid , SIGUSR1);
            }
            else {
                printf("%d: Child received SIGUSR2 signal\n", i);
                kill(pid , SIGUSR2);
            }
            sleep(1);
        }

    }
    else if (pid == 0){     //Processo-filho
        struct sigaction usr_action;
        usr_action.sa_handler = sigusr_handler;
        usr_action.sa_flags = 0;
        sigemptyset( &(usr_action.sa_mask) );
        
        sigaction(SIGUSR1 , &usr_action , NULL);
        sigaction(SIGUSR2 , &usr_action , NULL);
    
        while(1){ 
            pause();
        }

    }
    else{
        printf("Fork error.\n");
        exit(1);
    }

    return 0;
}