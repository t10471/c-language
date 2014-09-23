/*
 ============================================================================
 Name        : algorithm_5_data.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <locale.h>
#include <string.h>
// #include <tchar.h>
#include <math.h>
#include <stdlib.h> /* randとsrandを使うため */
#include <time.h>  /* timeを使うため */

#define StackMaxSize 5
#define StackHanoiMaxSize 20
#define QueueMaxSize 5
#ifndef TRUE            /* TRUE が定義されていなかったら */
#define TRUE 1
#endif
#ifndef FALSE           /* FALSE が定義されていなかったら */
#define FALSE 0
#endif

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

#define ChainHashTableSize 1000
#define ChainHashModSize   1000

#define ChainHash2TableSize 1000
#define ChainHash2ModSize   1000

void stack_main();
int push(int);
int pop(int *);
int stack_stack[StackMaxSize];
int stack_sp = 0;
void stack_hanoi();
void hanoi(int, int, int, int);
void move(int, int, int);
int stack_hanoi_push(int, int);
int stack_hanoi_pop(int *, int);
int stack_hanoi_pie[3][StackHanoiMaxSize];
int stack_hanoi_sp[3] , stack_hanoi_n = 3;
void queue_main();
int queue_queue[QueueMaxSize];
int queue_head = 0;
int queue_tail = 0;
int queue_queue_in(int);
int queue_queue_out(int *);
void display();

void list_main();
void list2_main();


//先に宣言する
typedef struct tfield  Tfield;
struct tfield {
	char *name;
	char *tel;
	Tfield *pointer;
} ;
Tfield *talloc();
//typedefを使わない場合
struct tfield2{
	char *name;
	char *tel;
	struct tfield2 *pointer;
};
struct tfield2 *talloc2();

void list3_main();

typedef struct tfield3  Tfield3;
struct tfield3 {
	char *name;
	char *tel;
	Tfield3 *pointer;
} ;
Tfield3 *talloc3();

typedef struct tfield4 Tfield4;
struct tfield4 {
//	char *name;
//	char *tel;
	char name[20];
	char tel[20];
	Tfield4 *pointer;
} ;
Tfield4 *list4_head;
Tfield4 *talloc4();
void list4_main();
void list4_generate();
void list4_display();
void list4_link(char *, char *, char *);

typedef struct tfield5 Tfield5;
struct tfield5 {
//	char *name;
//	char *tel;
	char name[20];
	char tel[20];
	Tfield5 *pointer;
} ;
Tfield5 *list5_head;
Tfield5 *talloc5();
void list5_main();
void list5_generate();
void list5_display();
void list5_link(char *, char *, char *);

void list6_main();
typedef struct tfield6 Tfield6;
struct tfield6 {
	char name[20];
	char tel[20];
	Tfield6 *pointer;
} ;
Tfield6 *talloc6();

typedef struct tfield7 Tfield7;
struct tfield7 {
	char name[20];
	char tel[20];
	Tfield7 *pointer;
} ;
Tfield7 *list7_head;
Tfield7 *talloc7();
void list7_main();
void list7_generate();
void list7_display();
void list7_del(char *);

typedef struct tfield8 Tfield8;
struct tfield8 {
	char name[20];
	char tel[20];
	Tfield8 *pointer;
} ;
Tfield8 *list8_head;
Tfield8 *talloc8();
void list8_main();
void list8_generate();
void list8_display();
void list8_del(char *);

void doubly_linked_list();
typedef struct doubly_linked_list DoublyLinkedList;
struct doubly_linked_list {
	DoublyLinkedList *left;
	char name[20];
	char tel[20];
	DoublyLinkedList *right;
} ;
DoublyLinkedList *doubly_linked_list_talloc();

void doubly_linked_list2();
typedef struct doubly_linked_list2 DoublyLinkedList2;
struct doubly_linked_list2 {
	DoublyLinkedList2 *left;
	char name[20];
	char tel[20];
	DoublyLinkedList2 *right;
} ;
DoublyLinkedList2 *doubly_linked_list2_talloc();

void reverse_polish_rotation1();
void reverse_polish_rotation2();
void reverse_polish_rotation3();
void reverse_polish_rotation4();
void reverse_polish_rotation5();

void self_re_organiing_search();

typedef struct sfield Sfield;
struct sfield {
	char name[20];
	char tel[20];
	Sfield *pointer;
} ;
Sfield *salloc();

void self_re_organiing_search2();

typedef struct sfield2 Sfield2;
struct sfield2 {
	char name[20];
	char tel[20];
	Sfield2 *pointer;
} ;
Sfield2 *salloc2();

void chain_hash_main();
int chain_hash_hash(char *);

typedef struct cfield Cfield;
struct cfield {
	char name[20];
	char tel[20];
	Cfield *pointer;
} ;
Cfield *dat[ChainHashTableSize];

Cfield *ccalloc();

void chain_hash2_main();
int chain_hash2_hash(char *);

typedef struct cfield2 Cfield2;
struct cfield2 {
	char name[20];
	char tel[20];
	Cfield2 *pointer;
} ;
Cfield2 *dat2[ChainHash2TableSize];

Cfield2 *ccalloc2();


int main(void) {
	stack_main();
	stack_hanoi();
	queue_main();
	list_main();
	list2_main();
	list3_main();
	list4_main();
	list5_main();
	list6_main();
	list7_main();
	list8_main();
	doubly_linked_list();
	doubly_linked_list2();
	reverse_polish_rotation1();
	reverse_polish_rotation2();
	reverse_polish_rotation3();
	reverse_polish_rotation4();
	reverse_polish_rotation5();
	self_re_organiing_search();
	self_re_organiing_search2();
	chain_hash_main();
	chain_hash2_main();
	return EXIT_SUCCESS;
}

