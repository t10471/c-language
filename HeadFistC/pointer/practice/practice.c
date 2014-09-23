#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 4;
    int y = 5;
    int *ptr = &x;
    char val[] = "abc";
    char* pptr;
    pptr = val;
    val[1] = val[0];
    ////ポインタがさす配列変数が変更されるとポインタのほうも変更される
    printf("val = %s , str = %s\n", val, pptr);
 
    printf("ptr is x\n");
    printf("address ptr %p\n", ptr);
    printf("value   ptr %i\n", *ptr);
    printf("x       ptr %i\n", x);
    printf("y       ptr %i\n", y);
    *ptr = 99;
    printf("ptr set 99\n");
    printf("address ptr %p\n", ptr);
    printf("value   ptr %i\n", *ptr);
    printf("x       ptr %i\n", x);
    printf("y       ptr %i\n", y);
    ptr = &y;
    printf("ptr is y\n");
    printf("address ptr %p\n", ptr);
    printf("value   ptr %i\n", *ptr);
    printf("x       ptr %i\n", x);
    printf("y       ptr %i\n", y);
}

