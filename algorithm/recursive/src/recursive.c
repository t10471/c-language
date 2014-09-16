#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <tchar.h>
#include <math.h>

void factorial_recursive();
long kaijo(int);
void fib_main();
long fib(long);
void combinator_main();
long combi(int, int);
void fn_main();
double fn(double, double *, int);
void gcd_main();
int gcd(int, int);
void gcd_main2();
int gcd2(int, int);
void generate_perm();
void perm(int, int *, int);
void generate_perm2();
void perm2(int, int *);
void hanoi_main();
void hanoi(int, char, char, char);
void hanoi_main2();
void hanoi2(int, char, char);
void maze();
int visit(int, int, int);
void maze2();
int visit2(int, int, int);
void maze3();
int visit3(int, int, int);
void maze4();
int visit4(int, int, int);
void quick_main();
void quick(int *, int, int, int);
void quick_main2();
void quick2(int *, int, int, int);
int maze_m[7][7] = {
		{2, 2, 2, 2, 2, 2, 2},
		{2, 0, 0, 0, 0, 0, 2},
		{2, 0, 2, 0, 2, 0, 2},
		{2, 0, 0, 2, 0, 2, 2},
		{2, 2, 0, 2, 0, 2, 2},
		{2, 0, 0, 0, 0, 0, 2},
		{2, 2, 2, 2, 2, 2, 2}
};
int maze_Si, maze_Sj, maze_Ei, maze_Ej, maze_success;
int maze2_m[7][7] = {
		{2, 2, 2, 2, 2, 2, 2},
		{2, 0, 0, 0, 0, 0, 2},
		{2, 0, 2, 0, 2, 0, 2},
		{2, 0, 0, 2, 0, 2, 2},
		{2, 2, 0, 2, 0, 2, 2},
		{2, 0, 0, 0, 0, 0, 2},
		{2, 2, 2, 2, 2, 2, 2}
};
int maze2_Si, maze2_Sj, maze2_Ei, maze2_Ej, maze2_success,
	maze2_sp, maze2_ri[100], maze2_rj[100];
int maze3_m[9][9] = {
		{2, 2, 2, 2, 2, 2, 2, 2, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 2, 2, 0, 2, 2, 0, 2},
		{2, 0, 2, 0, 0, 2, 0, 0, 2},
		{2, 0, 2, 0, 2, 0, 2, 0, 2},
		{2, 0, 0, 0, 0, 0, 2, 0, 2},
		{2, 2, 0, 2, 2, 0, 2, 2, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 2, 2, 2, 2, 2, 2, 2, 2},
};
int maze3_Si, maze3_Sj, maze3_Ei, maze3_Ej, maze3_success,
	maze3_sp, maze3_ri[100], maze3_rj[100];
int maze4_m[10][10] = {
		{2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 0, 2, 2, 2, 2, 2, 2, 2, 2},
		{2, 0, 2, 0, 0, 2, 0, 2, 0, 2},
		{2, 0, 2, 0, 0, 2, 0, 2, 0, 2},
		{2, 0, 0, 2, 2, 2, 0, 2, 0, 2},
		{2, 0, 2, 2, 2, 2, 0, 2, 0, 2},
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 2},
		{2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
};

int main(void) {
	factorial_recursive();
	fib_main();
	combinator_main();
	fn_main();
	gcd_main();
	gcd_main2();
	generate_perm();
	generate_perm2();
	hanoi_main();
	hanoi_main2();
	maze();
	maze2();
	maze3();
	maze4();
	quick_main();
	quick_main2();
	return EXIT_SUCCESS;
}

void factorial_recursive(){
	int n;
	for(n = 0; n < 13; n++){
		printf("%2d!= %10ld\n", n, kaijo(n));
	}
}

long kaijo(int n){
	if(n == 0)
		return 1L;
	else
		return n * kaijo(n - 1);
}

void fib_main(){
	long n;
	for(n = 1; n < 20; n++){
		printf("%3ld: %ld\n", n, fib(n));
	}
}

long fib(long n){
	if(n == 1 || n == 2){
		return 1L;
	}else{
		return fib(n - 1) + fib(n - 2);
	}
}

void combinator_main(){
	int n, r;
	for(n = 0; n <= 5; n++){
		for(r = 0; r <= n; r++){
			printf("%d C %d=%ld  ", n, r, combi(n, r));
		}
		printf("\n");
	}
}

