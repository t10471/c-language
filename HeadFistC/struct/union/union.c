#include <stdio.h>

typedef union {
    short count;
    float weight;
    float volume;
} quantity;

typedef struct {
    const char* color;
    int gears;
    int height;
} bike;

typedef struct {
    const char* name;
    const char* e;
    quantity amount;
} fruit_order;

void test_quantitiy()
{
    // countとして初期化
    quantity q1 = {4};
    //指示付き初期化子(C++ではつかえない)
    quantity q2 = {.weight = 1.5};
    quantity q3;
    q3.volume = 3.7;
    // floatの4バイトがquantityのサイズ
    printf("q1 sizeof %lu\n", sizeof q1);
    printf("q1.count  %hi sizeof %lu\n", q1.count, sizeof q1.count);
    printf("q1.weight %f sizeof %lu\n", q1.weight, sizeof q1.weight);
    printf("q1.volume %f sizeof %lu\n", q1.volume, sizeof q1.volume);
    printf("q2 sizeof %lu\n", sizeof q2);
    printf("q2.count  %hi sizeof %lu\n", q2.count, sizeof q2.count);
    printf("q2.weight %f sizeof %lu\n", q2.weight, sizeof q2.weight);
    printf("q2.volume %f sizeof %lu\n", q2.volume, sizeof q2.volume);
    printf("q3 sizeof %lu\n", sizeof q3);
    printf("q3.count  %hi sizeof %lu\n", q3.count, sizeof q3.count);
    printf("q3.weight %f sizeof %lu\n", q3.weight, sizeof q3.weight);
    printf("q3.volume %f sizeof %lu\n", q3.volume, sizeof q3.volume);
}

void test_bike()
{
    //指示付き初期化子は構造体でも使用できる
    bike b = {.height = 17, .gears = 21};
    printf("b.color %s  b.height %d b.gears %d\n", b.color, b.height, b.gears);
    printf("b.color %p  b.height %p b.gears %p\n", b.color, &b.height,
           &b.gears);
    b.color = "red";
    printf("b.color %s  b.height %d b.gears %d\n", b.color, b.height, b.gears);
    printf("b.color %p  b.height %p b.gears %p\n", b.color, &b.height,
           &b.gears);
}

void test_fruit_order()
{
    //構造体のなかでunionを使用
    fruit_order apples = {"リンゴ", "イギリス", .amount.weight = 4.2};
    printf("この注文には%2.2fポンドの%sが含まれています\n",
           apples.amount.weight, apples.name);
}

int main()
{
    test_quantitiy();
    test_bike();
    test_fruit_order();
}
