#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//再帰構造体は匿名にはできない
typedef struct island {
    char* name;
    char* opens;
    char* closes;
    struct island* next;
} island;

island* create(char* name)
{
    island* i = (island*)malloc(sizeof(island));
    i->name = strdup(name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

void display(island* start)
{
    island* i = start;
    for (; i != NULL; i = i->next) {
        printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
    }
}

void release(island* start)
{
    island* i = start;
    island* next = NULL;
    for (; i != NULL; i = next) {
        next = i->next;
        //先にnameを消す
        free(i->name);
        free(i);
    }
}

int main(int argc, char* args[])
{
    int is_interlocution = 0;
    char ch;
    while ((ch = getopt(argc, args, "i")) != EOF) {
        switch (ch) {
            case 'i':
                is_interlocution = 1;
                break;
            default:
                fprintf(stderr, "Unknown option: '%s'\n", optarg);
                return 1;
        }
    }
    argc -= optind;
    args += optind;

    island* start = NULL;
    island* i = NULL;
    island* next = NULL;
    char name[80];
    if (is_interlocution)
        fprintf(stdout,
                "島の名前を入力してください。終了する場合ははendと入力してくだ"
                "さい\n");
    for (; fgets(name, 80, stdin) != NULL; i = next) {
        name[strlen(name) - 1] = '\0';
        if (is_interlocution && strcmp(name, "end") == 0) break;
        name[strlen(name) - 1] = '\n';
        next = create(name);
        if (start == NULL) start = next;
        if (i != NULL) i->next = next;
    }
    if (start != NULL) {
        display(start);
        release(start);
    }
    return 0;
}
