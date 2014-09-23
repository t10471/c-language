#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -gをつけてコンパイルする必要がある
 * メモリーリークを確認する方法
 * valgrind --leak-check=full ./tree
 */
typedef struct node {
    char* question;
    struct node* no;
    struct node* yes;
} node;

int yes_no(char* question)
{
    char answer[3];
    printf("%s? (y/n): ", question);
    fgets(answer, 3, stdin);
    return answer[0] == 'y';
}

node* create(char* question)
{
    node* n = (node*)malloc(sizeof(node));
    n->question = strdup(question);
    n->no = NULL;
    n->yes = NULL;
    return n;
}

void release(node* n)
{
    if (n) {
        if (n->no) release(n->no);
        if (n->yes) release(n->yes);
        if (n->question) free(n->question);
        free(n);
    }
}
int main()
{
    char question[80];
    char suspect[20];
    node* start_node = create("容疑者はひげを生やしていましたか？");
    start_node->no = create("Loretta Barnsworth");
    start_node->yes = create("Vinny the Spoon");

    node* current;
    do {
        current = start_node;
        while (1) {
            if (yes_no(current->question)) {
                if (current->yes) {
                    current = current->yes;
                } else {
                    printf("SUSPECT IDENTIFIED\n");
                    break;
                }
            } else if (current->no) {
                current = current->no;
            } else {
                /*  yesノードに新たな容疑者の名前を入力する */
                printf("容疑者はだれですか？ ");
                fgets(suspect, 20, stdin);
                node* yes_node = create(suspect);
                current->yes = yes_node;

                /*  noノードに質問(容疑者の名前を入力する */
                node* no_node = create(current->question);
                current->no = no_node;

                /*  質問ノードに新たに質問を追加する */
                printf(
                    "%sに当てはまり、%sに当てはまらない質問は？ ",
                    suspect, current->question);
                fgets(question, 80, stdin);
                free(current->question);
                current->question = strdup(question);

                break;
            }
        }
    } while (yes_no("Run again"));
    release(start_node);
    return 0;
}
