#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>



int main(int argc, char const *argv[])
{
    int pid;

    printf("process ID %d\n", getpid());
    pid = atoi(argv[1]);

    int bit = 0;
    while (bit < 8)
    {
        if (bit % 2 == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);

        usleep(500);
        bit++;
    }

    return 0;
}
