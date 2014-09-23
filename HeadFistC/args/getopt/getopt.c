#include <stdio.h>
#include <unistd.h>
/* 
:QuickRun -args "Anchovies Pineapple"
:QuickRun -args "-d now Anchovies Pineapple"
:QuickRun -args "-d now -t Anchovies Pineapple"
:QuickRun -args "-d"
*/

int main(int argc, char* args[])
{
    char* delivery = "";
    int thick = 0;
    int count = 0;
    char ch;
    //引数をとるオプションには:をつける
    while ((ch = getopt(argc, args, "d:t")) != EOF) {
        switch (ch) {
            case 'd':
                //引数取得
                delivery = optarg;
                break;
            case 't':
                thick = 1;
                break;
            default:
                fprintf(stderr, "Unknown option: '%s'\n", optarg);
                return 1;
        }
    }
    //読み込んだ分の引数をスキップする
    argc -= optind;
    args += optind;

    if (thick) puts("Thick crust.");

    if (delivery[0]) printf("To be delivered %s.\n", delivery);

    puts("Ingredients:");

    for (count = 0; count < argc; count++) puts(args[count]);
    return 0;
}