void stack_main(){
	int i, n, test[] = {1, 2, 3, 4, 5, 6};
	for(i = 0; i < 6; i++){
		n = test[i];
		printf("input %2d ", n);
		if(push(n) == -1){
			printf("スタックがいっぱいです \n");
		}else{
			printf("\n");
		}
	}
	for(i = 0; i < 6; i++){
		if(pop(&n) == -1){
			printf("スタックがからです \n");
		}else{
			printf("out %2d\n", n);
		}
	}
}

int push(int n){
	if(stack_sp < StackMaxSize){
		stack_stack[stack_sp] = n;
		stack_sp++;
		return 0;
	}
	return -1;
}

int pop(int *n){
	if(stack_sp > 0){
		stack_sp--;
		*n = stack_stack[stack_sp];
		return 0;
	}
	return -1;
}


void stack_hanoi(){
	int i;
	printf("\n");
	printf("\n");
	printf("円盤の枚数 %d \n", stack_hanoi_n);
	//スタックポインタ初期化
	for(i = 0; i < 3; i++) stack_hanoi_sp[i] = 0;
	//棒に円盤をつむ
	for(i = 0; i < stack_hanoi_n; i++) stack_hanoi_push(stack_hanoi_n - i, 0);
	hanoi(stack_hanoi_n, 0, 1, 2);
}
void hanoi(int n, int a, int b, int c){
	if(n > 0){
		hanoi(n - 1, a, c, b);
		move(n, a, b);
		hanoi(n - 1, c, b, a);
	}
}

void move(int n, int s, int d){
	int i, j, t;
	int bk[3][20];
	int bk_sp[3];
	printf("input n=%d s=%d d=%d \n", n, s, d);
	for(j = stack_hanoi_n - 1; j >= 0; j--)
		for(i = 0; i < 3; i++) bk[i][j] = stack_hanoi_pie[i][j];
	for(i = 0; i < 3; i++) bk_sp[i] = stack_hanoi_sp[i];

	//s -> dに移動
	stack_hanoi_pop(&t, s);
	stack_hanoi_push(t, d);

	printf("sp    ");
	for(i = 0; i < 3; i++) printf("%d ", bk_sp[i]);
	printf(" -> ");
	for(i = 0; i < 3; i++) printf("%d ", stack_hanoi_sp[i]);
	printf("\n");
	for(j = stack_hanoi_n - 1; j >= 0; j--){
		printf("pie   ");
		for(i = 0; i < 3; i++) printf("%d ", bk[i][j]);
		printf(" -> ");
		for(i = 0; i < 3; i++) printf("%d ", stack_hanoi_pie[i][j]);
		printf("\n");
	}

	for(j = stack_hanoi_n - 1; j >= 0; j--){
		printf("debug j=%d ", j);
		for(i = 0; i < 3; i++){
			printf("%d", stack_hanoi_sp[i]);
			if(j < stack_hanoi_sp[i])
				printf("(T)");
			else
				printf("(F)");
		}
		printf("\n");
	}
	printf("%d 番目の円盤を %c --> %c に移す \n", n, 'a' + s, 'a' + d);
	for(j = stack_hanoi_n - 1; j >= 0; j--){
		for(i = 0; i < 3; i++){
			if(j < stack_hanoi_sp[i])
				printf("%8d", stack_hanoi_pie[i][j]);
			else
				printf("        ");
		}
		printf("\n");
	}
	printf("       a       b       c\n");
}

int stack_hanoi_push(int n, int i){
	if(stack_hanoi_sp[i] < StackHanoiMaxSize){
		stack_hanoi_pie[i][stack_hanoi_sp[i]] = n;
		//後で減算
		stack_hanoi_sp[i]++;
		return 0;
	}
	return -1;
}

int stack_hanoi_pop(int *n, int i){
	if(stack_hanoi_sp[i] > 0){
		//先に減算
		stack_hanoi_sp[i]--;
		*n = stack_hanoi_pie[i][stack_hanoi_sp[i]];
		return 0;
	}
	return -1;
}


void queue_main(){
	int i, n, x;
	srand( (unsigned)time( NULL ) );
	for(i = 0; i < 50; i++){
		x =  rand();
		if(x % 2 == 0 || x % 5 == 0 ){
			n = i;
			printf("head %d tail %d ", queue_head, queue_tail);
			printf("input %2d ", n);
			if(queue_queue_in(n) == -1){
				printf("キューがいっぱいです \n");
				queue_queue_out(&n);
				printf("head %d tail %d ", queue_head, queue_tail);
				printf("out %2d\n", n);
				queue_queue_out(&n);
				printf("head %d tail %d ", queue_head, queue_tail);
				printf("out %2d\n", n);
				printf("head %d tail %d ", queue_head, queue_tail);
				queue_queue_out(&n);
				printf("out %2d\n", n);

			}else{
				printf("\n");
			}
		}else if(x % 3 == 0){
			printf("head %d tail %d ", queue_head, queue_tail);
			if(queue_queue_out(&n) == -1){
				printf("キューがからです \n");
			}else{
				printf("out %2d\n", n);
			}
		}else{
			display();
		}
	}
}

int queue_queue_in(int n){
	//キューはheadとtailの差で計算する
	//いっぱいの場合
	//head 1 tail 0 -> 1 % 5 = 1
	//head 2 tail 1 -> 2 % 5 = 2
	//head 3 tail 2 -> 3 % 5 = 3
	//head 4 tail 3 -> 4 % 5 = 4
	//head 0 tail 4 -> 5 % 5 = 0
	if((queue_tail + 1) % QueueMaxSize != queue_head){
		queue_queue[queue_tail] = n;
		queue_tail++;
		queue_tail = queue_tail % QueueMaxSize;
		return 0;
	}
	return -1;
}

