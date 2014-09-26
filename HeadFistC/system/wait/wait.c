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

int main(int argc, char* argv[])
{
    char* phrase = argv[1];
    char* vars[] = {"RSS_FEED=http://rss.cnn.com/rss/edition.rss", NULL};
    FILE* f = fopen("stories.txt", "w");
    if (!f) {
        error("Can't open stories.txt");
    }
    pid_t pid = fork();
    if (pid == -1) {
        error("Can't fork process");
    }
    if (!pid) {
        //filenoでファイルのディスクリプタを取得し
        //dup2で1(標準出力)をファイルに変更している
        if (dup2(fileno(f), 1) == -1) {
            error("Can't redirect Standard Output");
        }
        if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py",
                   phrase, NULL, vars) == -1) {
            error("Can't run script");
        }
        int pid_status;
        //第3引数はオプション
        if (waitpid(pid, &pid_status, 0) == -1) {
            error("Error waiting for child process");
        }
    }
    return 0;
}

