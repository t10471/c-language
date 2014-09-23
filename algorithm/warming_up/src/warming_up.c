/*
 ============================================================================
 Name        : algorithm.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
// #include <tchar.h>
#include <math.h>

/* 漸化式 */
void recurrence_relation();
long combi(int, int);
void horner();
double fn(double x, double a[], int n);
void pascal();
void histogram();
void cryptography();
void bit();
void order();
void order_mod();
void order_negative();
void order_random();
int irnd(int);
void order_random_mod();
void monte_carlo();
double rnd();
void monte_carlo_ellipse();
void euclid1();
void euclid2();
void eratosthenes1();
void eratosthenes2();
void eratosthenes3();
void prime_decomposition();
int main(void) {
    recurrence_relation();
    horner();
    pascal();
    histogram();
    cryptography();
    bit();
    order();
    order_mod();
    order_negative();
    order_random();
    order_random_mod();
    monte_carlo();
    monte_carlo_ellipse();
    /*
    euclid1();
    euclid2();
    eratosthenes1();
    eratosthenes2();
    eratosthenes3();
    prime_decomposition();
    */
    return 0;
}

void recurrence_relation(){
    int n, r;
    for(n = 0; n <= 5; n++){
        for(r = 0; r <= n; r++){
            printf("%d C %d = %ld  ", n, r, combi(n, r));
        }
        printf("\n");
    }
}

/*
 * オーバーフローさせないため
 * に少しずつ計算する
 * nCr = n! / r!(n - r)!
 * n!でオーバーフロー
 * nCr = (n - r + 1 / r) * nCr-1
 * nC0 = 1
 */
long combi(int n, int r){
    int i;
    long p = 1;
    for(i = 1; i <= r; i++){
        p = p * (n - i + 1) / i;
    }
    return p;
}

void horner(){
    /* 係数 */
    double a[] = {1,2,3,4,5};
    double x;
    for(x = 1; x <= 5; x++){
        printf("fn(%f)=%f\n", x, fn(x,a,4));
    }
}

/*
 * 5xxxx + 4xxx + 3xx + 2x + 1
 * 上を普通に計算するより
 * 下で計算したほうが計算量が少ない
 * ((((5 * x + 4)  * x + 3) * x + 2) * x + 1)
 * 5x + 4
 * 5xx + 4x + 3
 * 5xxx + 4xx + 3x
 * てな具合になる
 */
double fn(double x, double a[], int n){
    double p;
    int i;
    p = a[n];
    for(i = n -1; i >= 0; i--){
        p = p * x + a[i];
    }
    return p;
}
/*
 * nCr = n-1Cr-1 + n-1Cr
 */
void pascal(){
    int n, r ,t;
    int N = 12;
    for(n = 0; n <= N; n++){
        for(t = 0; t < (N -n); t++)
                printf("   ");
        for(r = 0; r <= n; r++)
                printf("%3ld   ", combi(n, r));
        printf("\n");
    }
}

/*
 * 写像
 * 100分立から10分立に
 */
void histogram(){
    int input[] = {35, 25, 56, 78, 43, 66, 71, 73, 80, 90,
                0, 73, 35, 65,100, 78, 80, 85, 35, 50};
    int i, rank, histo[11];

    for(i = 0; i < 10; i++){
        histo[i] = 0;
    }
    for(i = 0; i < 20; i++){
        rank = input[i] / 10;
        if(0 <= rank && rank <= 10){
            histo[rank]++;
        }
    }
    for(i = 0; i <= 10; i++){
        printf("%3d - :%3d\n", i*10, histo[i]);
    }
}

/*
 * 暗号
 *
 */