int queue_queue_out(int *n){
	if(queue_tail != queue_head){
		*n = queue_queue[queue_head];
		queue_head++;
		queue_head = queue_head % QueueMaxSize;
		return 0;
	}
	return -1;
}

void display(){
	int i;
	i = queue_head;
	printf("display ");
	while(i != queue_tail){
		printf("%d ", queue_queue[i]);
		i++;
		i = i % QueueMaxSize;
	}
	printf("\n");
}

/*
 * 先頭にレコードを挿入する
 */
void list_main(){
	int i;
	Tfield *head, *p;
	char names[3][20] = {
			"ALICE",
			"MERRY",
			"ELLEY"
	};
	char tels[3][20] = {
			"1234-5678",
			"999-9999",
			"0000-0000"
	};
	printf("list_main\n");
	head = NULL;
	for(i = 0; i < 3; i++){
		p = talloc();
		p->name = names[i];
		p->tel = tels[i];
		p->pointer = head;
		head = p;
	}
	//この時点絵最後に挿入したレコードがhead
	p = head;
	while(p != NULL){
		printf("%15s%15s\n", p->name, p->tel);
		p = p->pointer;
	}
}

Tfield  *talloc(){
	return (Tfield *)malloc(sizeof(Tfield));
}

/**
 * typedefを使用しない場合
 */
void list2_main(){
	int i;
	struct tfield2 *head, *p;
	char names[3][20] = {
			"ALICE",
			"MERRY",
			"ELLEY"
	};
	char tels[3][20] = {
			"1234-5678",
			"999-9999",
			"0000-0000"
	};
	printf("list2_main\n");
	head = NULL;
	for(i = 0; i < 3; i++){
		p = talloc2();
		p->name = names[i];
		p->tel = tels[i];
		p->pointer = head;
		head = p;
	}
	p = head;
	while(p != NULL){
		printf("%15s%15s\n", p->name, p->tel);
		p = p->pointer;
	}
}

struct tfield2 *talloc2(){
	return (struct tfield2 *)malloc(sizeof(struct tfield2));
}

/**
 * 入力順のリスト
 */
void list3_main(){
	int i, end;
	Tfield3 *head, *p, *current;
	end = 3;
	char names[3][20] = {
			"ALICE",
			"MERRY",
			"ELLEY"
	};
	char tels[3][20] = {
			"1234-5678",
			"999-9999",
			"0000-0000"
	};
	printf("list3_main\n");
	for(i = 0; i < end; i++){
		p = talloc3();
		p->name = names[i];
		p->tel = tels[i];
		if(i == 0)
			head = p; //headをとっておかないと、表示のループがまわせない
		else if(i == end)
			current->pointer  = NULL; //リストの終わりを指定
		else
			current->pointer  = p;
		//currentが現在のリストの最後尾を更新
		current  = p;
	}
	p = head;
	while(p != NULL){
		printf("%15s%15s\n", p->name, p->tel);
		p = p->pointer;
	}
}

Tfield3  *talloc3(){
	return (Tfield3 *)malloc(sizeof(Tfield3));
}

/**
 * リストの追加
 */
void list4_main(){
	int i, end;
	char searches[3][20] = {
			"ALICE",
			"zMERRY",
			"ELLEY"
	};
	char names[3][20] = {
			"xALICE",
			"xMERRY",
			"xELLEY"
	};
	char tels[3][20] = {
			"x1234-5678",
			"x999-9999",
			"x0000-0000"
	};
	printf("list4_main\n");
	end = 3;
	list4_generate();
	list4_display();
	for(i = 0; i < end; i++){
		list4_link(searches[i], names[i], tels[i]);
	}
	list4_display();
}

void list4_generate(){
	int i, end;
	Tfield4 *p;
	char names[3][20] = {
			"ALICE",
			"MERRY",
			"ELLEY"
	};
	char tels[3][20] = {
			"1234-5678",
			"999-9999",
			"0000-0000"
	};
	end = 3;
	list4_head = NULL;
	for(i = 0; i < end; i++){
		p = talloc4();
		strcpy(p->name, names[i]);
		strcpy(p->tel, tels[i]);
//		p->name = names[i];
//		p->tel = tels[i];
		p->pointer = list4_head;
		list4_head = p;
	}
}

void list4_display(){
	Tfield4 *p;
	p = list4_head;
	printf("display\n");
	while(p != NULL){
		printf("%15s%15s\n", p->name, p->tel);
		p = p->pointer;
	}
}

void list4_link(char *search, char *name, char *tel){
	Tfield4 *p, *n;
	n = talloc4();
	strcpy(n->name, name);
	strcpy(n->tel, tel);
//	n->name = name;
//	n->tel = tel;
	printf("追加データ %s %s %s\n", search, name, tel);
	p = list4_head;
	while(p != NULL){
		printf("search  %s %s\n", search, p->name);
		if(strcmp(search, p->name) == 0){
			n->pointer = p->pointer;
			p->pointer = n;
			return;
		}
		p = p->pointer;
	}
	printf("キーが見つかりませんでした\n");
}

Tfield4  *talloc4(){
	return (Tfield4 *)malloc(sizeof(Tfield4));
}

/**
 * リストの追加なければ先頭に追加
 */
void list5_main(){
	int i, end;
	char searches[3][20] = {
			"ALICE",
			"zMERRY",
			"ELLEY"
	};
	char names[3][20] = {
			"xALICE",
			"xMERRY",
			"xELLEY"
	};
	char tels[3][20] = {
			"x1234-5678",
			"x999-9999",
			"x0000-0000"
	};
	printf("list5_main\n");
	end = 3;
	list5_generate();
	list5_display();
	for(i = 0; i < end; i++){
		list5_link(searches[i], names[i], tels[i]);
	}
	list5_display();
}

