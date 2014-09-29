#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_interrupt(int sig)
{
    puts("Goodbye cruel world....\n");
    exit(1);
}


// SIGINT プロセスが割り込まれた。
// SIGQUIT 誰かがプロセスに停止してコアダンプファイルにメモリをダンプするように要求した。
// SIGFPE 浮動小数点エラー
// SIGTRAP デバッガがプロセスの実行箇所を尋ねた。
// SIGSEGV プロセスが不正なメモリにアクセスしようとした。
// SIGWINCH 端末ウィンドウのサイズが変更された。
// SIGTERM 誰かがカーネルにプロセスを終了するように要求した。
// SIGPIPE プロセスが誰も読み込んでいないパイプに書き込んだ。

int main()
{
    //割り込み（Ctr + cなど）のときにhandle_interruptを呼ぶように設定
    if (signal(SIGINT, handle_interrupt) == SIG_ERR) {
        fprintf(stderr, "Can't map the handler");
        exit(2);
    }
    char name[30];
    printf("Enter your name: ");
    fgets(name, 30, stdin);
    printf("Hello %s\n", name);

    return 0;
}
