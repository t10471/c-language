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
#include <locale.h>
#include <string.h>
#include <tchar.h>
#include <math.h>
#include <stdlib.h> /* randとsrandを使うため */
#include <time.h>  /* timeを使うため */

#define nil -1
#define BTMaxSize 100
#define BTMaxSize 100
#define IntelligenceMax 100

void bt_main();
void bt_main2();
typedef struct tnode Tnode;
struct tnode {
	int left;
	char name[12];
	int right;
} ;
void bt_main3();
typedef struct tnode2 Tnode2;
struct tnode2 {
	Tnode2 *left;
	char name[12];
	Tnode2 *right;
} ;
Tnode2 *talloc();

void bt_main4();
Tnode2 *gentree(Tnode2 *, char *);
void bt_main5();
Tnode2 *search(Tnode2 *, char *);
void bt_main6();
void gentree2(Tnode2 **, char *);

void treewalk(Tnode2 *);
void bt_main7();

void treewalk2(Tnode2 *);
void bt_main8();

void treewalk3(Tnode2 *);
void bt_main9();

void treewalk4(Tnode2 *);
void bt_main10();

void heap_main();
void heap_main2();
void heap_main3();
void swap(int *, int *);
void shiftdown(int, int, int *);

typedef struct tnode3 Tnode3;
struct tnode3 {
	Tnode3 *left;
	char ope;
	Tnode3 *right;
} ;

Tnode3 *talloc3();
Tnode3 *gentree3(Tnode3 *, char *, char *);
void prefix(Tnode3 *);
void infix(Tnode3 *);
void postfix(Tnode3 *);
void treeform_main();

typedef struct tnode4 Tnode4;
struct tnode4 {
	Tnode4 *left;
	int ope;
	Tnode4 *right;
} ;
void treeform_main2();
void postfix2(Tnode4 *);
Tnode4 *gentree4(Tnode4 *, char *, char *);
Tnode4 *talloc4();


int main(void) {
	bt_main();
	bt_main2();
	bt_main3();
	bt_main4();
	bt_main5();
	bt_main6();
	bt_main7();
	bt_main8();
	bt_main9();
	bt_main10();
	heap_main();
	heap_main2();
	heap_main3();
	treeform_main();
	treeform_main2();
	return EXIT_SUCCESS;
}

void bt_main(){
	Tnode a[BTMaxSize] = {{   1, "Machilda",   2},
						  {   3, "Candy"   ,   4},
						  {   5, "Rolla"   , nil},
						  { nil, "Ann"     , nil},
						  {   6, "Emy"     ,   7},
						  { nil, "Nancy"   , nil},
						  { nil, "Eluza"   , nil},
						  { nil, "Lisa"    , nil}};
	char key[12];
	int p, i, hit;
	char keys[6][12] = {"a", "Nancy", "Lisa", "Rolla", "x", "Lisz"};
	for(i = 0; i < 6; i++){
		strcpy(key, keys[i]);
		p = 0;
		hit = 0;
		printf("search %s\n", key);
		while(p != nil){
			printf("  %8s ", a[p].name);
			if(strcmp(key, a[p].name) == 0){
				hit = 1;
				printf("見つかりました\n");
				break;
			}else if(strcmp(key, a[p].name) < 0){
				printf("move left\n");
				p = a[p].left;
			}else{
				printf("move right\n");
				p = a[p].right;
			}
		}
		if(hit == 0){
			printf("見つかりませんでした\n");
		}
	}
}

void bt_main2(){
	Tnode a[BTMaxSize] = {{   1, "Machilda",   2},
						  {   3, "Candy"   ,   4},
						  {   5, "Rolla"   , nil},
						  { nil, "Ann"     , nil},
						  {   6, "Emy"     ,   7},
						  { nil, "Nancy"   , nil},
						  { nil, "Eluza"   , nil},
						  { nil, "Lisa"    , nil}};
	char key[12];
	int p, i, old;
	int sp = 8;
	char keys[6][12] = {"A", "Nancyx", "Lisa", "Rollax", "X", "Lisz"};
	for(i = 0; i < 6; i++){
		strcpy(key, keys[i]);
		p = 0;
		printf("add %s\n", key);
		while(p != nil){
			old = p;
			printf("  %8s ", a[p].name);
			if(strcmp(key, a[p].name) <= 0){
				printf("move left\n");
				p = a[p].left;
			}else{
				printf("move right\n");
				p = a[p].right;
			}
		}
		a[sp].left = a[sp].right = nil;
		strcpy(a[sp].name, key);
		if(strcmp(key, a[old].name) <= 0){
			a[old].left = sp;
		}else{
			a[old].right = sp;
		}
		sp++;
	}
	for(i = 0; i < sp; i++){
		printf("%2d%4d%12s%4d\n", i, a[i].left, a[i].name, a[i].right);
	}

}