void list5_generate(){
	int i, end;
	Tfield5 *p;
	char names[3][20] = {
			"ALICE",
			"MERRY",
			"ELLEY"
	};
	char tels[3][20] = {
			"1234-5678",
			"999-9999",
			"0000-0000"
	};
	end = 3;
	list5_head = NULL;
	for(i = 0; i < end; i++){
		p = talloc5();
		strcpy(p->name, names[i]);
		strcpy(p->tel, tels[i]);
//		p->name = names[i];
//		p->tel = tels[i];
		p->pointer = list5_head;
		list5_head = p;
	}
}

void list5_display(){
	Tfield5 *p;
	p = list5_head;
	printf("display\n");
	while(p != NULL){
		printf("%15s%15s\n", p->name, p->tel);
		p = p->pointer;
	}
}

void list5_link(char *search, char *name, char *tel){
	Tfield5 *p, *n;
	n = talloc5();
	strcpy(n->name, name);
	strcpy(n->tel, tel);
//	n->name = name;
//	n->tel = tel;
	printf("追加データ %s %s %s\n", search, name, tel);
	p = list5_head;
	while(p != NULL){
		printf("search  %s %s\n", search, p->name);
		if(strcmp(search, p->name) == 0){
			n->pointer = p->pointer;
			p->pointer = n;
			return;
		}
		p = p->pointer;
	}
	printf("%s が見つからないので先頭に追加します\n", search);
	n->pointer = list5_head;
	list5_head = n;
}

Tfield5  *talloc5(){
	return (Tfield5 *)malloc(sizeof(Tfield5));
}

/**
 * 番兵を用いた検索
 * 番兵に検索文字を入れて、ポインタの位置で
 * 成功か判断する
 */
void list6_main(){
	int i;
	Tfield6 *head, *p, sentinel;
	char search[2][20] = {"xMERRY", "MERRY"};
	char names[3][20] = {
			"ALICE",
			"MERRY",
			"ELLEY"
	};
	char tels[3][20] = {
			"1234-5678",
			"999-9999",
			"0000-0000"
	};
	printf("list2_main\n");
	head = &sentinel;
	for(i = 0; i < 3; i++){
		p = talloc6();
		strcpy(p->name, names[i]);
		strcpy(p->tel, tels[i]);
		p->pointer = head;
		head = p;
	}

	p = head;
	for(i = 0; i < 2; i++){
		printf("search %s\n", search[i]);
		//番兵に検索文字を設定する
		strcpy(sentinel.name, search[i]);
		while(strcmp(search[i], p->name) != 0)
			p = p->pointer;
		if(p != &sentinel)
			printf("%s %s\n", p->name, p->tel);
		else
			printf("見つかりません\n");
		p = head;
	}
}

Tfield6  *talloc6(){
	return (Tfield6 *)malloc(sizeof(Tfield6));
}

/**
 * リストの削除
 */
void list7_main(){
	int i, end;
	char searches[3][20] = {
			"ALICE",
			"zMERRY",
			"ELLEY"
	};
	printf("list7_main\n");
	end = 3;
	list7_generate();
	list7_display();
	for(i = 0; i < end; i++){
		list7_del(searches[i]);
		list7_display();
	}
}

void list7_generate(){
	int i, end;
	Tfield7 *p;
	char names[3][20] = {
			"ALICE",
			"MERRY",
			"ELLEY"
	};
	char tels[3][20] = {
			"1234-7677",
			"999-9999",
			"0000-0000"
	};
	end = 3;
	list7_head = NULL;
	for(i = 0; i < end; i++){
		p = talloc7();
		strcpy(p->name, names[i]);
		strcpy(p->tel, tels[i]);
		p->pointer = list7_head;
		list7_head = p;
	}
}

void list7_display(){
	Tfield7 *p;
	p = list7_head;
	printf("display\n");
	while(p != NULL){
		printf("%17s%17s\n", p->name, p->tel);
		p = p->pointer;
	}
}

void list7_del(char *search){
	Tfield7 *current, *old;
	current = old = list7_head;
	printf("削除データ %s\n", search);
	while(current != NULL){
		printf("search  %s %s\n", search, current->name);
		if(strcmp(search, current->name) == 0){
			if(current == list7_head)
				list7_head = current->pointer;
			else
				old->pointer = current->pointer;
			return;
		}
		//見つかったときにポインタを変更するために必要
		old = current;
		current = current->pointer;
	}
	printf("%s が見つかりませんでした\n", search);
}

Tfield7  *talloc7(){
	return (Tfield7 *)malloc(sizeof(Tfield7));
}


/**
 * リストの削除
 */
void list8_main(){
	int i, end;
	char searches[3][20] = {
			"ALICE",
			"zMERRY",
			"ELLEY"
	};
	printf("list8_main\n");
	end = 3;
	list8_generate();
	list8_display();
	for(i = 0; i < end; i++){
		list8_del(searches[i]);
		list8_display();
	}
}

/**
 * ダミーつき削除
 */
void list8_generate(){
	int i, end;
	Tfield8 *p;
	char names[3][20] = {
			"ALICE",
			"MERRY",
			"ELLEY"
	};
	char tels[3][20] = {
			"1234-8688",
			"999-9999",
			"0000-0000"
	};
	end = 3;
	list8_head = NULL;
	for(i = 0; i < end; i++){
		p = talloc8();
		strcpy(p->name, names[i]);
		strcpy(p->tel, tels[i]);
		p->pointer = list8_head;
		list8_head = p;
	}
	//ダミーの挿入
	p = talloc8();
	p->pointer = list8_head;
	list8_head = p;
}

