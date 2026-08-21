#include <stdio.h>
#include <unistd.h>

int main(){
    int pid = fork();
    if(pid == 0){
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(10);
        printf("Child process after sleep: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        printf("Parent process exiting...\n");
        return 0;
    }
    return 0;
}