void bt_main3(){
	char keys[8][12] = {"Machilda",
					 "Candy"   ,
					 "Rolla"   ,
					 "Ann"     ,
					 "Emy"     ,
					 "Nancy"   ,
					 "Eluza"   ,
					 "Lisa"    };
	char key[12];
	Tnode2 *root, *p, *old;
	int i;
	root = talloc();
	printf("add %s\n", keys[0]);
	strcpy(root->name, keys[0]);
	root->left = root->right = NULL;


	for(i = 1; i < 8; i++){
		strcpy(key, keys[i]);
		p = root;
		printf("add %s\n", key);
		while(p != NULL){
			old = p;
			printf("  %8s ", p->name);
			if(strcmp(key, p->name) <= 0){
				printf("move left\n");
				p = p->left;
			}else{
				printf("move right\n");
				p = p->right;
			}
		}
		p = talloc();
		strcpy(p->name, key);
		p->left = p->right = NULL;
		if(strcmp (key, old->name) <= 0){
			printf("connect left\n");
			old->left = p;
		}else{
			printf("connect right\n");
			old->right = p;
		}

	}
	p = root;
	while(p->left != NULL){
		p = p->left;
		printf("left %s\n", p->name);
	}
	p = root;
	while(p->right != NULL){
		p = p->right;
		printf("right %s\n", p->name);
	}

}

Tnode2  *talloc(){
	return (Tnode2 *)malloc(sizeof(Tnode2));
}

void bt_main4(){
	char keys[8][12] = {"Machilda",
					 "Candy"   ,
					 "Rolla"   ,
					 "Ann"     ,
					 "Emy"     ,
					 "Nancy"   ,
					 "Eluza"   ,
					 "Lisa"    };
	char key[12];
	Tnode2 *root;
	int i;
	root = NULL;
	printf("\n\nstart bt_main4\n");
	for(i = 0; i < 8; i++){
		strcpy(key, keys[i]);
		printf("add %s\n", key);
		root = gentree(root, key);
	}
}

Tnode2 *gentree(Tnode2 *p, char *w){
	if(p == NULL){
		p = talloc();
		strcpy(p->name, w);
		p->left = p->right = NULL;
	}else if(strcmp (w, p->name) < 0){
		printf("move left %s\n", p->name);
		p->left = gentree(p->left, w);
	}else{
		printf("move right %s\n", p->name);
		p->right = gentree(p->right, w);
	}
	return p;
}

void bt_main5(){
	char keys[8][12] = {"Machilda",
					 "Candy"   ,
					 "Rolla"   ,
					 "Ann"     ,
					 "Emy"     ,
					 "Nancy"   ,
					 "Eluza"   ,
					 "Lisa"    };
	char key[12];
	char searchs[6][12] = {"A", "Nancyx", "Lisa", "Rollax", "X", "Lisz"};
	Tnode2 *root, *p;
	int i;
	root = NULL;
	printf("\n\nstart bt_main5\n");
	for(i = 0; i < 8; i++){
		strcpy(key, keys[i]);
		printf("add %s\n", key);
		root = gentree(root, key);
	}
	for(i = 1; i < 6; i++){
		strcpy(key, searchs[i]);
		printf("search %s\n", key);
		if((p = search(root, key)) != NULL){
			printf("見つかりました\n");
		}else{
			printf("見つかりませんでした\n");
		}
	}
}

Tnode2 *search(Tnode2 *p, char *key){
	if(p == NULL || strcmp(key, p->name) == 0){
		return p;
	}else if(strcmp(key, p->name) < 0){
		printf("search left %s\n", p->name);
		return search(p->left, key);
	}else{
		printf("search right %s\n", p->name);
		return search(p->right, key);
	}
}

void bt_main6(){
	char keys[8][12] = {"Machilda",
					 "Candy"   ,
					 "Rolla"   ,
					 "Ann"     ,
					 "Emy"     ,
					 "Nancy"   ,
					 "Eluza"   ,
					 "Lisa"    };
	char key[12];
	Tnode2 *root;
	int i;
	root = NULL;
	printf("\n\nstart bt_main6  \n");
	for(i = 0; i < 8; i++){
		strcpy(key, keys[i]);
		printf("add %s\n", key);
		//&はアドレスを渡す
		gentree2(&root, key);
	}
}