void list8_display(){
	Tfield8 *p;
	//ポインタから
	p = list8_head->pointer;
	printf("display\n");
	while(p != NULL){
		printf("%18s%18s\n", p->name, p->tel);
		p = p->pointer;
	}
}

void list8_del(char *search){
	Tfield8 *current;
	current = list8_head;
	printf("削除データ %s\n", search);
	//一個先のポインタから処理する
	while(current->pointer != NULL){
		printf("search  %s %s\n", search, current->pointer->name);
		if(strcmp(search, current->pointer->name) == 0){
			//ダミーが先頭なので、先頭かどうかの場合わけが不要になる
			current->pointer = current->pointer->pointer;
			return;
		}
		current = current->pointer;
	}
	printf("%s が見つかりませんでした\n", search);
}

Tfield8  *talloc8(){
	return (Tfield8 *)malloc(sizeof(Tfield8));
}


void doubly_linked_list(){
	DoublyLinkedList *head, *tail, *p;
	tail = NULL;
	char names[3][20] = {
			"ALICE",
			"MERRY",
			"ELLEY"
	};
	char tels[3][20] = {
			"1234-8688",
			"999-9999",
			"0000-0000"
	};
	int i, end;
	end = 3;
	//逆リストの作成
	tail = NULL;
	for(i = 0; i < end; i++){
		p = doubly_linked_list_talloc();
		strcpy(p->name, names[i]);
		strcpy(p->tel, tels[i]);
		p->left = tail;
		tail = p;
	}
	//順リストの作成
	p = tail;
	head = NULL;
	while(p != NULL){
		p->right = head;
		head = p;
		p = p->left;
	}
	printf("\n順方向リスト\n");
	p = head;
	while(p != NULL){
		printf("%15s%15s\n", p->name, p->tel);
		p = p->right;
	}

	printf("\n逆方向リスト\n");
	p = tail;
	while(p != NULL){
		printf("%15s%15s\n", p->name, p->tel);
		p = p->left;
	}
}

