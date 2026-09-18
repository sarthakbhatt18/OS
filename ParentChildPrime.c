//Write a program to calculate sum of array in parent process and then check the sum is prime or not in child process using fork() system call.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

int main() {
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    // Calculate sum in parent process
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("Sum in parent process: %d\n", sum);

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        printf("Checking if sum is prime in child process: %d\n", sum);
        if (isPrime(sum)) {
            printf("Sum is prime.\n");
        } else {
            printf("Sum is not prime.\n");
        }
    } else {
        // Parent process
        wait(NULL); // Wait for child to complete
    }

    return 0;
}