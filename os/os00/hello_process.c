#include <stdio.h>
#include <unistd.h>

// There is no guarantee of which will run first the child or the parent.
// The fork function for the parent return the pid of the child.
// The fork function for the parent return -1 when the fork fail.
// The fork funciion for the child return 0 for success.

int main(void) {
    pid_t pid = fork();

    if (pid == -1) { perror("fork"); return 1; }

    if (pid == 0) {
        printf("Child:  fork() = %5i, getpid() = %5i\n", pid, getpid());
    } else {
        printf("Parent: fork() = %5i, getpid() = %5i\n", pid, getpid());
    }

    return 0;
}
