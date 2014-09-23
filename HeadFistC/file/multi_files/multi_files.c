#include <stdio.h>
#include "encrypt.h"

int main()
{
    char msg[80];
    while (fgets(msg, 79, stdin)) {
        encrypt(msg);
        printf("%s", msg);
    }
    return 0;
}
