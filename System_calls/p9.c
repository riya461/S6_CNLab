#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    // Forking to create a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("Error creating child process");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent process
        printf("Parent process details - PID: %d, Parent PID: %d\n", getpid(), getppid());
        wait(NULL);  // Waiting for the child process to finish
        printf("Parent process exiting...\n");
    } else if (pid == 0) {
        // Child process
        printf("Child process details - PID: %d, Parent PID: %d\n", getpid(), getppid());

        // Opening a file using file system calls
        int fd = open("example.txt", O_RDONLY);
        if (fd == -1) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }

        // Reading and displaying the contents of the file
        char buffer[1024];
        ssize_t bytesRead;
        printf("File contents:\n");
        while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, bytesRead);
        }

        close(fd);  // Closing the file descriptor

        printf("\nChild process exiting...\n");
    }

    return 0;
}
