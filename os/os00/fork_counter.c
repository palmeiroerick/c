#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// Each process have its own memory space.
// They don't share the same x variable.

int main(void) {
    pid_t pid = fork();
    int x = 0;

    if (pid == -1) { perror("fork"); return 1; }

    if (pid == 0) {
        for (int i = 0; i < 3; i++) x++;
        printf("[Child]  x = %i\n", x);
    } else {
        waitpid(pid, NULL, 0);
        for (int i = 0; i < 3; i++) x++;
        printf("[Parent] x = %i\n", x);
    }

    return 0;
}