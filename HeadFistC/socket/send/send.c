#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[])
{
    char *advice[] = {
        "Take smaller bites\r\n",
        "Go for the tight jeans. No they do NOT make you look fat.\r\n",
        "One word: inappropriate\r\n",
        "Just for today, be honest. Tell your boss what you *really* think\r\n",
        "You might want to rethink that haircut\r\n"};
    //ソケットの作成ディスクリプタを返す
    // socket(int domain, int type, int protocol);
    // domain はPF_INET, PF_UNIXなどのソケットの形式を指定
    //   PF_INETはipv4のこと
    //   PF_*とAF_*は同じもの、どちらでもOK
    // typeはSOCK_STREAM,SOCK_DGRAMなどで、プロトコルに依存する
    //   TCPならSOCK_STREAM、UDPならSOCK_DGRAM UNIXソケットならどちらも可
    // protocolは基本0だが以下も設定できる
    //   IPPROTO_TCP  TCP/IP(AF_INET&SOCK_STREAMの場合。0も可。)
    //   IPPROTO_UDP  UDP/IP(AF_INET&SOCK_DGRAMの場合。0も可。)
    //   IPPROTO_RAW
    // (pingコマンドなど。AF_INET&SOCK_RAWでICMPソケットを作りたい場合)
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);
    // PF_INETだからを使う。PF_UNIXはsockaddr_unを使う
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    // sortを引数にしてportを取得するhtonl(long)もある
    name.sin_port = (in_port_t)htons(30000);
    //要求を受け付けるアドレスを指定する
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    // portを再利用する
    int reuse = 1;
    // int setsockopt(int sockfd, int level, int optname,
    //                const void *optval, socklen_t optlen);
    //  levelは普通のプログラムの場合はSOL_SOCKETを指定すればいいみたい
    if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse,
                   sizeof(int)) == -1)
        error("Can't set the reuse option on the socket");
    // sockaddrはsockaddr_inの親の型みたいなもん
    if (bind(listener_d, (struct sockaddr *)&name, sizeof(name)) == -1)
        error("Can't bind the port");
    //接続待ち,10こまでキューにいれる設定(それ以降はクライアントはエラーになる)
    if (listen(listener_d, 10) == -1) error("listenできません");
    puts("Waiting for connection");
    for (;;) {
        struct sockaddr_storage client_addr;
        unsigned int address_size = sizeof client_addr;
        //ソケットは双方向
        int connect_d =
            accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
        if (connect_d == -1) error("acceptできません");
        char *msg = advice[rand() % 5];
        if(send(connect_d, msg, strlen(msg), 0) == -1) error("sendできません");
        close(connect_d);
    }
    return 0;
}
