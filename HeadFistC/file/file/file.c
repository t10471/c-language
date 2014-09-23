#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
   下記コマンドで確認できる
   :QuickRun -args "UFO aliens.csv Elvis elvises.csv the_rest.csv"
*/

int main(int argc, char* args[])
{
    char line[80];
    FILE* in;
    FILE* file1;
    FILE* file2;
    FILE* file3;
    if (argc != 6) {
        fprintf(stderr, "You need to give 5 arguments\n");
        return 1;
    }
    in = fopen("spooky.csv", "r");
    file1 = fopen(args[2], "w");
    file2 = fopen(args[4], "w");
    file3 = fopen(args[5], "w");
    if(in == NULL) {
        fprintf(stderr, "spooky.csvを開けません\n");
        return 1;
    }
    if(file1 == NULL) {
        fprintf(stderr, "%sを開けません\n", args[2]);
        return 1;
    }
    if(file2 == NULL) {
        fprintf(stderr, "%sを開けません\n", args[4]);
        return 1;
    }
    if(file3 == NULL) {
        fprintf(stderr, "%sを開けません\n", args[5]);
        return 1;
    }
    while (fscanf(in, "%79[^\n]\n", line) == 1) {
        if (strstr(line, args[1]))
            fprintf(file1, "%s\n", line);
        else if (strstr(line, args[3]))
            fprintf(file2, "%s\n", line);
        else
            fprintf(file3, "%s\n", line);
    }
    fclose(in);
    fclose(file1);
    fclose(file2);
    fclose(file3);
    return 0;
}
