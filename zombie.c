#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int pid = fork();
    if(pid == 0){
        printf("Child process exiting...\n");
        return 0;
    } else {
        sleep(10);
        wait(NULL);
    }
    return 0;
}