DoublyLinkedList  *doubly_linked_list_talloc(){
	return (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
}

void doubly_linked_list2(){
	DoublyLinkedList2 *head, *p;
	char names[5][20] = {
			"ANN",
			"CANDY",
			"ALICE",
			"MERRY",
			"ELLEY"
	};
	char tels[5][20] = {
			"1111-8688",
			"3333-8688",
			"1234-8688",
			"999-9999",
			"0000-0000"
	};
	int i, end;
	end = 5;
	head = doubly_linked_list2_talloc();
	//右は順方向、左は逆方向
	head->left = head->right = head;
	for(i = 0; i < end; i++){
		p = doubly_linked_list2_talloc();
		strcpy(p->name, names[i]);
		strcpy(p->tel, tels[i]);
		//最終項の右は先頭になる
		p->right = head;
		//head->leftは前回の最後の項目を示している
		p->left = head->left;
		//順方向の接続、head->leftが前回の最終項なので
		head->left->right = p;
		//head->leftが前回の最終項なのでそこに新しいものを追加
		head->left  = p;
	}
	printf("\n順方向リスト\n");
	p = head->right;
	while(p != head){
		printf("%15s%15s\n", p->name, p->tel);
		p = p->right;
	}

	printf("\n逆方向リスト\n");
	p = head->left;
	while(p != head){
		printf("%15s%15s\n", p->name, p->tel);
		p = p->left;
	}
}

DoublyLinkedList2  *doubly_linked_list2_talloc(){
	return (DoublyLinkedList2 *)malloc(sizeof(DoublyLinkedList2));
}

void reverse_polish_rotation1(){
	int i;
	//polishが最終的に登録する配列
	//stackがワーキングメモリ
	char stack[50], polish[50];
	//各文字・記号の優先順位
	int pri[256];
	//sp1がstack用、sp2がpolish用
	int sp1, sp2;
	char *p = "a+b-c*d/e";
	int x;
	x = strlen(p);
	//文字の優先度設定
	for(i =  0; i <= 255; i++)
		pri[i] = 3;
	pri['+'] = pri['-'] = 1;
	pri['*'] = pri['/'] = 2;
	//pri[stack[sp1]]の番兵として設定
	//stack[0]はスタックが空、
	//スタックが空の時は、スルーさせるため番兵
	stack[0] = 0;
	pri[0] = -1;
	sp1 = sp2 = 0;
	//一文字ずつ処理
	while(*p != '\0'){
		printf("in ");
		putchar(*p); printf("(%d)", pri[*p]); printf(" polish ");
		for(i = 1; i <=sp2; i++) putchar(polish[i]);
		for(i = x; i > sp2; i--) printf(" ");
		printf(" stack ");
		for(i = 1; i <=sp1; i++) putchar(stack[i]);
		printf(" comps ");
		//*pの優先順位が低い間stackをpolishへ移す
		while(pri[*p] <= pri[stack[sp1]]){
			putchar(stack[sp1]); printf("(%d) ", pri[stack[sp1]]);
			polish[++sp2] = stack[sp1--];
		}
		putchar(stack[sp1]); printf("(%d)", pri[stack[sp1]]);
		//ひとまずスタックに入れる
		stack[++sp1] = *p++;
		printf("\n");
	}
	//stackの残りを設定
	for(i = sp1; i > 0; i--)
		polish[++sp2] = stack[i];

	for(i = 1; i <=sp2; i++){
		putchar(polish[i]);
	}
	printf("\n");
}
void reverse_polish_rotation2(){
	int i;
	//polishが最終的に登録する配列
	//stackがワーキングメモリ
	char stack[50], polish[50];
	//各文字・記号の優先順位
	int pri[256];
	//sp1がstack用、sp2がpolish用
	int sp1, sp2;
	char *p = "(a+b)*(c+d)";
	int x;
	x = strlen(p);
	//文字の優先度設定
	for(i =  0; i <= 255; i++)
		pri[i] = 3;
	pri['+'] = pri['-'] = 1;
	pri['*'] = pri['/'] = 2;
	pri['('] = 0;
	//pri[stack[sp1]]の番兵として設定
	//stack[0]はスタックが空、
	//スタックが空の時は、スルーさせるため番兵
	stack[0] = 0;
	pri[0] = -1;
	sp1 = sp2 = 0;
	//一文字ずつ処理
	while(*p != '\0'){
		printf("in ");
		putchar(*p); printf("(%d)", pri[*p]); printf(" polish ");
		for(i = 1; i <=sp2; i++) putchar(polish[i]);
		for(i = x; i > sp2; i--) printf(" ");
		printf(" stack ");
		for(i = 1; i <=sp1; i++) putchar(stack[i]);
		if( *p == '('){
			//(をつむ
			stack[++sp1] = *p;
		}else if(*p == ')'){
			//(までpolishに移す
			while(stack[sp1] != '(')
				polish[++sp2] = stack[sp1--];
			//(の分
			sp1--;
		}else{
			//*pの優先順位が低い間stackをpolishへ移す
			printf(" comps ");
			while(pri[*p] <= pri[stack[sp1]]){
				putchar(stack[sp1]); printf("(%d) ", pri[stack[sp1]]);
				polish[++sp2] = stack[sp1--];
			}
			putchar(stack[sp1]); printf("(%d)", pri[stack[sp1]]);
			stack[++sp1] = *p;
		}
		*p++;
		printf("\n");
	}
	//stackの残りを設定
	for(i = sp1; i > 0; i--)
		polish[++sp2] = stack[i];

	for(i = 1; i <=sp2; i++){
		putchar(polish[i]);
	}
	printf("\n");
}
void reverse_polish_rotation3(){
	int i;
	//polishが最終的に登録する配列
	//stackがワーキングメモリ
	char stack[50], polish[50];
	//各文字・記号の優先順位
	int pri[256];
	//sp1がstack用、sp2がpolish用
	int sp1, sp2;
	char *p = "(a+b)*(c+d)";
	int x;
	x = strlen(p);
	//文字の優先度設定
	for(i =  0; i <= 255; i++)
		pri[i] = 3;
	pri['+'] = pri['-'] = 1;
	pri['*'] = pri['/'] = 2;
	pri['('] = 4; pri[')'] = 0;
	//pri[stack[sp1]]の番兵として設定
	//stack[0]はスタックが空、
	//スタックが空の時は、スルーさせるため番兵
	stack[0] = 0;
	pri[0] = -1;
	sp1 = sp2 = 0;
	//一文字ずつ処理
	while(*p != '\0'){
		printf("in ");
		putchar(*p); printf("(%d)", pri[*p]); printf(" polish ");
		for(i = 1; i <=sp2; i++) putchar(polish[i]);
		for(i = x; i > sp2; i--) printf(" ");
		printf(" stack ");
		for(i = 1; i <=sp1; i++) putchar(stack[i]); for(i = x; i > sp1; i--);

		//*pの優先順位が低い間stackをpolishへ移す
		//(は入れるとき(pのとき)は優先度を考えて、なにもスタックから出さない、
		//しかし、スタックのトップにある場合は突き抜けないようにストップさせる
		printf(" comps ");
		while(pri[*p] <= pri[stack[sp1]] && stack[sp1] != '('){
			putchar(stack[sp1]); printf("(%d) ", pri[stack[sp1]]);
			polish[++sp2] = stack[sp1--];
		}
		putchar(stack[sp1]); printf("(%d)", pri[stack[sp1]]);
		if( *p != ')'){
			//スタックに入れる
			stack[++sp1] = *p;
		}else{
			//(の分 ここにくるときはstack[sp1]は必ず(
			printf(" check ");
			putchar(stack[sp1]);
			sp1--;
		}
		*p++;
		printf("\n");
	}
	//stackの残りを設定
	for(i = sp1; i > 0; i--)
		polish[++sp2] = stack[i];

	for(i = 1; i <=sp2; i++){
		putchar(polish[i]);
	}
	printf("\n");
}

void reverse_polish_rotation4(){
	int i;
	//polishが最終的に登録する配列
	//stackがワーキングメモリ
	char stack[50], polish[50];
	//各文字・記号の優先順位
	int pri[256];
	//sp1がstack用、sp2がpolish用
	int sp1, sp2;
	double v[50];
	char *p = "(6+3)/(6-2)+3*2^3-1";
	char *expression = p;
	int x;
	x = strlen(p);
	//文字の優先度設定
	for(i =  0; i <= 255; i++)
		pri[i] = 4;
	pri['+'] = pri['-'] = 1;
	pri['*'] = pri['/'] = 2;
	pri['^'] = 3;
	pri['('] = 5; pri[')'] = 0;
	//pri[stack[sp1]]の番兵として設定
	//stack[0]はスタックが空、
	//スタックが空の時は、スルーさせるため番兵
	stack[0] = 0;
	pri[0] = -1;
	sp1 = sp2 = 0;
	//一文字ずつ処理
	while(*p != '\0'){
		printf("in ");
		putchar(*p); printf("(%d)", pri[*p]); printf(" polish ");
		for(i = 1; i <=sp2; i++) putchar(polish[i]);
		for(i = x; i > sp2; i--) printf(" ");
		printf(" stack ");
		for(i = 1; i <=sp1; i++) putchar(stack[i]); for(i = x; i > sp1; i--);

		//*pの優先順位が低い間stackをpolishへ移す
		//(は入れるとき(pのとき)は優先度を考えて、なにもスタックから出さない、
		//しかし、スタックのトップにある場合は突き抜けないようにストップさせる
		printf(" comps ");
		while(pri[*p] <= pri[stack[sp1]] && stack[sp1] != '('){
			putchar(stack[sp1]); printf("(%d) ", pri[stack[sp1]]);
			polish[++sp2] = stack[sp1--];
		}
		putchar(stack[sp1]); printf("(%d)", pri[stack[sp1]]);
		if( *p != ')'){
			//スタックに入れる
			stack[++sp1] = *p;
		}else{
			//(の分 ここにくるときはstack[sp1]は必ず(
			printf(" check ");
			putchar(stack[sp1]);
			sp1--;
		}
		p++;
		printf("\n");
	}
	//stackの残りを設定
	for(i = sp1; i > 0; i--)
		polish[++sp2] = stack[i];

	sp1 = 0;
	for(i = 1; i <= sp2; i++){
		if('0' <= polish[i] && polish[i] <= '9'){
			v[++sp1] = polish[i] - '0';
		}else{
			switch(polish[i]){
			case '+' : v[sp1 - 1] = v[sp1 - 1] + v[sp1];
			break;
			case '-' : v[sp1 - 1] = v[sp1 - 1] - v[sp1];
			break;
			case '*' : v[sp1 - 1] = v[sp1 - 1] * v[sp1];
			break;
			case '/' : v[sp1 - 1] = v[sp1 - 1] / v[sp1];
			break;
			case '^' : v[sp1 - 1] = pow(v[sp1 - 1], v[sp1]);
			break;
			}
			sp1--;
		}
		printf("at ");
		putchar(polish[i]);
		printf(" ");
		for(x = i+1; x <=sp2; x++){
			putchar(polish[x]);
		}
		printf("\n");
		for(x = 1; x <=sp1; x++) printf("%f ", v[x]);
		printf("\n");

	}
	printf("%s=%f\n", expression, v[1]);
}
void reverse_polish_rotation5(){
	char ope[50];
	//各文字・記号の優先順位
	int pri[256];
	double v[50];
	//sp1がstack用、sp2がpolish用
	int sp1, sp2;
	char *p = "(1>2|2<8|3<4)|(9<2)";
	char *expression = p;
	int x;
	pri['|'] = 1;
	pri['<'] = pri['>'] = 2;
	pri['('] = 3;
	pri[')'] = 0;
	//番兵として設定
	//ope[0]はスタックが空、
	//スタックが空の時は、スルーさせるため番兵
	ope[0] = 0;pri[0] = -1;
	sp1 = sp2 = 0;
	//一文字ずつ処理
	while(*p != '\0'){
		printf("at ");putchar(p[0]);
		printf("\n");
		if('0' <= *p && *p <= '9'){
			v[++sp2] = *p - '0';
		}else{
			while(pri[*p] <= pri[ope[sp1]] && ope[sp1] != '('){
				switch(ope[sp1]){
				case '|' : v[sp2 - 1] = (v[sp2 - 1] + v[sp2])/2;
				break;
				case '>' : v[sp2 - 1] = Max(v[sp2 - 1],v[sp2]);
				break;
				case '<' : v[sp2 - 1] = Min(v[sp2 - 1],v[sp2]);
				break;
				}
				sp1--;sp2--;
				for(x = 1; x <=sp2; x++) printf("%f ", v[x]);
				printf("\n");
			}
			if( *p != ')'){
				//スタックに入れる
				ope[++sp1] = *p;
			}else{
				//(の分 ここにくるときはstack[sp1]は必ず(
				sp1--;
			}
		}
		p++;
	}
	//stackの残りを設定
	while(sp1 > 0){
		switch(ope[sp1]){
		case '|' : v[sp2 - 1] = (v[sp2 - 1] + v[sp2])/2;
		break;
		case '>' : v[sp2 - 1] = Max(v[sp2 - 1],v[sp2]);
		break;
		case '<' : v[sp2 - 1] = Min(v[sp2 - 1],v[sp2]);
		break;
		}
		sp1--;sp2--;
		for(x = 1; x <=sp2; x++) printf("%f ", v[x]);
		printf("\n");
	}
	printf("%s=%f\n", expression, v[1]);
}

void self_re_organiing_search(){
	int i;
	char key[20];
	Sfield *head, *p, *old;
	char names[3][20] = {
			"ALICE",
			"MERRY",
			"ELLEY"
	};
	char tels[3][20] = {
			"1234-5678",
			"999-9999",
			"0000-0000"
	};
	printf("list_main\n");
	head = NULL;
	for(i = 0; i < 3; i++){
		p = salloc();
		strcpy(p->name, names[i]);
		strcpy(p->tel, tels[i]);
		p->pointer = head;
		head = p;
	}
	printf("before\n");
	while(p != NULL){
		printf("%15s%15s\n", p->name, p->tel);
		p = p->pointer;
	}
	strcpy(key, "MERRY");
	p = old = head;
	while(p != NULL){
		if(strcmp(key, p->name) == 0){
			printf("hit %s\n", key);
			printf("%15s%15s\n", p->name, p->tel);
			if(p != head){
				//old->pointerはpを示している
				//old=>p=>nextをold=>nextに
				old->pointer = p->pointer;
				//pを現在のheadの前につける
				p->pointer = head;
				//pを先頭にする
				head = p;
			}
			break;
		}
		old = p;
		p = p->pointer;
	}
	printf("after\n");
	while(p != NULL){
		printf("%15s%15s\n", p->name, p->tel);
		p = p->pointer;
	}
}

Sfield  *salloc(){
	return (Sfield *)malloc(sizeof(Sfield));
}

void self_re_organiing_search2(){
	int i;
	char key[20];
	Sfield2 *head, *p, *old1, *old2, *q;
	char names[4][20] = {
			"ZZAAA",
			"MERRY",
			"ALICE",
			"ELLEY"
	};
	char tels[4][20] = {
			"5678-1234",
			"1234-5678",
			"999-9999",
			"0000-0000"
	};
	printf("list_main\n");
	head = NULL;
	for(i = 0; i < 4; i++){
		p = salloc2();
		strcpy(p->name, names[i]);
		strcpy(p->tel, tels[i]);
		p->pointer = head;
		head = p;
	}
	//ダミーノードを作成
	p = salloc2();
	p->pointer = head;
	head = p;

	p = head->pointer;
	printf("before\n");
	while(p != NULL){
		printf("%15s%15s\n", p->name, p->tel);
		p = p->pointer;
	}
	p = head->pointer;
	old1 = old2 = head;
	strcpy(key, "MERRY");
	while(p != NULL){
		if(strcmp(key, p->name) == 0){
			printf("hit %s\n", key);
			printf("%15s%15s\n", p->name, p->tel);
			if(p != head->pointer){
				//最初の順序old1=>old2=>p
				//目標old1=>p=>old2
				//old1->pointerはold2へのポインタ
				q = old1->pointer;
				//pとold2の入れ替え
				old1->pointer = p;
				//pの次をold2の次に変更
				old2->pointer = p->pointer;
				//old1->pointer(old2)をpに
				p->pointer = q;
			}
			break;
		}
		old1 = old2;
		old2 = p;
		p = p->pointer;
	}
	p = head->pointer;
	printf("after\n");
	while(p != NULL){
		printf("%15s%15s\n", p->name, p->tel);
		p = p->pointer;
	}
}

Sfield2  *salloc2(){
	return (Sfield2 *)malloc(sizeof(Sfield2));
}

void chain_hash_main(){
	int i, n, hit;
	char key[12];
	Cfield *p;
	char names[4][20] = {
			"ZZAAA",
			"MERRY",
			"ALICE",
			"ILACE",
	};
	char tels[4][20] = {
			"5678-1234",
			"1234-5678",
			"999-9999",
			"0000-0000"
	};
	char keys[4][20] = {
			"xxxx",
			"MERRY"
	};
	printf("list_main\n");
	for(n = 0; n < ChainHashTableSize; n++)
		dat[n] = NULL;

	for(i = 0; i < 4; i++){
		p = ccalloc();
		strcpy(p->name, names[i]);
		strcpy(p->tel, tels[i]);
		n = chain_hash_hash(p->name);
		printf("%15s%15s %d\n", p->name, p->tel, n);
		//先頭に追加
		p->pointer = dat[n];
		dat[n] = p;
	}
	for(i = 0; i < 2; i++){
		strcpy(key, keys[i]);
		n = chain_hash_hash(key);
		p = dat[n];
		hit = FALSE;
		while(p != NULL){
			if(strcmp(key, p->name) == 0){
				printf("%15s%15s hit\n", p->name, p->tel);
				hit = TRUE;
				break;
			}
			p = p->pointer;
		}
		if(hit != TRUE)
			printf("%15s was not found\n", key);
	}
}
int chain_hash_hash(char *s){
	int n;
	n = strlen(s);
	return (s[0] - 'A' + (s[n / 2] - 'A') * 26 + (s[n - 2] - 'A') * 26 * 26) % ChainHashModSize;

}

Cfield  *ccalloc(){
	return (Cfield *)malloc(sizeof(Cfield));
}

void chain_hash2_main(){
	int i, j, n, hit;
	char key[12];
	Cfield2 *p, *q;
	char names[200][20];
	char tels[200][20];
	char random[27];
	char material[] = "abcdef";
//	char material[] = "abcdefghijklmnopqrstuvwxyz";
	char material2[] = "0123456789";
	srand((unsigned)time(NULL));

	for(i = 0; i < 200; i++){
		for(j=0;j<5;j++){
			random[j] = material[rand()%(sizeof(material)-1)];
		}
		random[j] = '\0';
		strcpy(names[i], random);
		for(j=0;j<7;j++){
			random[j] = material2[rand()%(sizeof(material2)-1)];
		}
		random[j] = '\0';
		strcpy(tels[i], random);
	}

	printf("list_main\n");
	for(n = 0; n < ChainHash2TableSize; n++)
		dat[n] = NULL;

	for(i = 0; i < 200; i++){
		p = ccalloc2();
		strcpy(p->name, names[i]);
		strcpy(p->tel, tels[i]);
		n = chain_hash2_hash(p->name);
		printf("%15s%15s %d\n", p->name, p->tel, n);
		if(dat2[n] == NULL){
			dat2[n] = p;
			p->pointer = NULL;
		}else{
			printf("dup\n");
			q = dat2[n];
			while(q->pointer != NULL)
				q = q->pointer;
			q->pointer = p;
			p->pointer = NULL;
		}
		//先頭に追加
	}
	for(i = 0; i < 300; i++){
		for(j=0;j<5;j++){
			random[j] = material[rand()%(sizeof(material)-1)];
		}
		random[j] = '\0';
		strcpy(key, random);
		n = chain_hash2_hash(key);
		p = dat2[n];
		hit = FALSE;
		while(p != NULL){
			if(strcmp(key, p->name) == 0){
				printf("%15s%15s hit\n", p->name, p->tel);
				hit = TRUE;
				break;
			}
			p = p->pointer;
		}
//		if(hit != TRUE)
//			printf("%15s was not found\n", key);
	}
}
int chain_hash2_hash(char *s){
	int n;
	n = strlen(s);
	return (s[0] - 'A' + (s[n / 2] - 'A') * 26 + (s[n - 2] - 'A') * 26 * 26) % ChainHash2ModSize;

}

Cfield2  *ccalloc2(){
	return (Cfield2 *)malloc(sizeof(Cfield2));
}
