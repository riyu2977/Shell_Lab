#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Before exec: PID = %d\n", getpid());
    printf("Launching ls...\n");
    fflush(stdout);

    char *args[] = {"ls", "-l", NULL};

    execvp(args[0], args); //replacing the current process of prog with ls

    perror("execvp failed");

    return 1;
}
