/*
 ============================================================================
 Name        : algorithm_2_numeric_calculation.c
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


void uniform_random_number();
unsigned rndnum = 13;
unsigned irnd();
void chi_square_test();
double rnd();
void box_muller();
void brnd(double, double, double *, double *);
void test();
void test2(int *);
/* 積分 */
void trapezoid();
void simpson();
/* 関数 */
void taylor();
double myexp(double);
void taylor_ex();
double myexp_ex(double);
void taylor_cos();
double mycos(double);
/* 値 */
void bisection();
double func(double);
void newton();
double funcf(double);
double funcg(double);
/* 補完 */
void lgrange_interpolation();
double lgrange_interpolation_main(double *, double *, int, double);
void newton_interpolation();
double newton_interpolation_main(double *, double *, int, double);
/* 多桁計算 */
void long_calc();
void print(short *);
void long_calc2();
void ladd(short *,   short *, short *);
void lsub(short *,   short *, short *);
void lmul(short *,   short,   short *);
void llldiv(short *, short,   short *);
void printresult(short *);
void pai();
void pladd(short *,   short *, short *);
void plsub(short *,   short *, short *);
void pllldiv(short *, short,   short *);
void flmul(short *,   short,   short *);
void factorial();
void printresult2(short *);
/*連立方程式 */
void gauss_jordan();
void mod_gauss_jordan();
void gaussian_elimination();

/**/
void linear_programming();
void least_squares_method();
double ipow(double, int);

int main() {
    uniform_random_number();
    chi_square_test();
    box_muller();
    test();
    trapezoid();
    simpson();
    taylor();
    taylor_ex();
    taylor_cos();
    bisection();
    newton();
    lgrange_interpolation();
    newton_interpolation();
    long_calc();
    long_calc2();
    pai();
    factorial();
    gauss_jordan();
    mod_gauss_jordan();
    gaussian_elimination();
    linear_programming();
    least_squares_method();
    printf("end\n");
    return 0;
}
/*
 * 一様乱数
 * x(n) = (Ax(n-1) + C) mod M
 * 0 ~ Mまでの乱数を発生させる
 */
void uniform_random_number(){
    int j;
    for(j = 0; j < 100; j++){
        printf("%8d", irnd());
    }
    printf("\n");
}

unsigned irnd(){
    rndnum = (rndnum * 109 + 1021) % 32768;
    return rndnum;
}

double rnd(){
    return irnd() / 32767.1;
}

/*
 * カイ二乗検定
 * x^2 = Σ(f - F)^2 / F
 * fが発生回数、Fが期待値
 * 今回は期待値は1000/10
 * 1～10の乱数なので自由度10 - 1 = 9
 */
void chi_square_test(){
    int i, j, rank, hist[11];
    double e = 0.0;
    for (i = 1; i <= 10; i++){
        hist[i] = 0;
    }
    for (i = 1; i < 1000; i++){
        rank = (int)(10 * rnd() + 1);
        hist[rank]++;
    }
    for (i = 1; i <= 10; i++){
        printf("%3d:%3d ", i, hist[i]);
        for(j = 0; j < hist[i] * (40.0 / (1000 / 10)); j++){
            printf("*");
        }
        printf("\n");
        e = e + (double)(hist[i] - (1000 / 10)) * (hist[i] - (1000 / 10)) / (1000 / 10);
    }
    printf("x 2 = %f\n", e);

}

/*
 * ボックスミューラー法
 * 正規分布の乱数を生成
 */
void box_muller(){
    int hist[100];
    int i;
    int j;
    double x, y;
    for(i = 0; i < 100; i++){
        hist[i] = 0;
    }
    for(i = 0; i < 1000; i++){
        brnd(2.5, 10.0, &x, &y);
        hist[(int)x]++;
        hist[(int)y]++;
    }
    for(i = 0; i <= 20; i++){
        printf("%3d : I ", i);
        for(j = 1; j <= hist[i] / 10; j++){
            printf("*");
        }
        printf("\n");
    }
}