void gentree2(Tnode2 **p, char *w){
	if((*p) == NULL){
		(*p) = talloc();
		strcpy((*p)->name, w);
		(*p)->left = (*p)->right = NULL;
	}else if(strcmp (w, (*p)->name) < 0){
		printf("move left %s\n", (*p)->name);
		gentree2(&((*p)->left), w);
	}else{
		printf("move right %s\n", (*p)->name);
		gentree2(&((*p)->right), w);
	}
}

void bt_main7(){
	char keys[8][12] = {"Machilda",
					 "Candy"   ,
					 "Rolla"   ,
					 "Ann"     ,
					 "Emy"     ,
					 "Nancy"   ,
					 "Eluza"   ,
					 "Lisa"    };
	char key[12];
	Tnode2 *root;
	int i;
	root = NULL;
	printf("\n\nstart bt_main7  \n");
	for(i = 0; i < 8; i++){
		strcpy(key, keys[i]);
		printf("add %s\n", key);
		root = gentree(root, key);
	}
	treewalk(root);
}

void treewalk(Tnode2 *p){
	if(p != NULL){
		treewalk(p->left);
		printf("%s\n",p->name);
		treewalk(p->right);
	}
}

void bt_main8(){
	char keys[8][12] = {"Machilda",
					 "Candy"   ,
					 "Rolla"   ,
					 "Ann"     ,
					 "Emy"     ,
					 "Nancy"   ,
					 "Eluza"   ,
					 "Lisa"    };
	char key[12];
	Tnode2 *root;
	int i;
	root = NULL;
	printf("\n\nstart bt_main8  \n");
	for(i = 0; i < 8; i++){
		strcpy(key, keys[i]);
		printf("add %s\n", key);
		root = gentree(root, key);
	}
	treewalk2(root);
}

/**
 * 再帰を使わずスタックで実装
 */
void treewalk2(Tnode2 *p){
	Tnode2 *q, *w[128];
	int sp = 0;
	q = p;
	while(!(sp == 0 && q == NULL)){
		while(q != NULL){
			w[sp++]  = q;
			q = q->left;
		}
		sp--;
		printf("%s\n", w[sp]->name);
		q = w[sp]->right;
	}
}

void bt_main9(){
	char keys[8][12] = {
					"Machilda" ,
					 "Candy"   ,
					 "Rolla"   ,
					 "Ann"     ,
					 "Emy"     ,
					 "Nancy"   ,
					 "Eluza"   ,
					 "Lisa"    };
	char key[12];
	Tnode2 *root;
	int i;
	root = NULL;
	printf("\n\nstart bt_main9  \n");
	for(i = 0; i < 8; i++){
		strcpy(key, keys[i]);
		printf("add %s\n", key);
		root = gentree(root, key);
	}
	treewalk3(root);
}

void treewalk3(Tnode2 *p){
	Tnode2 *q[128], *w[128];
	int i, child, n, level;
	child = 1, q[0] = p, level = 0;
	do{
		n = 0;
		printf("level %d : ", level);
		//スタックに入れる
		for(i = 0; i < child; i++){
			printf("%12s", q[i]->name);
			if(q[i]->left != NULL){
				w[n++] = q[i]->left;
			}
			if(q[i]->right != NULL){
				w[n++] = q[i]->right;
			}
		}
		printf("\n");
		child = n;
		for(i = 0; i < child; i++){
			q[i] = w[i];
		}
		level++;
	}while(child != 0);
}

void bt_main10(){
	char keys[8][12] = {
					"Machilda" ,
					 "Lisa"    ,
					 "Candy"   ,
					 "Ann"     ,
					 "Emy"     ,
					 "Eluza"   ,
					 "Nancy"   ,
					 "Rolla"   ,
	};
	char key[12];
	Tnode2 *root;
	int i;
	root = NULL;
	printf("\n\nstart bt_main9  \n");
	for(i = 0; i < 8; i++){
		strcpy(key, keys[i]);
		printf("add %s\n", key);
		root = gentree(root, key);
	}
	treewalk4(root);
}

