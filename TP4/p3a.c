#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int var = 0;

void sigusr_handler(int signo){
    if (signo == SIGUSR1){
        var++;
    }

    else if (signo == SIGUSR2){
        var--;
    }
}


int main(void){

    printf("PID: %d\n",getpid());
    struct sigaction usr_action;  
    usr_action.sa_handler = sigusr_handler;  
    sigemptyset(&usr_action.sa_mask);  
    usr_action.sa_flags = 0; 

    while (var < 5){
        sigaction(SIGUSR1,&usr_action,NULL);
        sigaction(SIGUSR2,&usr_action,NULL);       

        printf("Var: %d\n", var);
        sleep(1);
    }

    return 0;

}
