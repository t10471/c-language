/*
 ============================================================================
 Name        : algorithm_6_tree.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <locale.h>
//#include <tchar.h>
#include <math.h>
#include <stdlib.h> /* randとsrandを使うため */
#include <time.h>  /* timeを使うため */
#include <sys/types.h>
#include <sys/stat.h>

#define nil -1
#define IntelligenceMax 100
#define Rec 34L
#define Leaf -1

FILE *fp;
typedef struct tnode Tnode;
struct tnode {
	Tnode *left;
	char node[30];
	Tnode *right;
};
Tnode *talloc();
Tnode *readTree(Tnode *);
void writeTree(Tnode *);


void intelligence_db_main();
void intelligence_db_main2();
void intelligence_db_main3();
void file_test();
void file_test2();
void file_test3();

int main(void) {

	printf("intelligence_db_main\n");
	intelligence_db_main();
	printf("intelligence_db_main2\n");
	intelligence_db_main2();
//	file_test2();
	printf("file_test3\n");
	file_test3();
	printf("intelligence_db_main3\n");
	intelligence_db_main3();
	printf("end\n");
	return EXIT_SUCCESS;
}

void intelligence_db_main(){
	struct tnode{
		int left;
		char node[30];
		int right;
	};
	static struct tnode a[IntelligenceMax] = {
			{1,  "芸能人ですか", 2},
			{3,  "歌手ですか",   4},
			{nil,"吉田　茂",   nil},
			{nil, "井上　陽水",nil},
			{5,  "女優ですか",   6},
			{nil, "中山　美穂",nil},
			{nil, "久米　宏",  nil},
	};
	int p, lp = 6, i = 0, x;
	srand( (unsigned)time( NULL ) );
	x = rand() % 3;

	do{
		p = 0;
		while(a[p].left != nil){
			printf("\n%s y/n %d", a[p].node, x);
			if(x == 0)
				p = a[p].left;
			else
				p = a[p].right;
		}
		x = rand() % 3;
		printf("\n答えは %s です。\n 正しいですか  y/n %d\n", a[p].node, x);
		if(x == 1){
			a[lp + 1] = a[p];
			i++;
			printf("\nあなたの考えは？ %d\n", i);
			sprintf(a[lp + 2].node, "%d", i);
			a[lp + 2].left = a[lp + 2].right = nil;
			i++;
			printf("%s と %s を区別する質問は？ %d\n", a[lp + 1].node, a[lp + 2].node, i);
			sprintf(a[p].node, "%d", i);
			x = rand() % 3;
			printf("YESの項目は %s でよいですか %d\n", a[lp + 1].node, x);
			if(x == 0){
				a[p].left = lp + 1; a[p].right = lp + 2;
			}else{
				a[p].left = lp + 2; a[p].right = lp + 1;
			}
			lp = lp + 2;
		}
		x = rand() % 3;
	}while(printf("\n続けますか y/n %d\n", x), x != 0);
	printf("\n");
}

void intelligence_db_main2(){
	Tnode *root, *p, *q1, *q2;
	int x, i;
	srand( (unsigned)time( NULL ) );
	root = talloc();
	strcpy(root->node, "井上　陽水");
	printf("初期ノード ? %s\n", root->node);
	root->right = root->left = NULL;

	do{
		p = root;
		while(p->left != NULL){
			printf("\n%s y/n %d", p->node, x);
			if(x == 0)
				p = p->left;
			else
				p = p->right;
		}
		x = rand() % 3;
		printf("\n答えは %s です。\n 正しいですか  y/n %d\n", p->node, x);
		if(x != 1){
			q1 = talloc(); *q1 = *p;
			i++;
			printf("\nあなたの考えは？ %d\n", i);
			q2 = talloc();
			sprintf(q2->node, "%d", i);
			q2->left = q2->right = NULL;
			i++;
			printf("%s と %s を区別する質問は？ %d\n", q1->node, q2->node, i);
			sprintf(p->node, "%d", i);
			x = rand() % 3;
			printf("YESの項目は %s でよいですか %d\n", q1->node, x);
			if(x == 0){
				p->left = q1; p->right = q2;
			}else{
				p->left = q2; p->right = q1;
			}
		}
		x = rand() % 4;
	}while(printf("\n続けますか y/n %d\n", x), x != 0);
	printf("\n");

}

