#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

// SIGKILL 強制終了(無視できない)
// SIGSTOP 一時停止(無視できない)
// SIGALRM　alarmで設定
// SIGCONT　再開
//
// alarmとsleepを同時に使用してはいけない
//
// デフォルトに戻す
// signal(SIGINT, SIG_DFL);
// 無視する
// signal(SIGINT, SIG_IGN);

int score = 0;

void end_game(int sig)
{
    printf("\nFinal score: %i\n", score);
    exit(0);
}
void times_up(int sig)
{
    puts("\nTIME'S UP!");
    //自分にシグナルを送る
    raise(SIGINT);
}
void error(char* msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}
int main()
{
    signal(SIGALRM, times_up);
    signal(SIGINT, end_game);
    //乱数のシード
    srandom(time(0));
    while (1) {
        int a = random() % 11;
        int b = random() % 11;
        char txt[4];
        //ここを通るたびに、毎回アラームはリセットされる
        alarm(5);
        printf("\nWhat is %i times %i? ", a, b);
        fgets(txt, 4, stdin);
        int answer = atoi(txt);
        if (answer == a * b)
            score++;
        else
            printf("\nWrong! Score: %i\n", score);
    }
    return 0;
}