/*
 * sigが正規分布の分散、
 * mが平均
 *
 */
void brnd(double sig, double m , double *x, double *y){
     double r1, r2, r3;

     r1 = (double)rand()/RAND_MAX;
     while( r1 == 0.0 ){
        r1 = (double)rand()/RAND_MAX;
     }
     r2 = (double)rand()/RAND_MAX;

     *x = sig * sqrt( -2.0 * log(r1)) * cos(2.0 * 3.14159 * r2) + m;
     *y = sig * sqrt( -2.0 * log(r1)) * sin(2.0 * 3.14159 * r2) + m;
}

void test(){
     int i = 1;
     /* 参照渡し */
     test2(&i);
     printf("%d \n",i);
     test2(&i);
     printf("%d \n",i);
}

 /* アスタリスクつきが値
  * アスタリスクなしがポインタ
  */
void test2(int *x){
    printf("%d, %d \n", *x, *x);
    *x = 12;
}

/*
 * 積分
 * 台形則
 * 関数を台形に分割して足す
 * 直線として近似
 * 初項と最後の項以外は2つづつ出現
 */
void trapezoid(){
    int k;
    double a, b, n, h, x, s, sum;
    /*
    printf("積分区間 A, B ?");
    scanf("%lf %lf", &a, &b);
    */
    a = 0;
    b = 2;
    n = 50; /* 分割数 */
    h = (b - a) / n; /* 台形の高さ */
    x = a;
    s = 0;
    /*
     * 関数
     * sqrt(4 - x * x)
     */
    for(k = 1; k <= n - 1; k++){
        x = x + h;
        /* 真ん中の項の計算 */
        s = s + (sqrt(4 - x * x));
    }
    sum = h *
            (
              (
                /* 初項と最後の項 */
                (sqrt(4 - a * a)) + (sqrt(4 - b * b))
              ) / 2
              + s
            );
    printf("    /%f\n", b);
    printf("    sqrt(4 - x * x) = %f\n", sum);
    printf("    /%f\n", a);
}

/*
 * 積分
 * 二次曲線で近似する
 * シンプソン則
 */
void simpson(){
    int k;
    double a, b, n, h, fo, fe, sum, t;
    a = 0;
    b = 2;
    n = 50; /* 分割数 */
    h = (b -a) /(n * 2); /* 区間幅 */
    fo = 0; /* 偶数項の合計 */
    fe = 0; /* 奇数項の合計 奇数項のほうが1項多い*/
    for(k = 1; k <= 2 * n - 3; k = k + 2){
        t = (a + h * k);
        fo =  fo + sqrt(4 - t * t);
        t = (a + h * (k + 1));
        fe = fe + sqrt(4 - t * t);
    }
    t = b - h;
    sum = ((sqrt(4 - a * a)) + (sqrt(4 - b * b))
            + 4 * (fo + sqrt(4 - t * t) )
            + 2 * fe)
          * h / 3;
    printf("    /%f\n", b);
    printf("    sqrt(4 - x * x) = %f\n", sum);
    printf("    /%f\n", a);

}

/*
 * e^xをテイラー展開で計算する
 */
void taylor(){
    double x;
    printf("    x      myexp(x)        exp(x)\n");
    for(x = 0; x <= 40; x = x + 10){
        printf("%5.1f%14.6g%14.6g\n", x, myexp(x), exp(x));
    }
}

/*
 * k-1項までの和をd、k項までの和をsとしたとき
 * |s - d|/ |d| < EPS
 * となったときに打ち切る
 * EPSを 1e - 8 とすると精度8桁程度になる
 */
double myexp(double x){
    double EPS = 1e-08;
    double s = 1.0, e = 1.0, d;
    int k;
    for(k = 1; k <= 200; k++){
        d = s;
        e = e * x / k;
        s = s + e;
        if(fabs(s - d) < EPS * fabs(d)){ /* 打ち切り誤差 */
            return s;
        }
    }
    return 0.0; /* 収束しないとき */
}

