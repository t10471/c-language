#include <stdio.h>
#include <string.h>

char *tracks[] = {"I left my heart in Harvard Med School",
                     "Newark, Newark - a wonderful town",
                     "Dancing with a Dork",
                     "From here to maternity",
                     "The girl from Iwo Jima", };
void print_reverse(char* s)
{
    size_t len = strlen(s);
    char* t = s + len - 1;
    
    while(t >= s) {
        printf("%c", *t);
        t = t - 1;
    }
    puts("");
}



int main()
{
    int i;
    for(i = 0; i < 5; i++){
        printf("%s\n",  tracks[i]);
        printf("sizeof %lu strlen %lu\n",  sizeof tracks[i], strlen(tracks[i]));
        print_reverse(tracks[i]);
    }
}

