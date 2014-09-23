#include <stdio.h>

typedef union {
    float lemon;
    int lime_pieces;
} lemon_lime;

typedef struct {
    float tequila;
    float cointreau;
    lemon_lime citrus;
} margarita;

void show_margarita_float(margarita m)
{
    puts("");
    printf(
        "%2.1f単位のテキーラ\n%2.1f単位のコアントロー\n%2.1f単位のジュース\n",
        m.tequila, m.cointreau, m.citrus.lemon);
}

void show_margarita_int(margarita m)
{
    puts("");
    printf(
        "%2.1f単位のテキーラ\n%2.1f単位のコアントロー\n%d切れのライム\n",
        m.tequila, m.cointreau, m.citrus.lime_pieces);
}

void test_margarita()
{
    //全てOK
    //intだけど共用体に最初かfloatなのでfloatになる
    margarita m1 = {2.0, 1.0, {2}};
    show_margarita_float(m1);
    margarita m2 = {2.0, 1.0, {0.5}};
    show_margarita_float(m2);
    margarita m3 = {2.0, 1.0, {.lime_pieces = 1}};
    show_margarita_int(m3);
    margarita m4 = {2.0, 1.0, .citrus.lemon = 2};
    show_margarita_float(m4);
    margarita m5 = {2.0, 1.0, 0.5};
    show_margarita_float(m5);
    margarita m6 = {2.0, 1.0, {1}};
    show_margarita_float(m6);
    
    //変数の宣言時しか{}を使った代入はできない
    //margarita m7;
    //m7 = {2.0, 1.0, {1}};
}

int main()
{
    test_margarita();
}
