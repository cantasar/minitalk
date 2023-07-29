#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signal)
{
    if (signal == SIGUSR1)
    {
        printf("SIGUSR1\n");
    }
    else if (signal == SIGUSR2)
    {
        printf("SIGUSR2\n");
    }
}

int main(int argc, char const *argv[])
{
    printf("process ID %d\n", getpid());

    while (1)
    {
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);

        pause();
    }

    return 0;
}
