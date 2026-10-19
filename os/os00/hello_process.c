#include <stdio.h>
#include <unistd.h>

// Not quite sure why child is the 0.
// Wouldn't it makes more sense if the parent was the 0?

int main(void) {
    pid_t pid = fork();

    if (pid == -1) { perror("fork"); return 1; }

    if (pid == 0) {
        printf("Hello, I am the  child: %i\n", getpid());
    } else {
        printf("Hello, I am the parent: %i\n", getpid());
    }

    return 0;
}