/*
 * e^xをテイラー展開で計算するマイナス乗対応
 */
void taylor_ex(){
    double x;
    printf("    x      myexp(x)        exp(x)\n");
    for(x = -40; x <= 40; x = x + 10){
        printf("%5.1f%14.6g%14.6g\n", x, myexp_ex(x), exp(x));
    }
}

/*
 * k-1項までの和をd、k項までの和をsとしたとき
 * |s - d|/ |d| < EPS
 * となったときに打ち切る
 * EPSを 1e - 8 とすると精度8桁程度になる
 */
double myexp_ex(double x){
    double EPS = 1e-08;
    double s = 1.0, e = 1.0, d, a;
    int k;
    a = fabs(x);
    for(k = 1; k <= 200; k++){
        d = s;
        e = e * a / k;
        s = s + e;
        if(fabs(s - d) < EPS * fabs(d)){ /* 打ち切り誤差 */
            /* マイナスのときは逆数にする e^-x ~ 1/ e^x*/
            if(x > 0){
                return s;
            }else{
                return 1.0 / s;
            }
        }
    }
    return 0.0; /* 収束しないとき */
}

/*
 * e^xをテイラー展開で計算するマイナス乗対応
 */
void taylor_cos(){
    double x, rd = 3.14159 / 180;
    printf("    x      mycos(x)        cos(x)\n");
    for(x = 0; x <= 180; x = x + 10){
        printf("%5.1f%14.6g%14.6g\n", x, mycos(x*rd), cos(x*rd));
    }
}

/*
 * k-1項までの和をd、k項までの和をsとしたとき
 * |s - d|/ |d| < EPS
 * となったときに打ち切る
 * EPSを 1e - 8 とすると精度8桁程度になる
 */
double mycos(double x){
    double EPS = 1e-08;
    double s = 1.0, e = 1.0, d;
    int k;
    x = fmod(x, 2 * 3.14159265358979); /* xの値を0～2πに収める */
    for(k = 1; k <= 200; k=k+2){
        d = s;
        e = -e * x * x / (k * (k + 1));
        s = s + e;
        if(fabs(s - d) < EPS * fabs(d)){ /* 打ち切り誤差 */
            return s;
        }
    }
    return 9999.0; /* 収束しないとき */
}

void bisection(){
    double low, hight, x;
    int k;
    double EPS = 1e-08; /* 打切り誤差 */
    int limit = 50; /* 打切り回数 */
    low = -2.0;
    hight = 2.0;
    for(k = 1; k <= limit; k++){
        x = (low + hight) / 2;
        if(func(x) > 0){
            hight = x;
        }else{
            low = x;
        }
        if(func(x) == 0 || fabs(hight - low) < fabs(low) * EPS){
            printf("x=%f\n", x);
            break;
        }
    }
    if(k > limit){
        printf("収束しない\n");
    }
}
double func(double x){
    return (x * x * x - x + 1);
}

void newton(){
    int k;
    double EPS = 1e-08; /* 打切り誤差 */
    int limit = 50; /* 打切り回数 */
    double x = -2.0, dx;

    for(k = 1; k <= limit; k++){
        dx = x;
        x = x - funcf(x) / funcg(x);
        if(fabs(x - dx) < fabs(dx) * EPS){
            printf("x=%f\n", x);
            break;
        }
    }
    if(k > limit){
        printf("収束しない\n");
    }
}
double funcf(double x){
    return (x * x * x - x +1);
}
/*
 * funcfの微分
 */
double funcg(double x){
    return (3 * x * x - x);
}


/*
 * ラグランジュの補完法
 */
void lgrange_interpolation(){
    double x[] = {0.0, 1.0, 3.0, 6.0, 7.0},
           y[] = {0.8, 3.1, 4.5, 3.9, 2.8};
    double t;
    printf("      x      y\n");
    for(t = 0.0; t <= 7.0; t = t + 0.5){
        printf("%7.2f%7.2f\n", t, lgrange_interpolation_main(x, y, 5, t));
    }

}

