/*
 ============================================================================
 Name        : algorithm_7_graph.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <locale.h>
// #include <tchar.h>
#include <math.h>
#include <stdlib.h> /* randとsrandを使うため */
#include <time.h>  /* timeを使うため */
#include <sys/types.h>
#include <sys/stat.h>

#define SG1N 8
#define SG2N 8
#define SG3N 8
#define SG4N 8
#define SG5N 8
#define SG6N 8
#define TS1N 8
#define TS2N 8
#define E1Node 4
#define E1Root 6
#define E1Start 1
#define E2Node 4
#define E2Root 6
#define E2Start 1

//search graph
void search_graph1();
void search_graph2();
void search_graph3();
void search_graph4();
void search_graph5();
//topological sort
void topological_sort1();
void topological_sort2();

void euler1();
void euler2();

int sg1_a[SG1N + 1][SG1N + 1] = {
		{0,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,0,0},
		{0,1,0,1,1,0,0,0,0},
		{0,0,1,0,0,0,0,1,0},
		{0,0,1,0,0,1,0,0,0},
		{0,0,0,0,1,0,1,0,0},
		{0,0,0,0,0,1,0,1,1},
		{0,0,0,1,0,0,1,0,1},
		{0,0,0,0,0,0,1,1,0},
};
int sg2_a[SG2N + 1][SG2N + 1] = {
		{0,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,0,0},
		{0,1,0,1,1,0,0,0,0},
		{0,0,1,0,0,0,0,1,0},
		{0,0,1,0,0,1,0,0,0},
		{0,0,0,0,1,0,1,0,0},
		{0,0,0,0,0,1,0,1,1},
		{0,0,0,1,0,0,1,0,1},
		{0,0,0,0,0,0,1,1,0},
};
int sg3_a[SG3N + 1][SG3N + 1] = {
		{0,0,0,0,0,0,0,0,0},
		{0,0,1,1,0,0,0,0,0},
		{0,1,0,1,1,0,0,0,0},
		{0,1,1,0,0,1,0,0,0},
		{0,0,1,0,0,1,0,0,0},
		{0,0,0,1,1,0,0,0,0},
		{0,0,0,0,0,1,0,1,1},
		{0,0,0,0,0,0,1,0,1},
		{0,0,0,0,0,0,1,1,0},
};
int sg4_a[SG4N + 1][SG4N + 1] = {
		{0,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,0,0},
		{0,1,0,1,1,1,0,0,0},
		{0,0,1,0,0,0,0,1,0},
		{0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,1,0,1,1},
		{0,0,0,1,0,0,1,0,1},
		{0,0,0,0,0,0,1,1,0},
};
int sg5_a[SG5N + 1][SG5N + 1] = {
		{0,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,0,0},
		{0,1,0,1,1,1,0,0,0},
		{0,0,1,0,0,0,0,1,0},
		{0,0,1,0,0,0,0,0,0},
		{0,0,1,0,0,0,1,0,0},
		{0,0,0,0,0,1,0,1,1},
		{0,0,0,1,0,0,1,0,1},
		{0,0,0,0,0,0,1,1,0},
};
int ts1_a[TS1N + 1][TS1N + 1] = {
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,1,0,0,0,0,0},
		{0,1,0,0,0,1,0,0,0},
		{0,0,0,0,1,0,0,1,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,1,0,0},
		{0,0,0,0,0,0,0,1,1},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,0},
};

int ts2_a[TS2N + 1][TS2N + 1] = {
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,1,0,0,0,0,0},
		{0,1,0,0,0,1,0,0,0},
		{0,0,0,0,1,0,0,1,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,1,0,0},
		{0,0,0,0,0,0,0,1,1},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,0},
};

int e1_a[E1Node+1][E1Node+1] = {
		{0,0,0,0,0},
		{0,0,1,0,1},
		{0,1,0,1,2},
		{0,0,1,0,1},
		{0,1,2,1,0},
};

int e2_a[E2Node+1][E2Node+1] = {
		{0,0,0,0,0},
		{0,0,1,0,0},
		{0,0,0,1,1},
		{0,0,0,0,1},
		{0,1,1,0,0},
};

int sg1_v[SG1N +1];
int sg1_depth = 0;
int sg2_v[SG2N +1];
int sg3_v[SG3N +1];
int sg4_v[SG4N +1];
int sg4_queuue[100];
int sg4_head = 0;
int sg4_tail = 0;
int sg5_v[SG5N +1];
int sg5_queuue[100];
int sg5_head = 0;
int sg5_tail = 0;

