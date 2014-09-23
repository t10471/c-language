#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_scores(const void* score_a, const void* score_b)
{
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return a - b;
}

int compare_scores_desc(const void* score_a, const void* score_b)
{
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return b - a;
}

typedef struct {
    int width;
    int height;
} rectangle;

int compare_areas(const void* a, const void* b)
{
    rectangle* ra = (rectangle*)a;
    rectangle* rb = (rectangle*)b;
    int area_a = (ra->width * ra->height);
    int area_b = (rb->width * rb->height);
    return area_a - area_b;
}

int compare_names(const void* a, const void* b)
{
    //配列のスライスとして2次元配列で渡される
    char** sa = (char**)a;
    char** sb = (char**)b;
    printf("%s %p %p %s %s\n", *sa, *sa, sa, sa[0], sa[1]);
    printf("%s %p %p %s %s\n", *sb, *sb, sb, sb[0], sb[1]);
    return strcmp(*sa, *sb);
}

int compare_areas_desc(const void* a, const void* b)
{
    return compare_areas(b, a);
}
int compare_names_desc(const void* a, const void* b)
{
    return compare_names(b, a);
}

int main()
{
    int scores[] = {543, 323, 32, 554, 11, 3, 112};
    int i;
    qsort(scores, 7, sizeof(int), compare_scores_desc);
    puts("These are the scores in order:");
    for (i = 0; i < 7; i++) {
        printf("Score = %i\n", scores[i]);
    }
    puts("");
    char* names[] = {"Karen", "Mark", "Brett", "Molly"};
    printf("names ptr %p\n", names);

    qsort(names, 4, sizeof(char*), compare_names);
    puts("");
    puts("These are the names in order:");
    for (i = 0; i < 4; i++) {
        printf("%s %p\n", names[i], names[i]);
    }

    rectangle rs[] = {{4, 2}, {1, 2}, {2, 3}, {2, 2}};
    qsort(rs, 4, sizeof(rectangle), compare_areas);
    puts("These are the rectangle in order:");
    for (i = 0; i < 4; i++) {
        printf("%d %d\n", rs[i].width, rs[i].height);
        // printf("%d %d\n", (&rs[i])->width, (&rs[i])->height);
    }


    return 0;
}