double lgrange_interpolation_main(double x[], double y[], int n, double t){

    int i, j;
    double s, p;

    s = 0.0;
    for(i = 0; i < n; i++){
        p = y[i];
        for(j = 0; j< n; j++){
            if(i != j){
                p = p * (t - x[j]) / (x[i] - x[j]);
            }
        }
        s = s + p;
    }
    return s;
}

/*
 * ニュートンの補完法
 * ラグランジュより計算量が少ない
 */
void newton_interpolation(){
    double x[] = {0.0, 1.0, 3.0, 6.0, 7.0},
           y[] = {0.8, 3.1, 4.5, 3.9, 2.8};
    double t;
    printf("      x      y\n");
    for(t = 0.0; t <= 7.0; t = t + 0.5){
        printf("%7.2f%7.2f\n", t, newton_interpolation_main(x, y, 5, t));
    }

}

double newton_interpolation_main(double x[], double y[], int n, double t){

    static int flag = 1;
    static double a[100];
    double w[100],  /* 係数配列 */
           s;       /* 作業用 */
    int i, j;

    if(flag == 1){ /* 1度目に呼ばれたときだけ a[]に係数を求める */
        for(i = 0; i < n; i++){
            w[i] = y[i];
            for(j = i - 1; j >= 0; j--){
                w[j] = (w[j + 1] - w[j]) / (x[i] -  x[j]);
            }
            a[i] = w[0];
        }
        flag = -1;
    }
    s = a[n - 1];
    for(i = n - 2; i >= 0; i--){
        s = s * (t - x[i]) + a[i];
    }
    return s;
}


void long_calc(){
    short keta = 20;
    short n = (keta - 1) / 4 + 1;
    short *a;
    short *b;
    short *c;
    a = (short *)malloc(sizeof(short) * (n + 2));
    b = (short *)malloc(sizeof(short) * (n + 2));
    c = (short *)malloc(sizeof(short) * (n + 2));
    a[0] = 1999;
    a[1] = 4444;
    a[2] = 7777;
    a[3] = 2222;
    a[4] = 9999;
    b[0] =  111;
    b[1] = 6666;
    b[2] = 3333;
    b[3] = 8888;
    b[4] = 1111;

    ladd(a, b, c);
    print(c);
    lsub(a, b, c);
    print(c);
    free(a);
    free(b);
    free(c);
}

void ladd(short a[], short b[], short c[]){
    int keta = 20;
    int n = (keta - 1) / 4 + 1;
    short i, cy = 0;
    for(i = n -1; i >= 0; i--){
        c[i] = a[i] + b[i] + cy;
        if(c[i] < 10000){
            cy = 0;
        }else{
            c[i] = c[i] - 10000;
            cy = 1;
        }
    }
}

void lsub(short a[], short b[], short c[]){
    int keta = 20;
    int n = (keta - 1) / 4 + 1;
    short i, brrw = 0;
    for(i = n -1; i >= 0; i--){
        c[i] = a[i] - b[i] - brrw;
        if(c[i] >= 0){
            brrw = 0;
        }else{
            c[i] = c[i] + 10000;
            brrw = 1;
        }
    }
}

void print (short c[]){
    int keta = 20;
    int n = (keta - 1) / 4 + 1;
    int i;
    for(i = 0; i < n; i++){
        printf("%04d ", c[i]);
    }
    printf("\n");
}

void long_calc2(){
    short keta = 20;
    short n = (keta - 1) / 4 + 1;
    short *a;
    short *c;
    short *x;
    a = (short *)malloc(sizeof(short) * (n + 2));
    c = (short *)malloc(sizeof(short) * (n + 2));
    x = (short *)malloc(sizeof(short) * (n + 2));
    a[0] = 0;
    a[1] = 3050;
    a[2] = 2508;
    a[3] = 8080;
    a[4] = 1233;

    lmul(a, 101, c);
    print(c);
    llldiv(a, 200, x);
    print(x);
    free(a);
    free(c);
    free(x);
}

