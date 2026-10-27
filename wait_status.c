#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child: performing a task.\n");
        printf("Child: exiting with status 7.\n");
        exit(7);
    }

    int status;

    waitpid(pid, &status, 0);

    if (WIFEXITED(status))
    {
        printf("Parent: child exited normally.\n");
        printf("Parent: child's exit status = %d\n",
               WEXITSTATUS(status));
    }

    return 0;
}
