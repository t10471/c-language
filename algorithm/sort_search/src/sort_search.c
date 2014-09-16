/*
 ============================================================================
 Name        : algorithm_3_sort_search.c
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
#include <tchar.h>
#include <math.h>



void direct_sort();
void bubble_sort();
void shaker_sort();
void sort_pointer();
void basic_sort();
void shell_sort();
void mod_shell_sort();
void sequential_search();
void binary_search();
void binary_search2();
void simple_merge();
void simple_merge_sentinel();
void string_match();
char *search(char *, char *);
void boyer_moore_match();
void make_skip_table( char *);
char *search2(char *, char *);
int skip[256];
char *search3(char *, char *);
void replace(char *, char *, char *);
void replace_main();
void replace_main2();
char *search4(char *, char *);
void replace2(char *, char *, char *);
int hash1(char *);
void hash_main();
void hash_main2();

int main(void) {
	direct_sort();
	bubble_sort();
	shaker_sort();
	sort_pointer();
	basic_sort();
	shell_sort();
	mod_shell_sort();
	sequential_search();
	binary_search();
	binary_search2();
	simple_merge();
	simple_merge_sentinel();
	string_match();
	boyer_moore_match();
	replace_main();
	replace_main2();
	hash_main();
	hash_main2();
	return EXIT_SUCCESS;
}
/*
 * 最小値を探して交換する
 */
