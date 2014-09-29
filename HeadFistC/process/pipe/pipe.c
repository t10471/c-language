#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void error(char* msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void open_url(char* url)
{
    // printf("url is %s", url);
    char launch[255];
    sprintf(launch, "echo x-www-browser '%s' &", url);
    system(launch);
}

int main(int argc, char* argv[])
{
    char* phrase = argv[1];
    char* vars[] = {"RSS_FEED=http://rss.cnn.com/rss/edition.rss", NULL};
    int fd[2];
    if (pipe(fd) == -1) {
        error("Can't create the pipe");
    }
    pid_t pid = fork();
    if (pid == -1) {
        error("Can't fork process");
    }
    //子プロセス
    if (!pid) {
        //標準出力をパイプの書き込み側に設定
        dup2(fd[1], 1);
        //読み込み側を閉じる
        close(fd[0]);
        if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u",
                   phrase, NULL, vars) == -1) {
            error("Can't run script");
        }
    }
    //親プロセス 標準入力をパイプのの読み込み側に設定
    dup2(fd[0], 0);
    //書き込み側を閉じる
    close(fd[1]);
    char line[255];
    while (fgets(line, 255, stdin)) {
        if (line[0] == '\t') open_url(line + 1);
    }
    return 0;
}
