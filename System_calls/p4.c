#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int primeornot(int a) {
    int i, flag = 0;
    
    for (i = 2; i < a/2; i++) {
        if (a % i == 0) {
            flag = 1;
            break;
        }
    }
    
    return flag;
}

void main() {
    int pid = fork();
    int number, status;
    int flag = 0;

    if (pid == 0) {
        printf("-------------\n");
        printf("Child process\n");
        printf("-------------\n");
    } else {
        wait(&status);
        printf("-------------\n");
        printf("Parent process\n");
        printf("Enter a number: ");
        wait(NULL);
        scanf("%d", &number);

        if (primeornot(number) == 0) {
            printf("The number is prime\n");
        } else {
            printf("The number is not prime\n");
        }
        printf("-------------\n");

    }
}