long combi(int n, int r){
	if(r == 0 || r == n){
		return 1L;
	}else{
		return combi(n - 1, r) + combi(n - 1, r - 1);
	}
}

void fn_main(){
	double a[] = {1, 2, 3, 4, 5};
	printf("%f\n", fn(2, a, 4));
}

double fn(double x,double a[],int i){
	if(i == 0)
		return a[4];
	else
		return fn(x, a, i - 1) * x + a[4 - i];
}

void gcd_main(){
	int a, b;
	a = 128;
	b = 72;
	printf("%dと%dの最大公約数は%d\n", a, b, gcd(a, b));
}

int gcd(int m, int n){
	if(m == n)
		return m;
	if(m > n)
		return gcd(m - n, n);
	else
		return gcd(m, n - m);
}

void gcd_main2(){
	int a, b;
	a = 128;
	b = 72;
	printf("%dと%dの最大公約数は%d\n", a, b, gcd2(a, b));
}

int gcd2(int m, int n){
	if(n == 0)
		return m;
	else
		return gcd(n, m % n);
}

void generate_perm(){
	int i;
	int p[5];
	for(i = 1;i <= 4; i++){
		p[i] = i;
	}
	perm(1, p, 0);
}

void perm(int i, int p[], int z){
	int t, j, x;
	if(i < 4){
		for(j = i; j <= 4; j++){
			if(i == 1){
				printf("1111111111111111\n");
			}
			printf("s i=%d j=%d ", i, j);
			for(x = 1; x <=  i; x++) printf("   ");
			printf("s ");
			for(x = 1; x <= 4; x++) printf("%d ", p[x]);
			t = p[i]; p[i] = p[j]; p[j] = t;
			printf("\n");
			perm(i + 1, p, j);
			//戻す
			t = p[i]; p[i] = p[j]; p[j] = t;
		}
	}else{
		printf("  i=%d j=%d ", i, z);
		for(x = 1; x <=  i; x++) printf("****");
		for(j = 1; j <= 4; j++) printf("%d ", p[j]);
		printf("\n");
	}
}

/*
 * 辞書順
 */
void generate_perm2(){
	printf("\n");
	printf("\n");
	int i;
	int p[5];
	for(i = 1;i <= 4; i++){
		p[i] = i;
	}
	perm2(1, p);
}

void perm2(int i, int p[]){
	int t, j, k;
	if(i < 4){
		for(j = i; j <= 4; j++){
			//p[i] から p[j]の右ローテイト
			t = p[j];
			for(k = j; k > i; k--) p[k] = p[k - 1];
			p[i] = t;
			perm2(i + 1, p);
			//戻す
			for(k = i; k < j; k++) p[k] = p[k + 1];
			p[j] = t;
		}
	}else{
		for(j = 1; j <= 4; j++) printf("%d ", p[j]);
		printf("\n");
	}
}

void hanoi_main(){
	printf("\n");
	printf("\n");
	int n = 4;
 	hanoi(n, 'a', 'b', 'c');
}

void hanoi(int n, char a, char b, char c){
	int i;
	if(n > 0){
		for(i = 0; i < 4 - n; i++) printf(" ");
		printf("%d in ", n);
		if(n > 1){
			printf("%c %c %c -> %c %c %c\n", a, b, c, a, c, b);
		}else{
			printf("\n");
		}
		hanoi(n - 1, a, c, b);
		for(i = 0; i < 4 - n; i++) printf(" ");
		printf("%d番目の円盤を %c から %c に移動\n", n, a, b);
		if(n > 1){
			for(i = 0; i < 4 - n; i++) printf(" ");
			printf("%c %c %c -> %c %c %c\n", a, b, c, c, b, a);
		}
		hanoi(n - 1, c, b, a);
		for(i = 0; i < 4 - n; i++) printf(" ");
		printf("%d out\n", n);
	}
}

void hanoi_main2(){
	printf("\n");
	printf("\n");
	int n = 4;
 	hanoi2(n, 'a', 'b');
}
void hanoi2(int n, char a, char b){
	if(n > 0){
		hanoi2(n - 1, a,  'a' + 'b' + 'c' - (a + b));
		printf("%d番目の円盤を %c から %c に移動\n", n, a, b);
		hanoi2(n - 1, 'a' + 'b' + 'c' - (a + b), b);
	}
}

