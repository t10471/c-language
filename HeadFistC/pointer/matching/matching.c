#include <stdio.h>
int main()
{
    int contestants[] = {3, 4, 5};
    int* choice = contestants;
    //配列とポインタは一緒
    char text[] = "yes we can!";
    char* ptr = text;
    int x = 4;
    int* int_ptr = &x;

    printf("ただの確認\n");
    printf("int_ptr  = %p\n", int_ptr);
    printf("*int_ptr = %i\n", *int_ptr);
    printf("x        = %i\n", x);
    printf("ptr[0]   = %c\n", ptr[0]);
    
    printf("全て一緒\n");
    printf("*contestants    = %i\n", *contestants);
    printf("contestants[0]  = %i\n", contestants[0]);
    printf("*choice         = %i\n", *choice);
    
    printf("ポインタが一緒\n");
    printf("contestants     = %p\n", contestants);
    printf("&contestants[0] = %p\n", &contestants[0]);
    printf("choice          = %p\n", choice);
    
    printf("sizeofの結果が違う!\n"); //配列変数をポインタに入れると情報が減る
    printf("sizeof contestants     = %lu\n", sizeof contestants);
    printf("sizeof choice          = %lu\n", sizeof choice);
    
    printf("charの場合\n");
    printf("ptr      = %p\n", ptr);
    printf("text     = %p\n", text);
    printf("&ptr[0]  = %p\n", &ptr[0]);   
    printf("&text[0] = %p\n", &text[0]);   

    printf("*ptr     = %c\n", *ptr);
    printf("*text    = %c\n", *text);
    printf("ptr[0]   = %c\n", ptr[0]);   
    printf("text[0]  = %c\n", text[0]);   

    printf("ptr      = %s\n", ptr);
    printf("text     = %s\n", text);
    
    printf("配列自体のポインタ\n");
    printf("ptr      = %p\n", ptr); //char *
    printf("text     = %p\n", text); //char *
    //これだけ結果違う
    printf("&ptr     = %p\n", &ptr); //char **
    printf("&text    = %p\n", &text); //char (*)[12]
    //配列変数はポインタとちょっと違う
    printf("text == &text = %d\n", text == &text);
    printf("ptr  == &ptr  = %d\n", ptr == &ptr);

    printf("intとcharでポインタのサイズが異なる\n");
    printf("sizeof ptr[0]   = %lu\n", sizeof ptr[0]);
    printf("sizeof chice[0] = %lu\n", sizeof choice[0]);
    printf("ポインタ演算\n");
    printf("ptr      = %s\n", ptr);
    printf("ptr + 4  = %s\n", ptr + 4);
    
    printf("*choice         = %i\n", *choice);
    printf("*(choice + 1)   = %i\n", *(choice + 1));
    printf("*(choice + 2)   = %i\n", *(choice + 2));
    printf("*(2 + choice)   = %i\n", *(2 + choice));
    printf("2[chice]        = %i\n", 2[choice]);
    
    contestants[0] = 2;
    contestants[1] = contestants[2];
    contestants[2] = *choice;
    printf("I’m going to pick contestant number %i\n", contestants[2]);
    return 0;
}