void lmul(short a[], short b, short c[]){
    int keta = 20;
    int n = (keta - 1) / 4 + 1;
    short i;
    long d, cy = 0;
    for(i = n -1; i >= 0; i--){
        d = a[i];
        c[i] = (d * b + cy) % 10000;
        cy = (d * b + cy) / 10000;
    }
}

void llldiv(short a[], short b, short x[]){
    int keta = 20;
    int n = (keta - 1) / 4 + 1;
    short i;
    long d;
    long rem = 0;
    for(i = 0; i < n; i++){
        d = a[i];
        x[i] = (short)((d + rem) / b);
        rem = ((d + rem) % b) * 10000;
    }
}

void pai(){
	short *s;
	short *w;
	short *v;
	short *q;
	short k;
	int  l = 1000;
	int  l1 = (l / 4) + 1;
	int  l2 = l1 + 1;
	/* l / 2log5 = l / 1.39794*/
	short n = (short)(l / 1.39794 + 1);
    s = (short *)malloc(sizeof(short) * (l2 + 2));
    w = (short *)malloc(sizeof(short) * (l2 + 2));
    v = (short *)malloc(sizeof(short) * (l2 + 2));
    q = (short *)malloc(sizeof(short) * (l2 + 2));
    for(k = 0; k <= l2; k++){
    	s[k] = w[k] = v[k] = q[k] = 0;
	}
    /* マチンの公式 */
    w[0] = 16 * 5;
    v[0] = 4 * 239;

    for(k = 1; k <= n; k++){
    	pllldiv(w, 25, w);
    	pllldiv(v, 239, v);
    	pllldiv(v, 239, v);
    	plsub(w, v, q);
    	pllldiv(q, 2 * k - 1, q);
    	if(k % 2 != 0){
    		pladd(s, q, s);
    	}else{
    		plsub(s, q, s);

    	}
	}
    printresult(s);

}

void printresult(short c[]){
	short i;
	int  l = 1000;
	int  l1 = (l / 4) + 1;
	printf("%3d. ", c[0]);
	for(i = 1; i < l1; i++){
		if(i % 6 == 0){
			printf("\n");
		}
		printf("%04d ", c[i]);
	}
	printf("\n");
}

void pladd(short a[], short b[], short c[]){
	int  l = 1000;
	int  l1 = (l / 4) + 1;
	int  l2 = l1 + 1;
    short i, cy = 0;
    for(i = l2; i >= 0; i--){
        c[i] = a[i] + b[i] + cy;
        if(c[i] < 10000){
            cy = 0;
        }else{
            c[i] = c[i] - 10000;
            cy = 1;
        }
    }
}

void plsub(short a[], short b[], short c[]){
	int  l = 1000;
	int  l1 = (l / 4) + 1;
	int  l2 = l1 + 1;
    short i, brrw = 0;
    for(i = l2; i >= 0; i--){
        c[i] = a[i] - b[i] - brrw;
        if(c[i] >= 0){
            brrw = 0;
        }else{
            c[i] = c[i] + 10000;
            brrw = 1;
        }
    }
}

void pllldiv(short a[], short b, short x[]){
	int  l = 1000;
	int  l1 = (l / 4) + 1;
	int  l2 = l1 + 1;
    short i;
    long d;
    long rem = 0;
    for(i = 0; i < l2; i++){
        d = a[i];
        x[i] = (short)((d + rem) / b);
        rem = ((d + rem) % b) * 10000;
    }
}

void factorial(){
	int l = 64;
	int l2 = (l + 3) / 4;
	short *s;
    s = (short *)malloc(sizeof(short) * (l2));
    short k;
    for(k = 0; k < l2; k++){
    	s[k] = 0;
    }
    s[l2 -1] = 1;
    /* 49!までの計算 */
    for(k = 1; k <= 49; k++){
    	flmul(s, k, s);
    	printf("%2d!=", k);
    	printresult2(s);

    }
}