int ts1_v[TS1N];
int ts1_depth = 0;
int ts1_ret[TS1N];
int ts1_i = 0;
int ts2_v[TS2N];
int ts2_s[TS2N];
int ts2_depth = 0;
int ts2_ret[TS2N];
int ts2_i = 0;

int e1_success;
int e1_v[E1Root+1];
int e1_n;

int e2_success;
int e2_v[E2Root+1];
int e2_n;

void visit(int);
void visit2(int);
void visit3(int);
void visit4(int);
void visit5(int);
void visit6(int);
void visit7(int);
void print_sp(int, int);

int main(void) {
	search_graph1();
	search_graph2();
	search_graph3();
	search_graph4();
	search_graph5();
	topological_sort1();
	topological_sort2();
	euler1();
	euler2();
	return EXIT_SUCCESS;
}

/**
 * グラフ探索 深さ優先
 */
void search_graph1(){
	int i;
	printf("search_graph1\n");
	for(i = 1; i < SG1N; i++)
		sg1_v[i] = 0;
	visit(1);
	printf("\n");
}
void visit(int i){
	int j;
	sg1_depth++;
	sg1_v[i] = 1;
	print_sp(0, sg1_depth - 1);
	printf("i=%d ", i);
	print_sp(0, 8 - sg1_depth);
	printf(" [");
	for(j = 1; j <= SG1N; j++){
		printf("%d,", sg1_a[i][j]);
		if(sg1_a[i][j] == 1 && sg1_v[j] == 0){
			print_sp(j, SG1N + 1);
			printf("%d->%d\n", i, j);
			visit(j);
			print_sp(0, sg1_depth - 1);
			printf("i=%d ", i);
			print_sp(0, j + 8 - sg1_depth + 1);
		}
	}
	sg1_depth--;
	printf("]\n");
}


/**
 * グラフ探索 深さ優先
 * 全地点スタート
 */
void search_graph2(){
	int i, k;
	printf("search_graph2\n");
	for(k = 1; k <= SG2N; k++){
		for(i = 1; i <= SG2N; i++)
			sg2_v[i] = 0;
		visit2(k);
		printf("\n");
	}
}
void visit2(int i){
	int j;
	sg2_v[i] = 1;
	for(j = 1; j <= SG2N; j++){
		if(sg2_a[i][j] == 1 && sg2_v[j] == 0){
			printf("%d->%d ", i, j);
			visit2(j);
		}
	}
}

/**
 *  不連結ノードの探索
 */
void search_graph3(){
	printf("search_graph3\n");
	int i, count = 1;
	for(i = 1; i <= SG3N; i++)
		sg3_v[i] = 0;
	for(i = 1; i <= SG3N; i++){
		if(sg3_v[i] != 1){
			printf("%d :", count++);
			visit3(i);
			printf("\n");
		}
	}
}
void visit3(int i){
	int j;
	printf("%d ", i);
	sg3_v[i] = 1;
	for(j = 1; j <= SG3N; j++){
		if(sg3_a[i][j] == 1 && sg3_v[j] == 0){
			visit3(j);
		}
	}
}

/**
 * グラフ探索 幅優先
 */
void search_graph4(){
	int i, j;
	printf("search_graph4\n");
	for(i=1;i<=SG4N;i++)
		sg4_v[i] = 0;
	sg4_queuue[sg4_tail++] = 1;sg4_v[1] = 1;
	do{
		i = sg4_queuue[sg4_head++];
		printf("head=%d tail=%d\n",sg4_head, sg4_tail);
		for(j=1;j<=SG4N;j++){
			if(sg4_a[i][j] == 1 && sg4_v[j] == 0){
				printf("%d->%d\n", i, j);
				sg4_queuue[sg4_tail++] = j;
				sg4_v[j] = 1;
			}
		}
	}while(sg4_head != sg4_tail);
	printf("\n");
}

/**
 * グラフ探索 幅優先
 * 全地点スタート
 */
