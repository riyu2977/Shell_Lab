#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("Parent process started. PID = %d\n", getpid());

    pid_t result = fork();

    if (result < 0)
    {
        perror("fork");
        return 1;
    }
    else if (result == 0)
    {
        printf("Child process started; PID = %d\n", getpid());
        printf("Child process in work.\n");
        return 0;
    }
    else
    {
        printf("Parent is waiting for the child process; PID = %d\n", result);

        waitpid(result, NULL, 0);

        printf("child has finished the work; parent is continuing.\n");
    }

    return 0;
}