void flmul(short a[], short b, short c[]){

	int l = 64;
	int l2 = (l + 3) / 4;
	short i;
    long d, cy = 0;
    for(i = l2 -1; i >= 0; i--){
        d = a[i];
        c[i] = (d * b + cy) % 10000;
        cy = (d * b + cy) / 10000;
    }
}

void printresult2(short c[]){
	short i;
	int l = 64;
	int l2 = (l + 3) / 4;
	for(i = 0; i < l2; i++){
		printf("%04d ", c[i]);
	}
	printf("\n");
}

void gauss_jordan(){
	double a[3][4] = {
			{ 2.0,  3.0,  1.0,  4.0},
			{ 4.0,  1.0, -3.0, -2.0},
			{ -1.0, 2.0,  2.0,  2.0},
	};
	double p, d;
	int i, j ,k;
	for(k = 0; k < 3; k++){
		p = a[k][k]; /*ピボットの場所*/
		for(j = k; j < 4; j++){
			a[k][j] = a[k][j] / p; /*ピボットで割る*/
		}
		for(i = 0; i < 3; i++){
			/* 自分の行以外を計算、過ぎた行も計算する */
			if(i != k){
				d = a[i][k];
				for(j = k; j < 4; j ++){
					p = a[i][j];
					a[i][j] = a[i][j] - d * a[k][j];
					printf("%f =  %f - %f * %f \n",a[i][j], p,  d, a[k][j]);
				}
				/*
				0.000000 =  4.000000 - 4.000000 * 1.000000
				-5.000000 =  1.000000 - 4.000000 * 1.500000
				-5.000000 =  -3.000000 - 4.000000 * 0.500000
				-10.000000 =  -2.000000 - 4.000000 * 2.000000
				0.000000 =  -1.000000 - -1.000000 * 1.000000
				3.500000 =  2.000000 - -1.000000 * 1.500000
				2.500000 =  2.000000 - -1.000000 * 0.500000
				4.000000 =  2.000000 - -1.000000 * 2.000000
				0.000000 =  1.500000 - 1.500000 * 1.000000
				-1.000000 =  0.500000 - 1.500000 * 1.000000
				-1.000000 =  2.000000 - 1.500000 * 2.000000
				0.000000 =  3.500000 - 3.500000 * 1.000000
				-1.000000 =  2.500000 - 3.500000 * 1.000000
				-3.000000 =  4.000000 - 3.500000 * 2.000000
				0.000000 =  -1.000000 - -1.000000 * 1.000000
				2.000000 =  -1.000000 - -1.000000 * 3.000000
				0.000000 =  1.000000 - 1.000000 * 1.000000
				-1.000000 =  2.000000 - 1.000000 * 3.000000
				*/
				/*
				-5.000000 =  1.000000 - 4.000000 * 1.500000
				-5.000000 =  -3.000000 - 4.000000 * 0.500000
				-10.000000 =  -2.000000 - 4.000000 * 2.000000
				3.500000 =  2.000000 - -1.000000 * 1.500000
				2.500000 =  2.000000 - -1.000000 * 0.500000
				4.000000 =  2.000000 - -1.000000 * 2.000000
				-1.000000 =  0.500000 - 1.500000 * 1.000000
				-1.000000 =  2.000000 - 1.500000 * 2.000000
				-1.000000 =  2.500000 - 3.500000 * 1.000000
				-3.000000 =  4.000000 - 3.500000 * 2.000000
				2.000000 =  -1.000000 - -1.000000 * 3.000000
				-1.000000 =  2.000000 - 1.000000 * 3.000000
				for(j = k + 1; j < 4; j ++){
					d = a[i][j];
					a[i][j] = a[i][j] - a[i][k] * a[k][j];
					printf("%f =  %f - %f * %f \n",a[i][j], d,  a[i][k], a[k][j]);
				}
				 */
			}
		}
	}
	for(k = 0; k < 3; k++){
		printf("x%d=%f", k + 1, a[k][3]);
	}
	printf("\n");
	for(k = 0; k < 3; k++){
		for(j = 0; j < 4; j++){
			printf("%f ", a[k][j]);
		}
		printf("\n");
	}

}