void intelligence_db_main3(){
	Tnode *root = NULL, *p, *q1, *q2;
	int x, i, c;
	char filename[256] = "../dbase.dat";
	srand( (unsigned)time( NULL ) );
	fp = fopen( filename , "r" );
	printf("3333333333333\n");
	if(fp == NULL){
		root = talloc();
		strcpy(root->node, "井上　陽水");
		strcpy(root->node, "111111");
		printf("初期ノード d? %s\n", root->node);
		root->right = root->left = NULL;
		fclose(fp);
	}else{
		fseek(fp, 0, SEEK_END);
		c = ftell(fp);
		if(c != 0){
			rewind(fp);
			root = readTree(root);
		}else{
			printf("empty\n");
			root = talloc();
			strcpy(root->node, "井上　陽水");
//			strcpy(root->node, "111111");
			printf("初期ノード ? %s\n", root->node);
			root->right = root->left = NULL;
		}
		fclose(fp);
	}

	do{
		p = root;
		while(p->left != NULL){
			printf("\n%s y/n %d", p->node, x);
			if(x == 0)
				p = p->left;
			else
				p = p->right;
		}
		x = rand() % 3;
		printf("\n答えは %s です。\n 正しいですか  y/n %d\n", p->node, x);
		if(x != 1){
			q1 = talloc(); *q1 = *p;
			i++;
			printf("\nあなたの考えは？ %d\n", i);
			q2 = talloc();
			sprintf(q2->node, "%d", i);
			q2->left = q2->right = NULL;
			i++;
			printf("%s と %s を区別する質問は？ %d\n", q1->node, q2->node, i);
			sprintf(p->node, "%d", rand());
			x = rand() % 3;
			printf("YESの項目は %s でよいですか %d\n", q1->node, x);
			if(x == 0){
				p->left = q1; p->right = q2;
			}else{
				p->left = q2; p->right = q1;
			}
		}
		x = rand() % 4;
	}while(printf("\n続けますか y/n %d\n", x), x != 0);
	printf("\n");

	fp = fopen(filename, "w");
	if(fp != NULL){
		writeTree(root);
		fclose(fp);
	}
}

Tnode *readTree(Tnode *p){
	int flag;
	p = talloc();
	fscanf(fp, "%30s%4d", p->node, &flag);
	printf("read %30s,%4d\n", p->node, flag);
	if(flag == -1){
		p->left = p->right = NULL;
	}else{
		p->left = readTree(p->left);
		p->right = readTree(p->right);
	}
	return p;
}

void writeTree(Tnode *p){
	if(p != NULL){
		if(p->left == NULL){
			printf("%30s%4d\n", p->node, Leaf);
			fprintf(fp, "%30s%4d\n", p->node, Leaf);
		}else{
			printf("%30s%4d\n", p->node, !Leaf);
			fprintf(fp, "%30s%4d\n", p->node, !Leaf);
		}
		writeTree(p->left);
		writeTree(p->right);
	}
}

Tnode  *talloc(){
	return (Tnode *)malloc(sizeof(Tnode));
}


void file_test(){
	 FILE *fp;
	 char *fname = "test.txt";
	 char *str = "Hello World\nThe C Programming Language\nTest Test";
	 int i;

	 fp = fopen( fname, "w" );
	 if( fp == NULL ){
	    printf( "%sファイルが開けません\n", fname );
	 }

	 for( i=0; i<48; i++ ){
	    fputc( str[i], fp );
	 }

	 fclose( fp );

	 printf( "%sファイル書き込みが終わりました\n", fname );
}

void file_test2(){
	  FILE * fp;
	  int ret;
	  char getstr[4];
	  int getint;

	  /* Windowsの場合はtest.txt */
	  fp = fopen( "test.txt" , "r" );
	  if( fp == NULL ) {
	    printf( "file open error\n" );
	  }

	  /* ファイルから各変数に変換して代入 */
	  while(( ret = fscanf( fp , "%s%d" , getstr , &getint ))
	                                                != EOF ) {
	    /* 変換して代入された変数を表示 */
	    printf( "getstr=%s\n" , getstr );
	    printf( "getint=%d\n" , getint );
	    printf( "ret=%d\n" , ret );
	  }

	  printf( "\nret=%d\n" , ret );/* -1 */

	  fclose( fp );

}

void file_test3(){
	int flag;
	int ret;
	Tnode *p;
	p = talloc();
	fp = fopen( "../dbase.dat" , "r" );
	if( fp == NULL ) {
		printf( "file open error\n" );
	}
	/* ファイルから各変数に変換して代入 */
	while(( ret = fscanf(fp, "%30s%4d", p->node, &flag)) != EOF ) {
		/* 変換して代入された変数を表示 */
		printf( "node=%s flg=%d\n" , p->node, flag );
		printf( "ret=%d\n" , ret );
		p = talloc();
	}
	printf( "\nret=%d\n" , ret );/* -1 */
	fclose( fp );
}
