#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>


//socketでソケットを作成
//connectでリモートのソケットに接続
//send, recvでソケットを使ってやり取り
//closeでソケットを閉じる
void error(char* msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int open_socket(char* host, char* port)
{
    struct addrinfo* res;
    struct addrinfo hints;
    //hintsを0で初期化する
    memset(&hints, 0, sizeof(hints));
    //PF_UNSPECを指定するとIPV4かIPV6のソケットアドレスを返す
    hints.ai_family = PF_UNSPEC;
    //TCPだからSOCK_STREAM,UDPならSOCK_DGRAM
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(host, port, &hints, &res) == -1)
        error("Can't resolve the address");
    int d_sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (d_sock == -1) error("Can't open socket");
    int c = connect(d_sock, res->ai_addr, res->ai_addrlen);
    //ネーミングリソースは閉じる
    freeaddrinfo(res);
    if (c == -1) error("Can't connect to socket");
    return d_sock;
}

int say(int socket, char* s)
{
    int result = send(socket, s, strlen(s), 0);
    if (result == -1)
        fprintf(stderr, "%s: %s\n", "Error talking to the server",
                strerror(errno));
    return result;
}

int main(int argc, char* argv[])
{
    //if(strlen(argv[1]) == 0) argv[1] = "O'Reilly_Media";
    if(!argv[1]) argv[1] = "O'Reilly_Media";
    printf("argv[1] = %s\n", argv[1]);
    int d_sock = open_socket("en.wikipedia.org", "80");
    char buf[255];
    sprintf(buf, "GET /wiki/%s http/1.1\r\n", argv[1]);
    say(d_sock, buf);
    say(d_sock, "Host: en.wikipedia.org\r\n\r\n");
    char rec[256];
    int bytesRcvd = recv(d_sock, rec, 255, 0);
    while (bytesRcvd) {
        if (bytesRcvd == -1) error("Can't read from server");
        rec[bytesRcvd] = '\0';
        printf("rec %s", rec);
        bytesRcvd = recv(d_sock, rec, 255, 0);
    }
    close(d_sock);
    return 0;
}
