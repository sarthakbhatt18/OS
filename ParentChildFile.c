// Write a c program to create input.txt in parent process and write your name , university roll no and class roll no in it and then read same file in child process and print the content
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    FILE *fp;
    pid_t pid;

    // Create and write to input.txt in parent process
    fp = fopen("input.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fprintf(fp, "Your Name: Sarthak Bhatt\n");
    fprintf(fp, "University Roll No: 2025439\n");
    fprintf(fp, "Class Roll No: 52\n");
    fclose(fp);

    pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        fp = fopen("input.txt", "r");
        if (fp == NULL) {
            perror("Error opening file");
            exit(1);
        }
        printf("Content of input.txt:\n");
        char ch;
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
        }
        fclose(fp);
    } else {
        // Parent process
        wait(NULL); // Wait for child to complete
    }

    return 0;
}