void mod_gauss_jordan(){
	double a[3][4] = {
			{ 2.0,  3.0,  1.0,  4.0},
			{ 4.0,  1.0, -3.0, -2.0},
			{ -1.0, 2.0,  2.0,  2.0},
	};
	double p, d, max, dummy;
	int i, j ,k, s;
	for(k = 0; k < 3; k++){
		max = 0; s = k;
		for(j = k; j < 3; j++){
			if(fabs(a[j][k]) > max){
				max = fabs(a[j][k]);
				s = j;
			}
		}
		if(max == 0){
			printf("解けない");
			return;
		}
		for(j = 0; j < 4; j++){
			dummy = a[k][j];
			a[k][j] = a[s][j];
			a[s][j] = dummy;
		}
		p = a[k][k]; /*ピボットの場所*/
		for(j = k; j < 4; j++){
			a[k][j] = a[k][j] / p; /*ピボットで割る*/
		}
		for(i = 0; i < 3; i++){
			/* 自分の行以外を計算、過ぎた行も計算する */
			if(i != k){
				d = a[i][k];
				for(j = k; j < 4; j ++){
					p = a[i][j];
					a[i][j] = a[i][j] - d * a[k][j];
				}
			}
		}
	}
	for(k = 0; k < 3; k++){
		printf("x%d=%f", k + 1, a[k][3]);
	}
	printf("\n");

}
/*
 * a11x1 +  a12x2  + a13x3   = b1    -> 1
 * a21x1 +  a22x2  + a23x3   = b2    -> 2
 * a31x1 +  a32x2  + a33x3   = b3    -> 3
 * 2  - 1  * a21/a11 3 - 1 * a31/a11
 * a11x1 + a12x2   + a13x3   = b1    -> 1'
 *         a'22x2  + a'23x3  = b'2   -> 2'
 *         a'32x2  + a'33x3  = b'3   -> 3'
 * 3' - 2' * a'32/a'22
 * a11x1 + a12x2   + a13x3   = b1    -> 1''
 *         a'22x2  + a'23x3  = b'2   -> 2''
 *                   a''33x3 = b''3  -> 3''
 * x3 = b''3 / a''33
 * x2 = (b'2 - a'23 * x3) / a'22
 * x1 = (b'1 - a12 * x2 - a13 * x3) / a11
 */
void  gaussian_elimination(){
	double a[3][4] = {
			{ 2.0,  3.0,  1.0,  4.0},
			{ 4.0,  1.0, -3.0, -2.0},
			{ -1.0, 2.0,  2.0,  2.0},
	};
	double d;
	int i, j ,k;
	for(k = 0; k < 2; k++){
		for(i = k + 1; i < 3; i++){
			d = a[i][k] / a[k][k];
			for(j = k + 1; j <= 3; j++){
				a[i][j] = a[i][j] - a[k][j] * d;
			}
		}
	}
	for(i = 2; i >= 0; i--){
		d = a[i][3];
		for(j = i + 1; j < 3; j++){
			d = d - a[i][j] * a[j][3];
		}
		a[i][3] = d / a[i][i];
	}
	for(k = 0; k < 3; k++){
		printf("x%d=%f", k + 1, a[k][3]);
	}
	printf("\n");

}