void direct_sort(){
	int a[] = {80, 41, 35, 90, 40, 20};
	int min, s, t, i, j;
	for(i = 0; i < 6 - 1; i++){
		min = a[i];
		s = i;
		for(j = i + 1; j < 6; j++){
			if(a[j] < min){
				min = a[j];
				s = j;
			}
		}
		t = a[i]; a[i] = a[s]; a[s] = t;
	}
	for(i = 0; i < 6; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

/*
 * 隣同士を交換する
 */
void bubble_sort(){
	int a[] = {80, 41, 35, 90, 40, 20};
	int t, i, j;
	printf("start \n");
	for(j = 0; j < 6; j++){
		printf("%d ", a[j]);
	}
	printf("\n");
	for(i = 0; i < 6; i++){
		for(j = 6 - 1; j > i; j--){
			if(a[j] < a[j - 1]){
				t = a[j]; a[j] = a[j - 1]; a[j - 1] = t;
			}
		}
		for(j = 0; j < 6; j++){
			printf("%d ", a[j]);
		}
		printf("\n");
	}
	for(i = 0; i < 6; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("end  \n");
}

/*
 * バブルソートの改良版
 * 左右の整列済みの部分を飛ばす処理を追加
 */
void shaker_sort(){
	int a[] = {3, 5, 6, 9, 2, 7, 8, 10, 4};
	int left, right, i, shift, t;
	left = 0; right = 9 - 1;
	printf("start \n");
	for(i = 0; i < 9; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	while( left < right){
		for(i = 0; i < right; i++){
			if(a[i] > a[i + 1]){
				t = a[i]; a[i] = a[i + 1]; a[i + 1] = t;
				shift = i;
			}
		}
		for(i = 0; i < 9; i++){
			printf("%d ", a[i]);
		}
		printf("\n");
		right = shift;
		for(i = right; i > left; i--){
			if(a[i] < a[i - 1]){
				t = a[i]; a[i] = a[i - 1]; a[i - 1] = t;
				shift = i;

			}
		}
		left = shift;
		for(i = 0; i < 9; i++){
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	for(i = 0; i < 9; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("end  \n");
}

void sort_pointer(){

    typedef struct {
        char *name;
        int age;
    } girl;
    girl t;
    girl **p;
    girl a[]={
    			{"Ann",18},
				{"Rolla",19},
				{"Nancy",16},
				{"Eluza",17},
				{"Juliet",18},
				{"Machilda",20},
				{"Emy",15},
				{"Candy",16},
				{"Ema",17},
				{"Mari",18}
    };
    char *min;
    int s,i,j;
    p = (girl **)malloc(sizeof(girl) * 10);

    /* データをポインタで指し示す */
    for (i=0;i<10;i++)
        p[i] = &a[i];
    for (i=0;i<10-1;i++){
        min = p[i]->name;
        s = i;
        for (j=i+1;j<10;j++){
            if (strcmp(p[j]->name, min) < 0){
                min = p[j]->name;
                s = j;
            }
        }
        /* ポインタの交換 */
        if(s != i){
            t = *p[i];
            *p[i] = *p[s];
            *p[s] = t;
        }
    }
    for (i=0;i<10;i++)
        printf("%10s%4d\n", p[i]->name, p[i]->age);
    free(p);

}

void basic_sort(){
	int a[100], i, j ,t;
	for(i=0;i<100;i++){
		a[i] = rand();
	}
	for(i=1;i<100;i++){
		for(j=i-1;j>=0;j--){
			if(a[j] > a[j+1]){
				t=a[j]; a[j]=a[j+1]; a[j+1]=t;
			}else{
				break;
			}
		}
	}
    for (i=0;i<100;i++)
        printf("%8d", a[i]);
    printf("\n");

}

/**
 * 基本挿入法を飛び飛びに行うことで、
 * 大雑把からだんだん並べ替える
 */
void shell_sort(){
	int a[100], i, j ,k, gap, t;
	for(i=0;i<100;i++){
		a[i] = rand();
	}
	gap = 100/2;
	while(gap > 0){
		/*ギャップの分、分割するのでその分ループ*/
		for(k=0; k < gap; k++){
			/*基本挿入法*/
			for(i = k + gap; i < 100; i=i+gap){
				for(j = i - gap; j >= k; j=j-gap){
					if(a[j] > a[j+gap]){
						t=a[j]; a[j]=a[j+gap]; a[j+gap]=t;
					}else{
						break;
					}
				}
			}
		}
		gap = gap / 2;
	}
    for (i=0;i<100;i++)
        printf("%8d", a[i]);
    printf("\n");
}

void mod_shell_sort(){
	int a[20], i, j, gap, t, x;
	for(i=0;i<20;i++){
		a[i] = rand();
	}
	for(gap= 1; gap < 20/3; gap=3*gap+1);
	printf("gap %d\n", gap);
    for (x=0;x<20;x++)
        printf("%8d", a[x]);
    printf("\n");
	while(gap > 0){
//		printf("gap %d  ", gap);
		for(i=gap; i < 20; i++){
			/*ギャップ分飛ばしで基本挿入法*/
//			printf("i %d  ", i);
			for(j = i - gap; j >= 0; j=j-gap){
//				printf("j %d  ", j);
				if(a[j] > a[j+gap]){
					t=a[j]; a[j]=a[j+gap]; a[j+gap]=t;
				}else{
					break;
				}
			}
//		    printf("\n");
//		    for (x=0;x<20;x++)
//		        printf("%8d", a[x]);
//		    printf("\n");

		}
		gap = gap / 3;
	}
    for (i=0;i<20;i++)
        printf("%8d", a[i]);
    printf("\n");
}

void sequential_search(){
    typedef struct {
        char name[20];
        int age;
    } girl;
    girl a[]={
    			{"Ann",18},
				{"Rolla",19},
				{"Nancy",16},
				{"Eluza",17},
				{"Juliet",18},
				{"Machilda",20},
				{"Emy",15},
				{"Candy",16},
				{"Ema",17},
				{"Mari",18}
    };
    char *key;
    int i;
    i = 0;
    key = "Ema";
    while(i < 20 && strcmp(key, a[i].name) != 0){
    	i++;
    }
    printf("%s %d\n", a[i].name, a[i].age);


}

/**
 * 半分筒調べる
 */
void binary_search(){
	int a[] = {2, 3, 7,  11, 31, 50, 55, 70, 77, 80};
	int key, low, high, mid, flag = 0;
	low = 0; high = 10 - 1;
	key = 31;
	while(low < high){
		mid = (low + high) / 2;
		if(a[mid] == key){
			printf("%d は %d 番目にありました\n", a[mid], mid);
			flag = 1;
			break;
		}
		if(a[mid] < key){
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	if(flag != 1){
		printf("見つかりませんでした\n");
	}
}

void binary_search2(){
	int a[] = {2, 3, 7,  11, 31, 50, 55, 70, 77, 80};
	int key, low, high, mid;
	low = 0; high = 10 - 1;
	key = 11;
	while(low <= high){
		mid = (low + high) / 2;
		printf("start %d %d %d\n", low, mid, high);
		if(a[mid] <= key){
			low = mid + 1;
		}
		if(a[mid] >= key){
			high = mid - 1;
		}
//		keyは3
//		start 0 4 9
//		end   0 4 3 a[mid] >= keyからhigh = mid - 1
//		start 0 1 3 mid = (0 + 3) / 2
//		end   2 1 3 a[mid] <= keyからlow  = mid + 1
//		start 2 2 3 mid = (2 + 3) / 2
//		end   3 2 3 a[mid] <= keyからlow  = mid + 1
//		start 3 3 3 mid = (3 + 3) / 2
//		end   4 3 2 a[mid] <= keyからlow  = mid + 1 かつ a[mid] >= keyからhigh  = mid - 1
//		なのでlowとhighの差が2になる
		printf("end   %d %d %d\n", low, mid, high);
	}
	if(low == high + 2){
		printf("%d は %d 番目にありました\n", a[mid], mid);
	}else{
		printf("見つかりませんでした\n");
	}
}

void simple_merge(){
	int a[] = {2, 4, 5, 7, 8, 10, 15, 20, 30, 40};
	int b[] = {6, 11, 25, 33, 35};
	int c[15];
	int i, j, p;
	i=j=p=0;
	while(i < 10 && j < 5){
		if(a[i] <= b[j]){
			c[p++] = a[i++];
		}else{
			c[p++] = b[j++];
		}
	}
	while(i < 10){
		c[p++] = a[i++];
	}
	while(j < 5){
		c[p++] = b[j++];
	}
    for (i=0;i<15;i++)
        printf("%d ", c[i]);
    printf("\n");
}

void simple_merge_sentinel(){
	int a[] = {2, 4, 5, 7, 8, 10, 15, 20, 30, 40, 45, 50, 60, 9999};
	int b[] = {6, 11, 25, 33, 35, 9999};
	int c[18];
	int i, j, p;
	i=j=p=0;
	//両方番兵になるまで
	while(a[i] != 9999 || b[j] != 9999){
		if(a[i] <= b[j]){
			c[p++] = a[i++];
		}else{
			c[p++] = b[j++];
		}
	}
    for (i=0;i<15;i++)
        printf("%d ", c[i]);
    printf("\n");
}

void string_match(){
	static char text[] = "This is a pen. That is pencil.";
	char *p, *key = "pen";
	//pen. That is pencil.が返る
	p = search(text, key);
	while(p != NULL){
		printf("%s\n", p);
		//pencil.
		//NULL
		p = search(p + strlen(key), key);
	}
}

char *search(char *text, char *key){
	int m, n;
	char *p;

	m = strlen(text);
	n = strlen(key);
	printf("%s\n", text);
	//max il.
	printf("max %s\n", text + m - n);
	//文字列にint足せる
	for(p = text; p <= text + m - n; p++){
		//printf("%d %d\n", *p, *(text + m - n));
		printf("for %s\n", p);
		if(strncmp(p, key, n) == 0){
			return p;
		}
	}
	return NULL;
}

void boyer_moore_match(){
	static char text[] = "This is a pen. That is pencil.";
	char *p, *key = "pen";

	make_skip_table(key);
	p = search2(text, key);
	while(p != NULL){
		printf("%s\n", p);
		p = search2(p + strlen(key), key);
	}
}

void make_skip_table(char *key){
	int k, n;
	n = strlen(key);
	for(k = 0; k < 255; k++){
		skip[k] = n;
	}
	//skipはアルファベットのテーブル
	for(k = 0; k < n - 1; k++){
		//key[k]はできるアルファベットのintが返る
		//同じアルファベットは後がち、小さいほうにマッチングさせる
		skip[key[k]] = n - 1 - k;
		//printf("%s\n", key[k]);はエラー
		printf("%c %d %d\n", key[k], key[k], skip[key[k]]);
	}
}

char *search2(char *text, char *key){
	int m, n;
	char *p;

	m = strlen(text);
	n = strlen(key);
	p = text + n - 1;
	//\0
	printf("max %s\n", text + m);
	while(p < text + m){
		if(*p == key[n - 1]){
			if(strncmp(p - n + 1, key, n) == 0){
				return p - n + 1;
			}
		}
		printf("%d\n", *p);
		p = p + skip[*p];
		printf("for %s\n", p);

	}
	return NULL;
}

void replace_main(){
	static char text[] = "This is a pen. That is pencil.";
	//同じ長さであること
	replace(text, "pen", "cap");
	printf("%s\n", text);

}

void replace(char *text, char *key, char *rep){
	char *p;
	int i;
	p = search3(text, key);
	printf("%s\n", p);
	while(p != NULL){
		for(i = 0; i < (int)strlen(rep); i++){
			p[i] = rep[i];
		}
		p = search3(p + strlen(key), key);
		printf("%s\n", p);
	}
}

char *search3(char *text, char *key){
	int m, n;
	char *p;
	m = strlen(text);
	n = strlen(key);
	for(p = text; p <= text + m - n; p++){
		if(strncmp(p, key, n) == 0){
			return p;
		}
	}
	return NULL;

}

void replace_main2(){
	int k;
	static char text[][128] = {"      --- サルビアの花 ---",
			                   "いつもいつも思ってた",
			                   "サルビアの花をあなたの部屋の中に",
			                   "投げ入れたくて",
			                   "そして君のベットに",
			                   "サルビアの紅い花をしきつめて",
			                   "僕は君を死ぬまで抱きしめていようと",
			                   ""
	};
	k = 0;
	while(text[k][0] != '\0'){
		printf("%s\n", text[k]);
		replace2(text[k], "サルビア", "か　す　み　草");
		replace2(text[k], "紅", "白");
		printf("%s\n", text[k]);
		k++;
	}
}

void replace2(char *text, char *key, char *rep){
	char *p, buf[128];
	p = search4(text, key);
	while(p != NULL){
		printf("text s%se\n", text);
		printf("p    s%se\n", p);
		//pとtextは同じ中身だが、指している場所は違う
		//textを一致前までにしている
		*p = '\0';
		printf("text s%se\n", text);
		//一致している部分以降をbufに設定\0を無視している
		strcpy(buf, p + strlen(key));
		printf("buf  s%se\n", buf);
		strcat(text, rep);
		printf("text s%se\n", text);
		strcat(text, buf);
		printf("text s%se\n", text);
		p = search4(p + strlen(rep), key);
		printf("p    s%se\n", p);
	}
}

char *search4(char *text, char *key){
	int m, n;
	char *p;
	m = strlen(text);
	n = strlen(key);
	for(p = text; p <= text + m - n; p++){
		if(strncmp(p, key, n) == 0){
			return p;
		}
	}
	return NULL;

}

void hash_main(){
	struct tel{
		char name[12];
		char telnum[12];
	} dat[1000];
	int n;
	char a[12], b[12];
	printf("名前 電話番号\n");
	strcpy(a, "MISAWA");
	strcpy(b, "1234-5678");
	n = hash1(a);
	printf("%s %s %d\n", a, b, n);
	strcpy(dat[n].name, a);
	strcpy(dat[n].telnum, b);
	strcpy(a, "KAWADA");
	strcpy(b, "1111-2222");
	n = hash1(a);
	printf("%s %s %d\n", a, b, n);
	strcpy(dat[n].name, a);
	strcpy(dat[n].telnum, b);

	strcpy(a, "MISAWA");
	printf("検索 %s\n", a);
	n = hash1(a);
	printf("%s %s\n", dat[n].name, dat[n].telnum);
}

int hash1(char *s){
	int n;
	n = strlen(s);
	return (s[0] ^ 'A' + (s[n / 2 - 1] - 'A') * 26 + (s[n - 2] - 'A') * 26 * 26) % 1000;
}

void hash_main2(){
	struct tel{
		char name[12];
		char telnum[12];
		int empty;
	} dat[1000];
	int n;
	char a[12], b[12];
	printf("名前 電話番号\n");
	strcpy(a, "MISAWA");
	strcpy(b, "1234-5678");
	n = hash1(a);
	while(dat[n].empty == 1 && n < 1000){
		n++;
	}
	if(n < 1000){
		printf("%s %s %d\n", a, b, n);
		strcpy(dat[n].name, a);
		strcpy(dat[n].telnum, b);
		dat[n].empty = 1;
	}else{
		printf("表がいっぱいです\n");
	}
	strcpy(a, "KAWADA");
	strcpy(b, "1111-2222");
	n = hash1(a);
	while(dat[n].empty == 1 && n < 1000){
		n++;
	}
	if(n < 1000){
		printf("%s %s %d\n", a, b, n);
		strcpy(dat[n].name, a);
		strcpy(dat[n].telnum, b);
		dat[n].empty = 1;
	}else{
		printf("表がいっぱいです\n");
	}

	strcpy(a, "MISAWA");
	printf("検索 %s\n", a);
	n = hash1(a);
	while(strcmp(a, dat[n].name) != 0 && n < 1000){
		n++;
	}
	if(n < 1000){
		printf("%s %s\n", dat[n].name, dat[n].telnum);
	}else{
		printf("見つかりませんでした\n");
	}
}