void search_graph5(){
	int i, j, p;
	printf("search_graph5\n");

	for(p=1;p<=SG5N;p++){
		for(i=1;i<=SG5N;i++)
			sg5_v[i] = 0;
		sg5_head = sg5_tail = 0;
		sg5_queuue[sg5_tail++] = p;sg5_v[p] = 1;
		do{
			i = sg5_queuue[sg5_head++];
//			printf("head=%d tail=%d\n",sg5_head, sg5_tail);
			for(j=1;j<=SG5N;j++){
				if(sg5_a[i][j] == 1 && sg5_v[j] == 0){
//					printf("%d->%d\n", i, j);
					printf("%d->%d ", i, j);
					sg5_queuue[sg5_tail++] = j;
					sg5_v[j] = 1;
				}
			}
		}while(sg5_head != sg5_tail);
		printf("\n");
	}
}

void topological_sort1(){
	int i;
	printf("topological_sort1\n");
	for(i=1;i<TS1N;i++)
		ts1_v[i] = 0;
	for(i=1;i<TS1N;i++)
		if(ts1_v[i] == 0)
			visit4(i);
	for(i=0;i<TS1N - 1;i++)
		printf("%d ", ts1_ret[i]);
	printf("\n");
}

void visit4(int i){
	int j;
	printf("in  ");
	print_sp(0, ts1_depth);
	printf("%d\n", i);
	ts1_depth++;
	ts1_v[i] = 1;
	for(j=1;j<TS1N;j++){
		if(ts1_a[i][j] == 1 && ts1_v[j] == 0)
			visit4(j);
	}

	ts1_ret[ts1_i++] = i;
	ts1_depth--;
	printf("out ");
	print_sp(0, ts1_depth);
	printf("%d\n", i);
}


void topological_sort2(){
	int i;
	printf("topological_sort2\n");
	for(i=1;i<TS2N;i++)
		ts2_v[i] = 0;
	for(i=1;i<TS2N;i++)
		if(ts2_v[i] == 0)
			visit5(i);
	for(i=TS2N;i>=1;i--)
		printf("%d ", ts2_s[i]);
	printf("\n");
}

void visit5(int i){
	int j;
	static int sp = 1;
	printf("in  ");
	print_sp(0, ts2_depth);
	printf("%d\n", i);
	ts2_depth++;
	ts2_v[i] = 1;
	for(j=1;j<=TS2N;j++){
		if(ts2_a[i][j] == 1 && ts2_v[j] == 0){
			visit5(j);
		}
		if(ts2_a[i][j] == 1 && ts2_v[j] == 1){
			printf("%d と %d の付近にループがあります\n", i ,j);
			exit(1);
		}
	}
	ts2_depth--;
	printf("out ");
	print_sp(0, ts2_depth);
	printf("%d\n", i);
	ts2_v[i] = 2;
	ts2_s[sp++] = i;
}

/**
 * 深さ優先の一筆書き
 */
void euler1(){
	e1_success = 0; e1_n = E1Root;
	printf("euler1\n");
	visit6(E1Start);
	if(e1_success == 0)
		printf("解なし\n");
}

void visit6(int i){
	int j;
	e1_v[e1_n] = i;
	//e1_nはと追った点の残り
	if(e1_n == 0 && i == E1Start){
		printf("解 %d: ", ++e1_success);
		for(i=0;i<= E1Root;i++){
			printf("%d", e1_v[i]);
		}
		printf("\n");
	}else{
		for(j=1;j<=E1Node;j++){
			if(e1_a[i][j] != 0){
				e1_a[i][j]--;e1_a[j][i]--;
				e1_n--;
				visit6(j);
				//戻るので値を戻す
				e1_a[i][j]++;e1_a[j][i]++;
				e1_n++;
			}
		}
	}
}

/**
 * 深さ優先の一筆書き 有向グラフ版
 */
void euler2(){
	e2_success = 0; e2_n = E2Root;
	printf("euler2\n");
	visit7(E2Start);
	if(e2_success == 0)
		printf("解なし\n");
}

void visit7(int i){
	int j;
	e2_v[e2_n] = i;
	//e1_nはと追った点の残り
	if(e2_n == 0 && i == E2Start){
		printf("解 %d: ", ++e2_success);
		for(i=0;i<= E2Root;i++){
			printf("%d", e2_v[i]);
		}
		printf("\n");
	}else{
		for(j=1;j<=E2Node;j++){
			if(e2_a[i][j] != 0){
				e2_a[i][j]--;
				e2_n--;
				visit7(j);
				//戻るので値を戻す
				e2_a[i][j]++;
				e2_n++;
			}
		}
	}
}

void print_sp(int s, int e){
	int x;
	for(x = s; x < e; x++){
		printf("  ");
	}
}