void treewalk4(Tnode2 *p){
	struct connect{
		struct tnode2 *node;
		char *parent;
		char direct;
	} q[128], w[128];

	int i, child, n, level;
	child = 1, level = 0;
	q[0].node = p;
	q[0].parent = "root";
	q[0].direct = ' ';
	do{
		n = 0;
		printf("level %d : \n", level);
		//スタックに入れる
		for(i = 0; i < child; i++){
			printf("%12s->%c:%12s\n", q[i].parent, q[i].direct, q[i].node->name);

			if(q[i].node->left != NULL){
				w[n].parent = q[i].node->name;
				w[n].direct = 'l';
				w[n].node = q[i].node->left;
				n++;
			}
			if(q[i].node->right != NULL){
				w[n].parent = q[i].node->name;
				w[n].direct = 'r';
				w[n].node = q[i].node->right;
				n++;
			}
		}
		child = n;
		for(i = 0; i < child; i++){
			q[i] = w[i];
		}
		level++;
	}while(child != 0);
}

void heap_main(){
	int n, i, s, p, w, x;
	n = 1;
	int heap[11];
	int tmp[10];
	printf("\nheap_main\n");
	srand( (unsigned)time( NULL ) );
	for(x = 0; x < 10; x++){
		heap[x + 1] = tmp[x] = rand() % 100;
		printf("%2d ", tmp[x]);
	}
	printf("\n");
	for(x = 0; x < 10; x++){
		heap[n] = tmp[x];
		s = n;
		p = s / 2;
		printf("x = %2d p = %2d s = %2d heap[p] = %2d heap[s] = %2d\n", x , p, s, heap[p], heap[s]);
		while(s >= 2 && heap[p] > heap[s]){
			printf("swap   p = %2d s = %2d heap[p] = %2d heap[s] = %2d\n", p, s, heap[p], heap[s]);
			w = heap[p];
			heap[p] = heap[s];
			heap[s] = w;
			for(i = 1; i < 11; i++)
				printf("%2d ", heap[i]);
			printf("\n");
			//親やへと進む ex 5 10 => 2 5 => 1 2 s/2が親
			s = p;
			p = s / 2;
		}
		n++;
	}
	for(i = 1; i < n; i++)
		printf("%2d ", heap[i]);
	printf("\n");

}

void heap_main2(){
	int heap[100];
	int tmp[10];
	int n, i, s, p, x, m;
	n = 11;
	m = n - 1;
	printf("\nheap_main2\n");
	srand( (unsigned)time( NULL ) );
	for(x = 0; x < 10; x++){
		heap[x + 1] = tmp[x] = rand() % 100;
		printf("%2d ", tmp[x]);
	}
	printf("\n");
	for(i = m / 2; i >= 1; i--){
		p = i; //親の位置
		s = 2 * p; //左の子の位置
		printf("i = %2d p = %2d s = %2d\n", i, p, s);
		while(s <= m){
			if(s < m)
				printf("p = %2d s = %2d heap[p] = %2d heap[s] = %2d heap[s + 1] = %2d\n", p, s,heap[p], heap[s], heap[s + 1]);
			else
				printf("p = %2d s = %2d heap[p] = %2d heap[s] = %2d \n", p, s, heap[p], heap[s]);
			//交換するのを左にするか右にするかを決める
			if(s < m && heap[s + 1] < heap[s])
				s++;
			//親のほうが大きい場合は交換しない
			if(heap[p] <= heap[s])
				break;
			printf("swap %2d %2d \n", heap[p], heap[s]);
			swap(&heap[p], &heap[s]);
			for(x = 1; x <= m; x++)
				printf("%2d ", heap[x]);
			printf("\n");
			p = s;
			s = 2 * p;
		}
	}
	for(i = 1; i <= m; i++)
		printf("%2d ", heap[i]);
	printf("\n");
}

void swap(int *a, int *b){
	int w;
	w = *a; *a = *b; *b = w;
}

void heap_main3(){
	int heap[100];
	int tmp[10];
	int n, i, m, x;
	n = 1;
	printf("\nheap_main3\n");
	srand( (unsigned)time( NULL ) );
	for(x = 0; x < 10; x++){
		heap[x + 1] = tmp[x] = rand() % 100;
		printf("%2d ", tmp[x]);
		n++;
	}
	printf("\n");
	m = n - 1;
	//ピープの作成
	for(i = m / 2; i >= 1; i--){
		shiftdown(i, m, heap);
	}
	printf("\ngenerate heap\n");
	for(i = 1; i < n; i++)
		printf("%2d ", heap[i]);
	printf("\n\n");
	while(m > 1){
		printf("swap %2d %2d m = %2d\n", heap[1], heap[m], m);
		//heap[1]が根であり一番小さくなっているのでそれを切り離す
		//mが現在の１heapの大きさ
		swap(&heap[1], &heap[m]);
		for(x = 1; x < 11; x++)
			printf("%2d ", heap[x]);
		printf("\n");

		m--;
		shiftdown(1, m, heap);
	}
	for(i = 1; i < n; i++)
		printf("%2d ", heap[i]);
	printf("\n");
}

