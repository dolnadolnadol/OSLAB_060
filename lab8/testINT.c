#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void INThandler(int);

void main(void){
    // 64050060
    signal(SIGINT, INThandler);
    while(1);
        pause();
}
void INThandler(int sig){
    signal(sig, SIG_IGN);
    printf("\nDid you hit Ctrl-C\n wanna quit? [y/n] \n");
    char c;
    scanf("%c",&c);
    if(c=='y'|| c=='Y') exit(0);
    else signal(SIGINT, INThandler);
}