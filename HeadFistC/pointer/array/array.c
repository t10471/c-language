#include <stdio.h>
#include <string.h>

char tracks[][80] = {"I left my heart in Harvard Med School",
                     "Newark, Newark - a wonderful town",
                     "Dancing with a Dork",
                     "From here to maternity",
                     "The girl from Iwo Jima", };

void find_track(char search_for[])
{
    int i;
    for (i = 0; i < 5; i++) {
        if (strstr(tracks[i], search_for))
            printf("Track %i: '%s'\n", i, tracks[i]);
    }
}

int main()
{
    char search_for[80];
    int last;
    printf("Search for: ");
    fgets(search_for , 80, stdin);
    //fgetsは改行コード+nullで返すので改行を消して詰めている
    last = strlen(search_for) - 1; 
    printf("%s,  %d, %c, %d, %c end\n", search_for, search_for[last], search_for[last], search_for[last+1], search_for[last+1]);
    search_for[strlen(search_for) - 1] = '\0';
    printf("%s,  %d, %c, %d, %c end\n", search_for, search_for[last], search_for[last], search_for[last+1], search_for[last+1]);
    find_track(search_for);
    return 0;
}