void maze(){
	maze_success = 0;
	maze_Si = 1; maze_Sj = 1; maze_Ei = 5; maze_Ej = 5;
	printf("\n 迷路の探索 \n");
	if(visit(maze_Si, maze_Sj, 0) == 0){
		printf("出口は見つかりませんでした  \n");
	}
	printf("\n");
}

int visit(int i, int j, int s){
	int x;
	for(x = 0; x < s; x++) printf(" ");
	printf("in  (%d, %d) \n", i, j);
	//訪れたところにしるしをつける
	maze_m[i][j] = 1;
	if(i == maze_Ei && j == maze_Ej)
		maze_success = 1;

	if(maze_success != 1 && maze_m[i][j + 1] == 0) visit(i, j + 1, s + 1);
	if(maze_success != 1 && maze_m[i + 1][j] == 0) visit(i + 1, j, s + 1);
	if(maze_success != 1 && maze_m[i][j - 1] == 0) visit(i, j - 1, s + 1);
	if(maze_success != 1 && maze_m[i - 1][j] == 0) visit(i - 1, j, s + 1);

	if(maze_success == 1){
		printf("(%d, %d) \n", i, j);
	}
	for(x = 0; x < s; x++) printf(" ");
	printf("out (%d, %d) \n", i, j);
	return maze_success;
}

void maze2(){
	//スタックのポインタ
	maze2_sp = 0;
	maze2_success = 0;
	maze2_Si = 1; maze2_Sj = 1; maze2_Ei = 5; maze2_Ej = 5;
	printf("\n 迷路の探索 \n");
	if(visit2(maze2_Si, maze2_Sj, 0) == 0){
		printf("出口は見つかりませんでした  \n");
	}
	printf("\n");
}

int visit2(int i, int j, int s){
	int x;
	int k;
	//訪れたところにしるしをつける
	maze2_m[i][j] = 1;
	//とりあえずスタックに入れる
	maze2_ri[maze2_sp] = i; maze2_rj[maze2_sp] = j; maze2_sp++;

	for(x = 0; x < s; x++) printf(" ");
	printf("in  (%d, %d) \n", i, j);

	if(i == maze2_Ei && j == maze2_Ej){
		//ここにきているときはスタックが正しい
		for(k = 0; k < maze2_sp; k++)
			printf("(%d, %d) ", maze2_ri[k], maze2_rj[k]);
		printf("\n");
		maze2_success = 1;
	}

	if(maze2_success != 1 && maze2_m[i][j + 1] == 0) visit2(i, j + 1, s + 1);
	if(maze2_success != 1 && maze2_m[i + 1][j] == 0) visit2(i + 1, j, s + 1);
	if(maze2_success != 1 && maze2_m[i][j - 1] == 0) visit2(i, j - 1, s + 1);
	if(maze2_success != 1 && maze2_m[i - 1][j] == 0) visit2(i - 1, j, s + 1);

	for(x = 0; x < s; x++) printf(" ");
	printf("out (%d, %d) \n", i, j);
	//ここにいるということは失敗なのでスタックから出す
	maze2_sp--;
	return maze2_success;
}

void maze3(){
	//スタックのポインタ
	maze3_sp = 0;
	maze3_success = 0;
	maze3_Si = 1; maze3_Sj = 1; maze3_Ei = 7; maze3_Ej = 7;
	printf("\n 迷路の探索 \n");
	if(visit3(maze3_Si, maze3_Sj, 0) == 0){
		printf("出口は見つかりませんでした  \n");
	}
	printf("\n");
}

