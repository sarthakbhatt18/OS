#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>

void fibonacci(int n) {
    int a = 0, b = 1, c;

    printf("Child Process: Fibonacci Series:\n");

    while (a <= n) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

int armstrong(int num) {
    int temp = num, digits = 0;
    int rem, sum = 0;

    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = num;

    while (temp != 0) {
        rem = temp % 10;
        sum += pow(rem, digits);
        temp /= 10;
    }

    return (sum == num);
}

int main() {
    int n, i;

    printf("Enter n: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        // Child Process
        fibonacci(n);
    }
    else {
        // Parent Process
        wait(NULL);

        printf("Parent Process: Armstrong Numbers up to %d:\n", n);

        for (i = 1; i <= n; i++) {
            if (armstrong(i))
                printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}