void cryptography(){
    char table[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O',
                    'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J' ,'K',
                    'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '?'};
    char *p, *ango = "KSOIDHEPZ";
    int index;
    p = ango;
    while( *p != '\0'){
        if('A' <= *p && *p <= 'Z'){
            index = *p - 'A';
        }else{
            index = 26;
        }
        putchar(table[index]);
        p++;

    };
    printf("\n");
}


/*
 * &   a = b & 0x4F    ビットAND
 * |   a = b | 0x0F    ビットOR
 * ^   a = b ^ 0xFF    ビットXOR
 * ~   a = ~a  ビットNOT
 * <<= a = a << 2  左シフト
 * >>= a = a >> 2  右シフト
 *
 */
void bit(){
    char a = 'a';
    printf("%c", a & 0x4F);/* A */
    printf("%c", a | 0x4F);/* o */
    printf("%c", a ^ 0x4F);/* . */
    printf("%c", (a ^ 0x4F) ^ 0x4F) /* a */;
    printf("\n");
}

void order(){
    int a[] = {56, 25, 67, 88, 100, 61, 55, 67, 76, 56};
    int juni[10];
    int i,j;
    for(i = 0; i < 10; i++){
        juni[i] = 1;
        for(j = 0; j < 10; j++){
            if(a[j] > a[i]){
                juni[i]++;
            }
        }
    }

    printf("  得点  順位 \n");
    for(i = 0; i < 10; i++){
        printf("%6d%6d\n", a[i], juni[i]);
    }
}

/*
 * 100この箱を用意して
 * それをカウントアップし、
 * 順次足すことで順位を得る
 */
void order_mod(){
    int a[] = {56, 25, 67, 88, 100, 61, 55, 67, 76, 56};
    int i, juni[100 + 2];
    for(i = 0; i <= 100; i++){
        juni[i] = 0;
    }
    for(i = 0; i < 10; i++){
        juni[a[i]]++;
    }
    juni[100 + 1] = 1;
    for(i = 100; i >= 0; i--){
        juni[i] = juni[i] + juni[i + 1];
    }
    printf("  得点  順位 \n");
    for(i = 0; i < 10; i++){
        printf("%6d%6d\n", a[i], juni[a[i] + 1]);
    }
}

void order_negative(){
    int a[] = {-3, 2, 3, -1, -2, -6, 2, -1, 1, 5};
    int min = -20;
    int max = 36;
    int bias = 1 - (min);
    int t = max + bias + 1;
    int i;
    int *juni;
    juni = (int *)malloc(sizeof(int) * t);

    for(i = min + bias; i <= max + bias; i++){
        juni[i] = 0;
    }
    for(i = 0; i < 10; i++){
        juni[a[i] + bias]++;
    }
    juni[0] = 1;
    for(i = min + bias; i <= max + bias; i++){
        juni[i] = juni[i] + juni[i - 1];
    }
    printf("  得点  順位 \n");
    for(i = 0; i < 10; i++){
        printf("%6d%6d\n", a[i], juni[a[i] + bias - 1]);
    }
    free(juni);
}

/*
 * 乱数列の取得
 */
void order_random(){
    int i, j, flag, a[21];
    a[1] = irnd(20);
    for(i = 2; i <= 20; i++){
        do{
            a[i] = irnd(20);
            flag = 0;
            /* すでにgetしていたらもう一度 */
            for(j = 1; j < i; j++){
                if(a[i] == a[j]){
                    flag = 1;
                    break;
                }
            }
        }while(flag == 1);
    }

    for(i = 1; i <= 20; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int irnd( int n){
    return (int)(rand() / (RAND_MAX + 0.1) * n +1);
}

void order_random_mod(){
    int i, j, d, a[21];
    for(i = 1; i <= 20; i++){
        a[i] = i;
    }
    for(i = 20; i > 1; i--){
        j = irnd(i - 1);
        d = a[i];
        a[i] = a[j];
        a[j] = d;
    }
    for(i = 1; i <= 20; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}


/*
 * 確率を使って解く
 * 1/4円の面積は4/π
 * 正方形の面積は1
 * 4/π : 1 = a : a + b
 * a + b = 1000
 * in = a
 * π = 4 * in / 1000
 */
void monte_carlo(){
    double x, y, pai;
    int i, in = 0;
    for(i = 0; i < 1000; i++){
        x = rnd();
        y = rnd();
        if(x * x + y * y < 1){
            in++;
        }
    }
    pai = (double) 4 * in / 1000;
    printf("πの値 = %f\n", pai);
}

double rnd(){
    return (double) rand() / (RAND_MAX + 0.1);
}

/*
 * 楕円の面積
 * x^2 / 4 + y^2 = 1
 * sは楕円の面積
 * 2 : s = n : a
 * n = 1000
 * 長方形 : 楕円 = n : a
 * s = 2a / 1000
 * s = 4 * 2a / 1000
 * 4は1/4だから
 *
 */
void monte_carlo_ellipse(){
    double x, y, s;
    int i, in = 0;
    for(i = 0; i < 1000; i++){
        x = 2 * rnd();
        y = rnd();
        if(x * x / 4 + y * y < 1){
            in++;
        }
    }
    s = 4.0 * (2.0 * in / 1000);
    printf("楕円の面積 = %f\n", s);
}

void euclid1(){

    int a, b, m , n;

    printf("二つの数字を入力してください");
    scanf("%d %d", &a, &b);

    m = a;
    n = b;
    while(m != n){
        if(m > n){
            m = m - n;
        }else{
            n = n - m;
        }
    }
    printf("最大公約数 = %d \n", m);

}

/*
 * a=a'Ｇ
 * b=b'Ｇ
 * b=b''Ｇ'
 * r=r'Ｇ'
 * ①
 * a=bq+r
 * r=a-bq
 * a=a'Ｇ
 * b=b'Ｇ
 * r=a'Ｇ-b'Ｇq
 *  =(a'-b'q)Ｇ
 * r=r'Ｇ'
 * Ｇ' = Ｇ
 * ②
 * b=b''Ｇ'
 * r=r'Ｇ'
 * a=bq+r
 * =b''Ｇ'q+r'Ｇ'
 * =(b''q+r')Ｇ'
 * a=a'Ｇ
 * Ｇ' = Ｇ
 */
void euclid2(){

    int a, b, m , n, k;

    printf("二つの数字を入力してください");
    scanf("%d %d", &a, &b);

    m = a;
    n = b;
    do{
        k = m % n;
        m = n;
        n = k;
    }while(k != 0);
    printf("最大公約数 = %d \n", m);
}

void eratosthenes1(){
    int i, n, limit;
    /* ctr + z で終了 */
    while(printf("data? "), scanf("%d", &n) != EOF){
        if(n >= 2){
            /*√nから調べればよい*/
            limit = (int)sqrt((double)n);
            for(i = limit; i > 1; i--){
                if(n % i == 0) break;
            }
            printf("%d は", n);
            if(i == 1){
                printf("素数 \n");
            }else{
                printf("素数ではない \n");
            }
        }
    }
}

void eratosthenes2(){
    int i, n,  m= 0, limit;
    int num = 1000;
    int *prime;
    prime = (int *)malloc(sizeof(int) * (num / 2 + 1));

    for(n = 2; n < num; n++){
        limit = (int)sqrt((double)n);
        for(i = limit; i > 1; i--){
            if(n % i == 0){
                break;
            }
        }
        if(i == 1){
            prime[m++] = n;
        }
    }
    printf("求められた素数 \n");
    for(i = 0; i < m; i++){
        printf("%5d", prime[i]);
    }
    printf("\n");
    free(prime);
}
/*
 * ステップ 1
 * 整数を最初の素数である 2 から昇順で探索リストに羅列する。
 * 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
 * ステップ 2
 * リストの先頭の数を素数リストに記録する。
 * 素数リスト：2
 * 探索リスト：2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
 * ステップ 3
 * 前のステップで素数リストに加えられた数の全ての倍数を、探索リストから削除する。
 * 素数リスト：2
 * 探索リスト：3 5 7 9 11 13 15 17 19
 * ステップ 4
 * 探索リストの最大値が素数リストの最大値の平方よりも小さい場合、素数リストおよび探索リストに残っている数が素数となる。探索リストの最大値が素数リストの最大値の平方よりも大きい場合、ステップ 2 に戻る。
 * 19 は 2 の平方よりも大きいので、ステップ 2 に戻る。
 * ステップ 2
 * 素数リスト：2 3
 * 探索リスト：3 5 7 9 11 13 15 17 19
 * ステップ 3
 * 素数リスト：2 3
 * 探索リスト：5 7 11 13 17 19
 * ステップ 4
 * 19 は 3 の平方よりも大きいので、ステップ 2 に戻る。
 * ステップ 2
 * 素数リスト：2 3 5
 * 探索リスト：5 7 11 13 17 19
 * ステップ 3
 * 素数リスト：2 3 5
 * 探索リスト：7 11 13 17 19
 * ステップ 4
 * 19 は 5 の平方よりも小さいので、リストに残っている数が素数である。
 * 結果：2 から 20 までの数に含まれる素数は、
 * 2 3 5 7 11 13 17 19
 */
void eratosthenes3(){
    int i, j, limit;
    int num = 1000;
    int *prime;
    prime = (int *)malloc(sizeof(int) * (num + 1));

    for(i = 2; i <= num; i++){
        prime[i] = 1;
    }
    limit = (int)sqrt((double)num);
    for(i = 2; i <= limit; i++){
        if(prime[i] == 1){
            for(j = 2 * i; j <= num; j++){
                if(j % i ==  0){
                    prime[j] = 0;
                }
            }
        }
    }
    printf("求められた素数 \n");
    for(i = 2; i < num; i++){
        if(prime[i] ==  1){
            printf("%5d", i);
        }
    }
    printf("\n");
    free(prime);
}


void prime_decomposition(){
    int a, n;
    while(printf("data? "), scanf("%d", &n) != EOF){
        a = 2;
        while( n >= a * a){
            if(n % a == 0){
                printf("%d * ", a);
                n = n /a;
            }else{
                a++;
            }
        }
        printf("%d\n", n);
    }

}