void shiftdown(int p, int n, int heap[]){
	int s, x;
	s = 2 * p;
	printf("p = %2d s = %2d\n", p, s);
	while(s <= n){
		if(s < n)
			printf("p = %2d s = %2d heap[p] = %2d heap[s] = %2d heap[s + 1] = %2d\n", p, s,heap[p], heap[s], heap[s + 1]);
		else
			printf("p = %2d s = %2d heap[p] = %2d heap[s] = %2d \n", p, s, heap[p], heap[s]);
		//交換するのを左にするか右にするかを決める
		if(s < n && heap[s + 1] < heap[s])
			s++;
		//親のほうが大きい場合は交換しない
		if(heap[p] <= heap[s])
			break;
		printf("swap %2d %2d \n", heap[p], heap[s]);
		swap(&heap[p], &heap[s]);
		for(x = 1; x < 11; x++)
			printf("%2d ", heap[x]);
		printf("\n");
		p = s;
		s = 2 * p;
	}
}
void treeform_main(){
	Tnode3 *root;
	char expression[] = "ab*cd+e/-";

	printf("\n   base = %s", expression);
	printf("\n");
	root = NULL;
	root = gentree3(root, expression, "root");


	printf("\n prefix = ");  prefix(root);
	printf("\n  infix = ");   infix(root);
	printf("\npostfix = "); postfix(root);
	printf("\n");
}

Tnode3 *gentree3(Tnode3 *p, char *w, char *node){
	int n;
	//1文字づつ減らしていく
	n = strlen(w);
	p = talloc3();
	p->ope = w[n - 1];
	w[n - 1] = '\0';
	printf("%c %s %s",p->ope, node, w);
	if(!(p->ope == '-' || p->ope == '+' || p->ope == '*' || p->ope == '/' )){
		p->left = p->right = NULL;
		printf(" stop\n");
	}else{
		printf("\n");
		p->right = gentree3(p->right, w, "rght");
		p->left = gentree3(p->left, w, "left");
	}
	return p;
}

void prefix(Tnode3 *p){
	if(p != NULL){
		putchar(p->ope);
		prefix(p->left);
		prefix(p->right);
	}
}

void infix(Tnode3 *p){
	if(p != NULL){
		infix(p->left);
		putchar(p->ope);
		infix(p->right);
	}
}

void postfix(Tnode3 *p){
	if(p != NULL){
		postfix(p->left);
		postfix(p->right);
		putchar(p->ope);
	}
}

Tnode3  *talloc3(){
	return (Tnode3 *)malloc(sizeof(Tnode3));
}

void treeform_main2(){
	Tnode4 *root;
	char expression[] = "53*64+2/-";

	printf("\n   base = %s", expression);
	printf("\n");
	root = NULL;
	root = gentree4(root, expression, "root");

	postfix2(root);
	printf("\n value = %d\n", root->ope);
}

Tnode4 *gentree4(Tnode4 *p, char *w, char *node){
	int n;
	//1文字づつ減らしていく
	n = strlen(w);
	p = talloc4();
	if('0' < w[n - 1] && w[n - 1] <= '9'){
		p->ope = w[n -1] - '0'; //定数のときは数値に変換
		printf("%d ",p->ope);
	}else{
		p->ope = w[n -1];
		printf("%c ",p->ope);
	}
	w[n - 1] = '\0';
	printf("%s %s",node, w);
	if(!(p->ope == '-' || p->ope == '+' || p->ope == '*' || p->ope == '/' )){
		p->left = p->right = NULL;
		printf(" stop\n");
	}else{
		printf("\n");
		p->right = gentree4(p->right, w, "rght");
		p->left = gentree4(p->left, w, "left");
	}
	return p;
}

void postfix2(Tnode4 *p){
	if(p != NULL){
		postfix2(p->left);
		postfix2(p->right);
		switch(p->ope){
		case '+': p->ope = (p->left->ope) + (p->right->ope); break;
		case '-': p->ope = (p->left->ope) - (p->right->ope); break;
		case '*': p->ope = (p->left->ope) * (p->right->ope); break;
		case '/': p->ope = (p->left->ope) / (p->right->ope); break;
		}
	}
}

Tnode4  *talloc4(){
	return (Tnode4 *)malloc(sizeof(Tnode4));
}


