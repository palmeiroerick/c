#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();

    if (pid == -1) { perror("fork"); return 1; }

    if (pid == 0) {
        pid_t pid_child = fork();

        if (pid_child == -1) { perror("fork_child"); return 1; }

        if (pid_child == 0) {
            printf("[Grandchild] my pid: %5i, my parent pid: %5i\n", getpid(), getppid());
        } else {
            waitpid(pid_child, NULL, 0);
            printf("[Child]      my pid: %5i, my parent pid: %5i\n", getpid(), getppid());
        }
    } else {
        waitpid(pid, NULL, 0);
        printf("[Parent]     my pid: %5i\n", getpid());
    }

    return 0;
}