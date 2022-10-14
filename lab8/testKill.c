#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int notDone = 1;
int cnt = 0;

// 64050060
void mySIGhandler(int sig){
    signal(SIGALRM, SIG_IGN);
    printf("GoTo Die Man.\n");
    // notDone = 0;
}
int main(void){
    signal(SIGALRM, mySIGhandler);
    pid_t pid = fork();
    if(pid == 0){
        printf("Child Create.\n");
        while(1);
        printf("DONT SHOW\n");
        // kill(getppid(), SIGALRM);
    }else {
        
        // printf("parent wait for SIGALRM\n");
        // while(notDone) cnt++;
        sleep(2);
        kill(getpid(), SIGALRM);
        printf("I will go after my child yaaaaaaa.");
        exit(0);
    }
    // printf("it rakes %d\n", cnt);
    return 0;
}