#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum response_type { DUMP, SECOND_CHANCE, MARRIAGE };
typedef struct {
    char* name;
    enum response_type type;
} response;

void dump(response r)
{
    printf("%sさんへ、\n", r.name);
    puts("前回のデートの結果、");
    puts("再度お会いすることはないという連絡を受けました。");
}

void second_change(response r)
{
    printf("%sさんへ、\n", r.name);
    puts("いいお知らせです。前回のデートの結果、");
    puts("もう一度お会いしたいとの連絡を受けました。至急ご連絡ください。");
}

void marriage(response r)
{
    printf("%sさんへ、\n", r.name);
    puts("おめでとうございます！前回のデートの結果、");
    puts("結婚を申し込みたいとの連絡を受けました。");
}

void (*replies[])(response) = {dump, second_change, marriage};
int main()
{
    response rs[] = {{"マイク", DUMP},
                     {"ルイス", SECOND_CHANCE},
                     {"マット", SECOND_CHANCE},
                     {"ウィリアム", MARRIAGE}};
    int i;
    for (i = 0; i < 4; i++) {
        //fn() と(*fn)()は同じ
        (replies[rs[i].type])(rs[i]);
        //(*replies[rs[i].type])(rs[i]);
        puts("");
    }
    return 0;
}
