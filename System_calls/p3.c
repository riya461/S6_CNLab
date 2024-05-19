#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void lwrtouppr() {
    char str[100];
    printf("Enter the string: ");
    scanf(" %[^\n]", str);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        i++;
    }
    printf("%s\n", str);
}

void main() {
    int pid = fork();
    char str[100];
    if (pid > 0) {
        printf("-------------\n");
        printf("Parent process\n");
        printf("--------------\n");
        wait(NULL);
    } else {
        printf("-------------\n");
        printf("Child process\n");
        lwrtouppr();
        printf("-------------\n");

    }
}