void linear_programming(){
	int n1 = 4; /* 行数 */
	int n2 = 6; /* 列数 */
	int n3 = 2; /* 変数の数 */
	double a[4][6] = {
			{ 1.0,  2.0, 1.0, 0.0, 0.0, 14.0},
			{ 1.0,  1.0, 0.0, 1.0, 0.0, 8.0 },
			{ 3.0,  1.0, 0.0, 0.0, 1.0, 18.0},
			{-2.0, -3.0, 0.0, 0.0, 0.0, 0.0 }
	};
	double min, p, d;
	int j, k, x, y , flag;

	while(1){
		min = 9999;/* yの選定  */
		for(k = 0; k < n2 - 1; k++){
			if(a[n1 - 1][k] < min){
				min = a[n1 - 1][k];
				y = k;
			}
		}
		if(min >= 0){
			break;
		}
		min = 9999;/* xの選定  */
		for(k = 0; k < n1 - 1; k++){
			p = a[k][n2 - 1] / a[k][y];
			if(a[k][y] > 0 && p < min){
				min = p;
				x = k;
			}
		}
		p = a[x][y];                /* ピボット係数 */
		for(k = 0; k < n2; k++){    /* ピボット行をpで割る */
			a[x][k] = a[x][k] / p;
		}
		for(k = 0; k < n1; k++){    /* ピボット列の掃き出し */
			if(k != x){
				d = a[k][y];
				for(j = 0; j < n2; j++){
					a[k][j] = a[k][j] - d * a[x][j];
				}
			}
		}
	}

	for(k = 0; k < n3; k++){
		flag = -1;
		for(j = 0; j < n1; j++){
			if(a[j][k] == 1){
				flag = j;
			}
		}
		if(flag != -1){
			printf("x%d = %f\n", k, a[flag][n2 - 1]);
		}else{
			printf("x%d = %f\n", k, 0.0);
		}
	}
	printf("z= %f\n", a[n1 - 1][n2 - 1]);

}


void least_squares_method(){
	int n = 7;
	int m = 5;
	int i, j, k;
	double p, d, px;
    double x[]={-3,-2,-1, 0,1,2,3},
           y[]={ 5,-2,-3,-1,1,4,5},
           /* t分yが1つ多い */
           a[m+1][m+2],
           s[2*m+1],
           t[m+1];

	for(i = 0; i <= 2 * m; i++){
		s[i] = 0;
	}

	for(i = 0; i < n; i++){
		for(j = 0; j <= 2 * m; j++){ /* s0からs2mの計算 */
			/* s0 = Σx^0 s1 = Σx^1 s2m = ... Σx^2m
			 * xの乗数の合算 */
			s[j] = s[j] + ipow(x[i], j);
		}
		for(j = 0; j <= m; j++){     /* t0からt2mの計算 */
			/* s0 = Σy*x^0 s1 = Σy*x^1 s2m = ... Σy*x^2m
			 * xの乗数*yの合算 */
			t[j] = t[j] + ipow(x[i], j) * y[i];
		}
	}

	for(i = 0; i <= m; i++){ /* a[][]にs[],t[]の値を入れる */
		for(j = 0; j <= m; j++){
			/*斜めに同じものが入る
			 * 0 1 2 3 4 5
			 * 1 2 3 4 5 6
			 * 2 3 4 5 6 7
			 * 3 4 5 6 7 8
			 * 4 5 6 7 8 9
			 * 5 6 7 8 9 10
			 */
			a[i][j] = s[i + j];
		}
		a[i][m + 1] = t[i];
	}

	for(k = 0; k <= m; k++){ /* 掃き出し */
		p = a[k][k];
		for(j = k; j <= m + 1; j++){    /* ピボット行をpで割る */
			a[k][j] = a[k][j] / p;
		}
		for(i = 0; i <= m; i++){    /* ピボット列の掃き出し */
			if(i != k){
				d = a[i][k];
				for(j = k; j <= m + 1; j++){
					a[i][j] = a[i][j] - d * a[k][j];
				}
			}
		}
	}
	printf("     x     y\n");/* 補完多項式によるyの値の計算 */
	for(px = -3; px <= 3; px = px + 0.5){
		p = 0;
		for(k = 0; k <= m; k++){
			p = p + a[k][m + 1] * ipow(px, k);
		}
		printf("%5.1f%5.1f\n", px, p);
	}
}

double ipow(double p, int n){
	int k;
	double s = 1;
	for(k = 1; k <= n; k++){
		s = s * p;
	}
	return s;
}
