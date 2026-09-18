#include <stdio.h>
#include <unistd.h>


int prime(int n) {
    int i;

    if (n <= 1)
        return 0;

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int factorial(int n) {
    int i, fact = 1;

    for (i = 1; i <= n; i++)
        fact *= i;

    return fact;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid == 0) {
        // Child Process
        if (prime(n))
            printf("Child Process: %d is Prime\n", n);
        else
            printf("Child Process: %d is Not Prime\n", n);
    }
    else {
        // Parent Process
        
        printf("Parent Process: Factorial = %d\n", factorial(n));
    }

    return 0;
}