#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();

    if (pid == -1) { perror("fork"); return 1; }

    if (pid == 0) {
        printf("Child:  fork() = %5i, getpid() = %5i\n", pid, getpid());
    } else {
        waitpid(pid, NULL, 0);
        printf("Parent: fork() = %5i, getpid() = %5i\n", pid, getpid());
    }

    return 0;
}