int visit3(int i, int j, int s){
	int x;
	int k;
	static int maze3_path = 1;
	//訪れたところにしるしをつける
	maze3_m[i][j] = 1;
	//とりあえずスタックに入れる
	maze3_ri[maze3_sp] = i; maze3_rj[maze3_sp] = j; maze3_sp++;

	for(x = 0; x < s; x++) printf(" ");
	printf("in  (%d, %d) \n", i, j);

	if(i == maze3_Ei && j == maze3_Ej){
		printf("\npath=%d\n", maze3_path++);
		//ここにきているときはスタックが正しい
		for(k = 0; k < maze3_sp; k++)
			printf("(%d, %d) ", maze3_ri[k], maze3_rj[k]);
		printf("\n");
		maze3_success = 1;
	}

	//未探索のところだけ進む
	if(maze3_m[i][j + 1] == 0) visit3(i, j + 1, s + 1);
	if(maze3_m[i + 1][j] == 0) visit3(i + 1, j, s + 1);
	if(maze3_m[i][j - 1] == 0) visit3(i, j - 1, s + 1);
	if(maze3_m[i - 1][j] == 0) visit3(i - 1, j, s + 1);

	for(x = 0; x < s; x++) printf(" ");
	printf("out (%d, %d) \n", i, j);
	//ここにいるということは失敗なのでスタックから出す
	maze3_sp--;
	//別経路探索のため戻す
	maze3_m[i][j] = 0;
	return maze3_success;
}

void maze4(){
	int i, j;
	visit4(1, 1 ,1);
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			printf("%2d", maze4_m[i][j]);
		}
		printf("\n");
	}
}

int visit4(int i, int j, int s){
	maze4_m[i][j] = 1;
	//未探索のところだけ進む
	if(maze4_m[i][j + 1] == 0) visit4(i, j + 1, s + 1);
	if(maze4_m[i + 1][j] == 0) visit4(i + 1, j, s + 1);
	if(maze4_m[i][j - 1] == 0) visit4(i, j - 1, s + 1);
	if(maze4_m[i - 1][j] == 0) visit4(i - 1, j, s + 1);
	return s;
}

void quick_main(){
	static int a[] = {41, 24, 76, 11, 45, 64, 21, 69, 19, 36};
	int k;
	printf("\n");
	printf("\n");
	quick(a, 0, 10 - 1, 0);

	for(k = 0; k < 10; k++){
		printf("%4d", a[k]);
	}
	printf("\n");
}

void quick(int a[], int left, int right, int y){
	int  s, t, i, j, x, k;
	for(k = 0; k < 10; k++){
		printf("%4d", a[k]);
	}
	for(x = 0; x < y; x++) printf("  ");
	printf(" %d  %d ", left, right);
	printf("\n");

	if(left < right){
		//左端の項を軸にする
		s = a[left];
		//軸より小さいグループと大きいグループに分ける
		i = left; j = right + 1;
		printf("%2d, ", s);
		while(1){
			//軸より大きいものを選ぶ
			while(a[++i] < s);
			//軸より小さいものを選ぶ
			while(a[--j] > s);
			//逆転している場合、正しく並んでいる
			if(i >= j) break;
			printf("%3d <-> %2d,", a[i], a[j]);
			t = a[i]; a[i] = a[j]; a[j] = t;
		}
		printf("\n");
		//軸を正しい位置に入れる
		a[left] = a[j]; a[j] = s;
		//左部分に対する再帰
		quick(a, left, j - 1, y + 1);
		//右部分に対する再帰
		quick(a, j + 1, right, y + 1);
	}

}

void quick_main2(){
	static int a[] = {41, 24, 76, 11, 45, 64, 21, 69, 19, 36};
	int k;
	printf("\n");
	printf("\n");
	quick2(a, 0, 10 - 1, 0);

	for(k = 0; k < 10; k++){
		printf("%4d", a[k]);
	}
	printf("\n");
}

void quick2(int a[], int left, int right, int y){
	int  s, t, i, j, x, k;
	for(k = 0; k < 10; k++){
		printf("%4d", a[k]);
	}
	for(x = 0; x < y; x++) printf("  ");
	printf(" %d  %d ", left, right);
	printf("\n");
	if(left < right){
		//左端の項を軸にする
		s = a[(left + right) / 2];
		//軸より小さいグループと大きいグループに分ける
		i = left - 1; j = right + 1;
		printf("%2d, ", s);
		while(1){
			//軸より大きいものを選ぶ
			while(a[++i] < s);
			//軸より小さいものを選ぶ
			while(a[--j] > s);
			//逆転している場合、正しく並んでいる
			if(i >= j) break;
			printf("%3d <-> %2d,", a[i], a[j]);
			t = a[i]; a[i] = a[j]; a[j] = t;
		}
		printf("\n");
		//軸の交換は行わない
		//左部分に対する再帰
		quick2(a, left, i - 1, y + 1);
		//右部分に対する再帰
		quick2(a, j + 1, right, y + 1);
	}

}
