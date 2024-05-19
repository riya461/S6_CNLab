#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 4096

int main()
{
   

    int sourceFile = open("sourceFile.txt", O_RDONLY);
    int destinationFile = open("destinationFile.txt", O_CREAT | O_WRONLY );
    if (destinationFile && sourceFile == -1)
    {
        printf("Error in File Creation or Deletion");
    }

    char buffer[BUF_SIZE];
    ssize_t bytesRead, bytesWritten, totalBytesCopied = 0;

    while ((bytesRead = read(sourceFile, buffer, BUF_SIZE)) > 0) {
        bytesWritten = write(destinationFile, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            perror("Error writing to destination file");
            break;
        }
        totalBytesCopied += bytesWritten;
    }

    if (bytesRead == -1) {
        perror("Error reading from source file");
    }

    printf("Copy successful. Total bytes copied: %lu\n", totalBytesCopied);

    close(sourceFile);
    close(destinationFile);

    exit(EXIT_SUCCESS);
}