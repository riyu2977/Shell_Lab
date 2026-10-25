#include <stdio.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t interrupted = 0;

void handle_sigint(int signal_number)
{
    interrupted = 1;
}

int main()
{
    struct sigaction action = {0};

    action.sa_handler = handle_sigint;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    if (sigaction(SIGINT, &action, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }

    printf("PID = %d\n", getpid());
    printf("Press Ctrl+C to notify this process.\n");

    while (!interrupted)
    {
        pause();
    }

    printf("\nSIGINT received. Exiting now...\n");

    return 0;
}
