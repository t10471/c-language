#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

//引数としてコマンドを渡す
void my_execl()
{
    if (execl("/bin/ls", "ls", "-l", NULL) == -1) {
        fprintf(stderr, "error : %s\n", strerror(errno));
    }
}

//配列としてコマンドを渡す
void my_execv()
{
    char* argv[] = {"ls", "-l", NULL};
    if (execv("/bin/ls", argv) == -1) {
        fprintf(stderr, "error : %s\n", strerror(errno));
    }
}

//絶対パスじゃなくてもOK
void my_execlp()
{
    if (execlp("ls", "ls", "-l", NULL) == -1) {
        fprintf(stderr, "error : %s\n", strerror(errno));
    }
}

void my_execvp()
{
    char* argv[] = {"ls", "-l", NULL};
    if (execvp("ls", argv) == -1) {
        fprintf(stderr, "error : %s\n", strerror(errno));
    }
}

//環境変数を渡す
void my_execle()
{
    char* envv[] = {"CONTENT_LENGTH=1024", NULL};
    if (execle("/bin/ls", "ls", "-l", NULL, envv) == -1) {
        fprintf(stderr, "error : %s\n", strerror(errno));
    }
}

void my_execve()
{
    char* argv[] = {"ls", "-l", NULL};
    char* envv[] = {"CONTENT_LENGTH=1024", NULL};
    if (execve("/bin/ls", argv, envv) == -1) {
        fprintf(stderr, "error : %s\n", strerror(errno));
    }
}

pid_t fork_exec(void (*func)(void))
{
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork失敗");
        return pid;
    } else if (pid == 0) {
        // 子プロセスで別プログラムを実行
        func();
        //ここまで来るとエラー
        perror("exec失敗");
        return -1;
    }
    return pid;
}

void wait_all()
{
    for (;;) {
        pid_t pid;
        int status = 0;

        pid = wait(&status);
        printf("pid %d\n", pid);
        if (pid == -1) {
            fprintf(stderr, "error : %s\n", strerror(errno));
            if (ECHILD == errno) {
                // 子プロセスが存在しない
                break;
            } else if (EINTR == errno) {
                continue;
            }
            // wait が失敗した
            perror("wait error");
        }
    }
}

int main()
{
    fork_exec(&my_execl);
    fork_exec(&my_execv);
    fork_exec(&my_execlp);
    fork_exec(&my_execvp);
    fork_exec(&my_execle);
    fork_exec(&my_execve);
    wait_all();
    return 0;
}
